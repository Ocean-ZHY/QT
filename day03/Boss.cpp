#include "Boss.h"
#include <QDebug>

Boss::Boss(QString _name, int _exp, QWidget *parent) : QWidget(parent)
{
    exp = _exp;
    name = _name;
}


void Boss::BossDead()
{
    qDebug() << name << "boss死了!" << exp;
}

//void Boss::BossDead(int _exp)
//{
//    qDebug() << name << "boss死了" << exp;
//}
