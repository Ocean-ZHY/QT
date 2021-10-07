#ifndef BOSS_H
#define BOSS_H

#include <QWidget>

class Boss : public QWidget
{
    Q_OBJECT
public:
    //explicit关键字  修饰函数参数 无法自动转换类型
    explicit Boss(QString _name, int _exp, QWidget *parent = nullptr);
    int exp;
    QString name;

//信号定义
signals:
    void DeadSignal();//定义死亡信号
    void DeadSignal(int _exp);

//槽函数定义
public slots:
    void BossDead();
//    void BossDead(int _exp);
};

#endif // BOSS_H
