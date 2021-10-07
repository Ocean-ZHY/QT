#include "Widget.h"
#include <QPushButton> //按钮控件
#include <QDebug>
#include <QLabel> //文本控件
#include <QSlider> //滑动条控件
#include <QProgressBar> //进度条控件
#include <QTextEdit> //文本编辑框控件



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(300, 400);
    //最大化按钮 （被观察者）
    QPushButton* btnmax = new QPushButton("最大化", this);
    btnmax->move(20, 30);
    //观察者 （this窗口）
    //建立信号和槽连接
    connect(btnmax,SIGNAL(clicked()),this,SLOT(showMaximized()));

    QPushButton* btnmin = new QPushButton("最小化", this);
    btnmin->move(20, 90);
    connect(btnmin, SIGNAL(clicked()), this, SLOT(showMinimized()));

    QPushButton* btnNormal = new QPushButton("正常化", this);
    btnNormal->move(20, 150);
    connect(btnNormal, SIGNAL(clicked()), this, SLOT(showNormal()));

    //鼠标按下  打印：被打了
    //鼠标抬起  打印：反抗了
    QPushButton* btn = new QPushButton("老鼠", this);

    connect(btn, &QPushButton::pressed, [](){qDebug() << "老鼠被打了";});
    connect(btn, &QPushButton::released, [](){qDebug() << "老师反抗了";});
    //函数指针
    void (*pFun)();
    pFun = []()->void
    {
        qDebug() << "被打了";
    };



    //------------常用控件
    //*************文字控件
    QLabel* label = new QLabel;
    label->setParent(this);
    label->move(1, 100);
    label->setText("今天天气如何");
    label->setFont(QFont("楷体", 20, 10, 1));

    //*************滑动条控件
    QSlider* slider = new QSlider;
    slider->setParent(this);
    slider->move(100, 100);
    slider->setValue(20);
    //通过滑动滑动条 改变字体大小
    connect(slider, &QSlider::valueChanged, [label](int _value){
        label->setFont(QFont("楷体", _value, 10, 1));
        label->resize(500,_value+100);
    });

    //************进度条控件
    QProgressBar* proBar = new QProgressBar;
    proBar->setParent(this);
    proBar->move(0,200);
    proBar->resize(this->size().width(), 20);
    //proBar->setValue(50);
    //通过滑动条改变进度条的进度
    connect(slider, &QSlider::valueChanged, proBar, &QProgressBar::setValue);


    //************文本编辑框
    QTextEdit* edit = new QTextEdit;
    edit->move(0, 300);
    edit->resize(500,500);
    edit->setParent(this);
    edit->setFontUnderline(1);    //下划线
    edit->setFontPointSize(qreal(35.5));  //文字大小
    //edit->setText("阿三大苏打实打实啊实打实大苏打");
    //通过编辑文本框改变label文本内容
    connect(edit, &QTextEdit::textChanged, [label, edit](){
        label->setText(edit->toPlainText());
    });

    //****************补充：老版本信号和槽写法
    //点击按钮 最大化窗口
    auto* btn10 = new QPushButton("老版本写法", this);
    connect(btn10, SIGNAL(clicked()), this, SLOT(showMaximized()));
}

Widget::~Widget()
{
}

