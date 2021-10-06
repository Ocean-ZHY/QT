#include "Widget.h"
#include <QPushButton>
#include <QDebug>
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

}

Widget::~Widget()
{
}

