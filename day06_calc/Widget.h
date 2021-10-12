#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

enum BtnType //按钮类型
{
    num,
    Op,
    dot,
    equal,
    clear,
    back
};

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void OnClicked(BtnType _type, QString _btn);

private:
    Ui::Widget *ui;

    QString num1; //操作数1
    QString num2; //操作数2
    QString op; //运算符
    QString equ;
    QString res;
};
#endif // WIDGET_H
