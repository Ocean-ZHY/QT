#include "Role.h"
#include <QWidget>
#include <QDebug>

Role::Role(QWidget* parent) : QWidget(parent)
{

}

void Role::GetExp()
{
    qDebug() << "获得经验";
}

void Role::GetExp(int _exp)
{
    qDebug() << "获得" << _exp << "经验";
}
