#include "Widget.h"
#include "Boss.h"
#include <QPushButton>
#include <QDebug>
#include "Role.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //观察者 boss   处理函数  死亡打印
    //被观察者：按钮  信号：点击
    //按钮点击  处理Boss  死亡

    auto btn = new QPushButton("击杀", this); //被观察者 （信号源）
    btn->move(0,50);
    auto boss1 = new Boss("白蛇", 2000); //观察者
    mBoss = new Boss("美猴王", 10000);
    mRole = new Role(this);

    connect(btn, &QPushButton::clicked, boss1,&Boss::BossDead);//绑定信号

    //boss  死亡信号 广播后 触发Boss死亡槽函数
     //思路：点击按钮 触发死亡信号  死亡信号对应boss死亡槽函数处理
    QPushButton* btn2 = new QPushButton("死亡信号", this);
    connect(btn2, &QPushButton::clicked, this, &Widget::BossDeadBrodcast);//点击触发信号广播，广播Boss死亡信号

    //---------重载后无参 信号 和 槽
    void(Boss::*deadSignal0)() = &Boss::DeadSignal;//信号指针
    void(Boss::*bossDead0)() = &Boss::BossDead; //槽指针
    connect(mBoss, deadSignal0, mBoss, bossDead0);//死亡信号触发后  死亡槽函数处理打印

    //boss死亡信号触发  角色获得经验处理
    //connect(mBoss, &Boss::DeadSignal, mRole, &Role::GetExp);

    //连接带参的信号和槽
    void(Boss::*deadSignal)(int) = &Boss::DeadSignal;//信号指针
    void(Role::*getExp)(int) = &Role::GetExp; //槽指针
    connect(mBoss, deadSignal, mRole, getExp);

    //信号绑定信号
    QPushButton* btn3 = new QPushButton("信号绑定信号测试", this);
    btn3->move(0,100);
    connect(btn3, &QPushButton::clicked, mBoss, deadSignal0);

    //断开连接
    //disconnect(btn3, &QPushButton::clicked, mBoss, deadSignal0);
}

Widget::~Widget()
{
}

void Widget::BossDeadBrodcast()
{
    //触发死亡信号逻辑
    qDebug() << "死亡信号广播";
    emit mBoss->DeadSignal();//此处为触发信号 emit关键字用来触发信号
    emit mBoss->DeadSignal(mBoss->exp);//触发有参信号

}
