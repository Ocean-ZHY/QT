#include "Widget.h"

#include <QApplication>

/*
信号和槽：是QT框架引以为豪的东西，实际上就是 观察者模式 一种简易方式
使用connect 函数可以为信号 以及 槽 建立好连接 当信号 广播（触发）时 槽做出相应的处理，
信号来自于 被观察者
槽来自于 观察者

Signal信号：函数声明 无需实现 系统大多数类都内置了信号  开发者也可以自定义信号
Slot槽：本质就是个函数 一般是类的成员函数 有声明且由实现体

Lamda表达式定义函数语法：
[可访问外部变量](参数表)->返回值{函数体}

[变量名1，变量名1...](){}   指定部分变量访问
[=](){}                  值传递形式捕获所有外部变量（内部无法改变实际变量）
[&](){}                  引用形式捕获所有外部变量（可以改变实际变量）
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
