#include"CalendarWidget.h"

SqliteOperator* oper=new SqliteOperator;

CalendarWidget::CalendarWidget(QWidget *parent): QCalendarWidget(parent)
{
    connect(this, &QCalendarWidget::currentPageChanged, this, &CalendarWidget::onPageChanged);//换页动作关联
    oper=new SqliteOperator;
    //下面使用selectedDate()方法获取当前选中的日期，并使用daysInMonth()方法获取当前月份的天数。接下来，使用一个循环遍历这些日期，并使用qDebug()输出日期信息。
    QDate currentDate = selectedDate();
    int daysInMonth = currentDate.daysInMonth();

    QDate previousMonthDate = currentDate.addMonths(-1);  // 获取上个月的日期
    QDate nextMonthDate = currentDate.addMonths(1);//获取下个月日期
    int previousnumDays = previousMonthDate.daysInMonth();
    int nextnumDays = nextMonthDate.daysInMonth();
    change_color(previousMonthDate,previousnumDays);
    change_color(currentDate,daysInMonth);
    change_color(nextMonthDate,nextnumDays);

    //设置星期中每天（包括表头）的风格
    setHorizontalHeaderFormat(QCalendarWidget::LongDayNames);//保留星期几的行表头
    QTextCharFormat format;
    format.setForeground(QColor(51, 51, 51));//前景色
    format.setBackground(QColor(247,247,247));//背景色
    format.setFontFamily("Times New Roman");//字体
    format.setFontPointSize(9);//字号
    format.setFontWeight(QFont::Medium);//字体粗细
    //setWeekdayTextFormat(Qt::Saturday, format);
    //setWeekdayTextFormat(Qt::Sunday,   format);

    //修改按钮图片
    QToolButton *prevBtn = findChild<QToolButton*>(QLatin1String("qt_calendar_prevmonth"));
    QToolButton *nextBtn = findChild<QToolButton*>(QLatin1String("qt_calendar_nextmonth"));
    QString currentDir = QDir::currentPath();  // 获取当前工作目录路径
    //qDebug() << "Current Directory: " << currentDir;
    QString iconPath1 = currentDir + "/上月.png";  // 图标文件的相对路径
    prevBtn->setIcon(QIcon(iconPath1));  // 设置按钮的图标
    QString iconPath2 = currentDir + "/下月.png";  // 图标文件的相对路径
    nextBtn->setIcon(QIcon(iconPath2));  // 设置按钮的图标
    //要把按钮图片放置在"HCIProject/build-Easygtd-Desktop_Qt_5_15_2_MinGW_64_bit-Debug"目录下
}
void CalendarWidget::change_color(QDate currentDate,int daysInMonth)//输入参数为当前日期（主要是月份），每月的天数。修改整个月的底色。
{
    for (int day = 1; day <= daysInMonth; ++day)
    {
        QDate date(currentDate.year(), currentDate.month(), day);
        //下面是修改指定日期方格背景色部分的代码
        QTextCharFormat format;// 设置背景色为指定颜色，根据某天任务数量的多少确定
        int lightness=0;//设定颜色的亮度数值
        int taskcount=oper->GetDeadline(date.toString(Qt::ISODate));//存储ddl数量
        if(taskcount>=MAX_DDL)
        {
            taskcount=MAX_DDL;
        }
        lightness=L_MAX+K*taskcount;
        QColor newcolor = QColor::fromHsl(H_GREEN, S_GREEN, lightness);
        format.setBackground(newcolor);// 应用字符格式到指定的日期
        setDateTextFormat(date, format);//修改背景色完毕
        //变色结束
        //qDebug() << date.toString(Qt::ISODate);//将日期转换为string并输出,曾经用于测试

        //注意：检测到用户切换月份时，有专门的函数处理更新，但是那个函数在用户首次打开一个月份时不工作，所以上面构造函数的部分（对日期首次处理）也是需要的
        //GetDeadline(QString date);这个函数可以查询某一日期的截止任务数量，输入参数应该是"xxxx-xx-xx"

        //假设一天最多有30个任务（30以上均为同一种颜色），不同深浅颜色间相差K个B值
        //使用HSB调整，主要修改B属性，255是白，0是黑。大致调整的范围是45~255，共210.底色用绿色。
        //任务数量0对应255,30对应75.y=K*x+255.
        //QColor newcolor = QColor::fromHsl(hue, saturation, lightness);
        //setDateTextFormat(QDate(2023,05,22), format),输入参数是QDate
    }
}
void CalendarWidget::onPageChanged(int year, int month)//这是检测用户日历换页后重新修改颜色
{
    QDate currentDate(year, month, 1);
    int daysInMonth = currentDate.daysInMonth();

    QDate previousMonthDate = currentDate.addMonths(-1);  // 获取上个月的日期
    QDate nextMonthDate = currentDate.addMonths(1);//获取下个月日期
    int previousnumDays = previousMonthDate.daysInMonth();
    int nextnumDays = nextMonthDate.daysInMonth();
    change_color(previousMonthDate,previousnumDays);
    change_color(currentDate,daysInMonth);
    change_color(nextMonthDate,nextnumDays);
}
void CalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{

    if (date == selectedDate())
    {
        painter->save();

        //下面重新绘制选中日期的格子底色和文本
        int taskcount=oper->GetDeadline(date.toString(Qt::ISODate));//存储ddl数量
        if(taskcount>=MAX_DDL)
        {
            taskcount=MAX_DDL;
        }
        int lightness=L_MAX+K*taskcount;
        QColor newcolor = QColor::fromHsl(H_GREEN, S_GREEN, lightness);
        // 绘制选中日期的背景色
        painter->fillRect(rect, newcolor);

        // 绘制选中日期的文本颜色
        painter->setPen(Qt::black);
        painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
        //底色和文本设置完毕，下面设置圆圈边框和三角形角标

        painter->setRenderHint(QPainter::Antialiasing, true);

        // 设置圆圈边框的颜色和宽度
        QColor borderColor = Qt::blue;
        int borderWidth = 2;

        // 计算圆圈的位置和大小
        int circleSize = qMin(rect.width(), rect.height()) - borderWidth * 2;
        int x = rect.x() + rect.width() / 2 - circleSize / 2;
        int y = rect.y() + rect.height() / 2 - circleSize / 2;
        QRect circleRect(x, y, circleSize, circleSize);

        // 绘制圆圈边框
        painter->setPen(QPen(borderColor, borderWidth));
        painter->setBrush(Qt::NoBrush);
        painter->drawEllipse(circleRect);

        painter->restore();
    }
    else
    {
        QCalendarWidget::paintCell(painter, rect, date);
    }
    if (date == QDate::currentDate()) {
        // 最后在左上角绘制金黄色三角形
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor::fromHsl(H_triangle, S_triangle, L_triangle));
        QPoint points[3];
        points[0] = rect.topLeft();
        points[1] = rect.topLeft()+alpha_triangle*(rect.topRight()-rect.topLeft());
        points[2] = rect.topLeft()+alpha_triangle*(rect.bottomLeft()-rect.topLeft());
        painter->drawPolygon(points, 3);
        painter->restore();
    }
}

