#include "Widget.h"

#include <QApplication>

/*
QT快捷键
注释 ctrl+/
运行 ctrl+r
构建 ctrl+b
转到定义/声明切换 F2
返回 Alt + ⬅
前进 Alt + ➡

QPushButton 继承于QAbstractButton 继承于QWidget 继承于 QObject
构造函数
auto b = new QPushButton; 无参构造
auto b  = new QPushButton(文本，父亲）； 带参构造
相关接口
resize 重置大小
setFixedSize 设置固定大小
move 设置位置
setParent 设置父亲
setFont 设置字体
show 显示函数

对象树 QT中的类的继承关系，有一定程度上简化了对象释放操作，由QT的QOobject类派生出来的类，无需手动释放堆内存
添加到QObject或QObject派生类的对象也无需手动释放，程序结束时，QT会自动检测对象树的对象，释放对象前先释放子对象从而一层一层的最终释放最上层父对象。
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //定义应用程序对象
    Widget w;  //定义空窗口对象
    w.show();  //调用空窗口子函数  显示窗口
    return a.exec();
}
