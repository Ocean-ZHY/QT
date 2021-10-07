#include "Widget.h"

#include <QApplication>


/*
QT内置的大量信号和槽 还支持用户自定义信号和槽

自定义槽：
    1.有函数声明且有实现
    2.返回值为类型void
    3.槽函数 可以带参 可以重载（槽函数实参是从信号而来）

自定义信号：
    1.写在Signal：下
    2.只需声明，无需实现
    3.返回值为void
    4.支持带参，可重载
    5.emit 可触发信号

自定义信号和槽特点
    1.一个信号可以被多个信号绑定
    2.同一个槽函数可以绑定多个信号
    3.信号和槽函数的参数表要一一对应
    4.信号的参数表可以都多余槽函数，
      反之，槽函数的参数表不能多余信号的参数表
    5.信号可以绑定信号

信号和槽断开连接
disconnect 断开连接关键字
connect 连接关键字
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
