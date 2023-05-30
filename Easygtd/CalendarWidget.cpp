#include"CalendarWidget.h"
#include <QPushButton>
#include <QLabel>
#include<QEvent>
#include<QHBoxLayout>
#include <QProxyStyle>

class QCustomStyle : public QProxyStyle
{
public:
    QCustomStyle(QWidget *parent){
        setParent(parent);
    };

private:
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget) const
    {
        if (element == PE_FrameFocusRect)
        {
            return;
        }
        QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
};

SqliteOperator* oper=new SqliteOperator;

CalendarWidget::CalendarWidget(QWidget *parent): QCalendarWidget(parent)
{
    connect(this, &QCalendarWidget::currentPageChanged, this, &CalendarWidget::onPageChanged);//换页动作关联
    oper=new SqliteOperator;
    //下面使用selectedDate()方法获取当前选中的日期，并使用daysInMonth()方法获取当前月份的天数。
    QDate currentDate = selectedDate();
    int daysInMonth = currentDate.daysInMonth();

    QDate previousMonthDate = currentDate.addMonths(-1);  // 获取上个月的日期
    QDate nextMonthDate = currentDate.addMonths(1);//获取下个月日期
    int previousnumDays = previousMonthDate.daysInMonth();
    int nextnumDays = nextMonthDate.daysInMonth();
    change_color(previousMonthDate,previousnumDays);
    change_color(currentDate,daysInMonth);
    change_color(nextMonthDate,nextnumDays);

    initControl();
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
        // 最后在今日的左上角绘制金黄色三角形
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

void CalendarWidget::initControl()
{
    //layout()->setSizeConstraint(QLayout::SetFixedSize); //设置固定大小，效果不好
    setLocale(QLocale(QLocale::Chinese));
    setNavigationBarVisible(false);
    setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);//星期几的表头为单个文字
    setStyle(new QCustomStyle(this));


    //设置星期中每天（包括表头）的风格
    //下面可以更改字体等
    QTextCharFormat format;
    format.setForeground(QColor(160, 160, 160));//前景色
    format.setBackground(QColor(255, 255, 255));//背景色
    //format.setFontFamily("Times New Roman");//字体
    //format.setFontPointSize(9);//字号
    //format.setFontWeight(QFont::Medium);//字体粗细
    setHeaderTextFormat(format);
    //    setWeekdayTextFormat(Qt::Saturday, format);
    //    setWeekdayTextFormat(Qt::Sunday,   format);
    //    setWeekdayTextFormat(Qt::Monday,   format);
    //    setWeekdayTextFormat(Qt::Tuesday,  format);
    //    setWeekdayTextFormat(Qt::Wednesday,format);
    //    setWeekdayTextFormat(Qt::Thursday, format);
    //    setWeekdayTextFormat(Qt::Friday,   format);

    initTopWidget();
    initBottomWidget();
    connect(this, &QCalendarWidget::currentPageChanged, [this](int year, int month){
        setDataLabelTimeText(year, month);
    });
}
void CalendarWidget::initTopWidget()
{
    QWidget* topWidget = new QWidget(this);
    topWidget->setObjectName("CalendarTopWidget");
    topWidget->setFixedHeight(topWidget_height);
    topWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

//    下面曾经用于颜色修改测试
//    bottomWidget->setStyleSheet("background-color: red;");
//    QLinearGradient gradient(0, 0, 0, topWidget->height());
//    gradient.setColorAt(0, Qt::blue);
//    gradient.setColorAt(1, Qt::green);
//    QBrush brush(gradient);
//    QPalette palette;
//    palette.setBrush(QPalette::Window, brush);
//    topWidget->setAutoFillBackground(true);
//    topWidget->setPalette(palette);
//    颜色修改完毕

    QHBoxLayout* hboxLayout = new QHBoxLayout;
    hboxLayout->setContentsMargins(12, 0, 12, 0);
    hboxLayout->setSpacing(4);

    m_leftYearBtn   = new QPushButton(this);
    m_leftMonthBtn  = new QPushButton(this);
    m_rightYearBtn  = new QPushButton(this);
    m_rightMonthBtn = new QPushButton(this);
    m_dataLabel     = new QLabel(this);

    //设置每个按钮的名称
    m_leftYearBtn->setObjectName("CalendarLeftYearBtn");
    m_leftMonthBtn->setObjectName("CalendarLeftMonthBtn");
    m_rightYearBtn->setObjectName("CalendarRightYearBtn");
    m_rightMonthBtn->setObjectName("CalendarRightMonthBtn");
    m_dataLabel->setObjectName("CalendarDataLabel");

    //设置每个按钮的大小
    m_leftYearBtn->setFixedSize(BtnSize, BtnSize);
    m_leftMonthBtn->setFixedSize(BtnSize, BtnSize);
    m_rightYearBtn->setFixedSize(BtnSize, BtnSize);
    m_rightMonthBtn->setFixedSize(BtnSize, BtnSize);

    hboxLayout->addWidget(m_leftYearBtn);
    hboxLayout->addWidget(m_leftMonthBtn);
    hboxLayout->addStretch();
    hboxLayout->addWidget(m_dataLabel);
    hboxLayout->addStretch();
    hboxLayout->addWidget(m_rightMonthBtn);
    hboxLayout->addWidget(m_rightYearBtn);
    topWidget->setLayout(hboxLayout);

    //设置每个按钮的图标
    m_leftYearBtn->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    m_leftMonthBtn->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    m_rightYearBtn->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    m_rightMonthBtn->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));

    //初始化每个按钮的背景色为透明
    m_leftYearBtn->setStyleSheet("background-color: transparent;");
    m_leftMonthBtn->setStyleSheet("background-color: transparent;");
    m_rightYearBtn->setStyleSheet("background-color: transparent;");
    m_rightMonthBtn->setStyleSheet("background-color: transparent;");

    //在每个按钮上都安装事件过滤器
    m_leftYearBtn->installEventFilter(this);
    m_leftMonthBtn->installEventFilter(this);
    m_rightYearBtn->installEventFilter(this);
    m_rightMonthBtn->installEventFilter(this);

    QVBoxLayout *vBodyLayout = qobject_cast<QVBoxLayout *>(layout());
    vBodyLayout->insertWidget(0, topWidget);

    connect(m_leftYearBtn,   SIGNAL(clicked()),  this, SLOT(onbtnClicked()));
    connect(m_leftMonthBtn,  SIGNAL(clicked()),  this, SLOT(onbtnClicked()));
    connect(m_rightYearBtn,  SIGNAL(clicked()),  this, SLOT(onbtnClicked()));
    connect(m_rightMonthBtn, SIGNAL(clicked()),  this, SLOT(onbtnClicked()));

    setDataLabelTimeText(selectedDate().year(), selectedDate().month());
}
void CalendarWidget::initBottomWidget()
{
    QWidget* bottomWidget = new QWidget(this);
    bottomWidget->setObjectName("CalendarBottomWidget");
    bottomWidget->setFixedHeight(bottomWidget_height);
    bottomWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

//    下面曾经用于颜色修改测试
//    bottomWidget->setStyleSheet("background-color: red;");
//    QLinearGradient gradient(0, 0, 0, bottomWidget->height());
//    gradient.setColorAt(0, Qt::blue);
//    gradient.setColorAt(1, Qt::green);
//    QBrush brush(gradient);
//    QPalette palette;
//    palette.setBrush(QPalette::Window, brush);
//    bottomWidget->setAutoFillBackground(true);
//    bottomWidget->setPalette(palette);
//    颜色修改完毕

    QHBoxLayout* hboxLayout = new QHBoxLayout;
    hboxLayout->setContentsMargins(12, 0, 12, 0);
    hboxLayout->setSpacing(6);

    m_toDayBtn = new QPushButton(this);
    m_toDayBtn->setObjectName("CalendarTodayBtn");
    m_toDayBtn->setFixedSize(3*toDayBtn_length, toDayBtn_length);
    m_toDayBtn->setText(QStringLiteral("回到今日页面"));

    hboxLayout->addStretch();
    hboxLayout->addWidget(m_toDayBtn);
    bottomWidget->setLayout(hboxLayout);

    QVBoxLayout *vBodyLayout = qobject_cast<QVBoxLayout *>(layout());
    vBodyLayout->addWidget(bottomWidget);

    connect(m_toDayBtn, &QPushButton::clicked, [this](){

        showToday();
    });
}
void CalendarWidget::setDataLabelTimeText(int year, int month)
{
    QFont font = m_dataLabel->font();
    font.setPointSize(15);  // 设置字号
    font.setFamily("Arial");  // 设置字体名称为 Arial
    font.setBold(true);      // 设置加粗
    font.setItalic(false);   // 取消斜体
    m_dataLabel->setFont(font);
    m_dataLabel->setText(QStringLiteral("%1年%2月").arg(year).arg(month));
}
void CalendarWidget::onbtnClicked()
{
    //disconnect(SIGNAL(selectionChanged()));
    QPushButton *senderBtn = qobject_cast<QPushButton *>(sender());
    if (senderBtn == m_leftYearBtn)
    {
        showPreviousYear();
    }
    else if (senderBtn == m_leftMonthBtn)
    {
        showPreviousMonth();
    }
    else if (senderBtn == m_rightYearBtn)
    {
        showNextYear();
    }
    else if (senderBtn == m_rightMonthBtn)
    {
        showNextMonth();
    }
}
bool CalendarWidget::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == m_leftYearBtn)
    {
        if (event->type() == QEvent::Enter)
        {
            m_leftYearBtn->setStyleSheet("border: 1px solid black;");
        }
        else if (event->type() == QEvent::Leave)
        {
            m_leftYearBtn->setStyleSheet("background-color: transparent;"); // 清空样式表，恢复默认外观
        }
    }
    else if (obj == m_leftMonthBtn)
    {
        if (event->type() == QEvent::Enter)
        {
            m_leftMonthBtn->setStyleSheet("border: 1px solid black;");
        }
        else if (event->type() == QEvent::Leave)
        {
            m_leftMonthBtn->setStyleSheet("background-color: transparent;"); // 清空样式表，恢复默认外观
        }
    }
    else if (obj == m_rightYearBtn)
    {
        if (event->type() == QEvent::Enter)
        {
            m_rightYearBtn->setStyleSheet("border: 1px solid black;");
        }
        else if (event->type() == QEvent::Leave)
        {
            m_rightYearBtn->setStyleSheet("background-color: transparent;"); // 清空样式表，恢复默认外观
        }
    }
    else if (obj == m_rightMonthBtn)
    {
        if (event->type() == QEvent::Enter)
        {
            m_rightMonthBtn->setStyleSheet("border: 1px solid black;");
        }
        else if (event->type() == QEvent::Leave)
        {
            m_rightMonthBtn->setStyleSheet("background-color: transparent;"); // 清空样式表，恢复默认外观
        }
    }
    return QObject::eventFilter(obj, event);
}
