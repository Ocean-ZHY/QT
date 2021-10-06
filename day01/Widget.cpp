#include "Widget.h"
#include<QPushButton> //包含按钮的头文件
#include "Student.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("hello qt"); //设置窗口标题
    this->resize(50,240); //设置窗口大小
    this->setFixedSize(200, 100); //设置窗口的固定大小，无法拖拽改变窗口大小


    //创建按钮
    QPushButton* btn = new QPushButton;
    //btn->resize(20,10); 设置按钮大小
    btn->setParent(this); //设置父指针
    btn->setText("游戏");
    btn->move(20, 20); //设置按钮的位置
    btn->show();

    Student* stu = new Student;
    stu->setParent(this); //为本窗口设置父亲， 当父窗口释放时 会释放孩子
}

Widget::~Widget()
{
}

