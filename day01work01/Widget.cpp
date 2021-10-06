#include "Widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(400, 500);
    this->setWindowTitle("测试窗口");
    QPushButton* btn = new QPushButton("HELLO QT", this);
    btn->resize(100, 100);
    btn->move(150, 200);
}

Widget::~Widget()
{
}

