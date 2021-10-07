#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Boss.h"
#include "Role.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Boss* mBoss;
    Role* mRole;

public slots:
    //广播 boss死亡信号
    void BossDeadBrodcast();
};
#endif // WIDGET_H
