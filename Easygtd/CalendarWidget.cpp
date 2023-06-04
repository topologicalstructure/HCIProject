#include"CalendarWidget.h"
#include <QPushButton>
#include <QLabel>
#include<QEvent>
#include<QHBoxLayout>
#include <QProxyStyle>
#include <QtMath>

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
    oper=new SqliteOperator;
    initControl();
    connect(this, &CalendarWidget::selectionChanged, [this]() {
        QDate date= selectedDate();
        QTextCharFormat format;
        this->setDateTextFormat(date, format);
    });
}
void CalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    oper=new SqliteOperator;

    //下面重新绘制选中日期的格子底色和文本
    painter->save();
    int taskcount=oper->GetDeadline(date.toString(Qt::ISODate));//存储ddl数量
    if(taskcount>MAX_DDL)
    {
        taskcount=MAX_DDL;
    }
    int hue=H_MAX+K*taskcount;
    QColor newcolor = QColor::fromHsl(hue, S_CONST, L_CONST);
    if(taskcount>0)
    {
    painter->fillRect(rect, newcolor);    // 绘制选中日期的背景色
    }
    // 绘制选中日期的文本颜色
    painter->setPen(Qt::black);
    painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
    //底色和文本设置完毕
    painter->restore();

    if (date == selectedDate())
    {
        painter->save();
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
    if (date == QDate::currentDate()) {
        // 在今日的左上角绘制三角形
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing, true);// 抗锯齿
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::blue);

        QPoint points[3];
        points[0] = rect.topLeft();
        points[2] = rect.topLeft()+alpha_triangle*(rect.bottomLeft()-rect.topLeft());
        points[1].setY(points[0].y());
        int deltaX = (points[2] - points[0]).manhattanLength();  // 计算曼哈顿距离
        points[1].setX(points[0].x() + deltaX);
        painter->drawPolygon(points, 3);

//        QPoint center;
//        int radius=floor(deltaX/(2+qSqrt(2)));
//        center.setX(points[0].x()+radius+1);
//        center.setY(points[0].y()+radius+1);
//        painter->setBrush(QColor::fromRgb(238,232,170)); // 设置填充颜色
//        painter->drawEllipse(center, radius, radius); // 绘制内接圆

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
    format.setForeground(Qt::black);//前景色（字的颜色）
    //format.setBackground(Qt::blue);//背景色
    //format.setFontFamily("Times New Roman");//字体
    //format.setFontPointSize(9);//字号
    //format.setFontWeight(QFont::Medium);//字体粗细
    setHeaderTextFormat(format);
    setWeekdayTextFormat(Qt::Saturday, format);
    setWeekdayTextFormat(Qt::Sunday,   format);
    setWeekdayTextFormat(Qt::Monday,   format);
    setWeekdayTextFormat(Qt::Tuesday,  format);
    setWeekdayTextFormat(Qt::Wednesday,format);
    setWeekdayTextFormat(Qt::Thursday, format);
    setWeekdayTextFormat(Qt::Friday,   format);

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

    //下面曾经用于颜色修改测试
    //topWidget->setStyleSheet("background-color: red;");
//    QLinearGradient gradient(0, 0, 0, topWidget->height());
//    gradient.setColorAt(0, Qt::blue);
//    gradient.setColorAt(1, Qt::green);
//    QBrush brush(gradient);
//    QPalette palette;
//    palette.setBrush(QPalette::Window, brush);
//    topWidget->setAutoFillBackground(true);
//    topWidget->setPalette(palette);
    //颜色修改完毕

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

    hboxLayout->setContentsMargins(0, 10, 12, 10);
    hboxLayout->setSpacing(6);

    m_toDayBtn = new QPushButton(this);
    m_toDayBtn->setObjectName("CalendarTodayBtn");
    m_toDayBtn->setFixedSize(3*toDayBtn_length, toDayBtn_length);
    m_toDayBtn->setText(QStringLiteral("回到今日页面"));
    m_ddlLabel = new QLabel(this);
    m_ddlLabel -> setObjectName("CalendarddlLabel");

    hboxLayout->addWidget(m_ddlLabel);
    hboxLayout->addStretch();
    hboxLayout->addWidget(m_toDayBtn);
    bottomWidget->setLayout(hboxLayout);

    QVBoxLayout *vBodyLayout = qobject_cast<QVBoxLayout *>(layout());
    vBodyLayout->addWidget(bottomWidget);

    connect(m_toDayBtn, &QPushButton::clicked, [this](){

        showToday();
    });

    setddlLabelText();
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
void CalendarWidget::setddlLabelText()
{
    QDate date= selectedDate();
    QTextCharFormat format;// 设置背景色为指定颜色，根据某天任务数量的多少确定
    int hue=0;//设定颜色的色相数值
    oper=new SqliteOperator;
    int taskcount=oper->GetDeadline(date.toString(Qt::ISODate));//存储ddl数量
    int ddl_overflow=0;
    if(taskcount>MAX_DDL)
    {
        ddl_overflow=1;
        taskcount=MAX_DDL;
    }
    hue=H_MAX+K*taskcount;
    QColor newcolor = QColor::fromHsl(hue, S_CONST, L_CONST);//这就是ddl框的背景色

    QFont font = m_ddlLabel->font();
    font.setPointSize(15);  // 设置字号
    font.setFamily("Arial");  // 设置字体名称为 Arial
    font.setBold(true);      // 设置加粗
    font.setItalic(false);   // 取消斜体
    m_ddlLabel->setFont(font);
    if(ddl_overflow==0)
    {
        m_ddlLabel->setText("DDL：" + QString::number(taskcount));
    }
    else
    {
        m_ddlLabel->setText("DDL：" + QString::number(taskcount)+"+");
    }
    //下面是设置DDL框的背景的颜色
    if(taskcount>0)
    {
       QPalette palette = m_ddlLabel->palette();  // 获取 m_ddlLabel 的调色板
       palette.setColor(QPalette::Window, newcolor);  // 设置背景色
       m_ddlLabel->setPalette(palette);  // 应用修改后的调色板
       m_ddlLabel->setAutoFillBackground(true);  // 开启自动填充背景
    }
    else
    {
       QPalette defaultPalette = m_ddlLabel->palette();  // 获取默认的调色板
       m_ddlLabel->setPalette(defaultPalette);  // 将默认的调色板应用到标签
       m_ddlLabel->setAutoFillBackground(false);  // 关闭自动填充背景
    }
    m_ddlLabel->update();  // 更新 m_ddlLabel 的显示
}
void CalendarWidget::onbtnClicked()
{
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
