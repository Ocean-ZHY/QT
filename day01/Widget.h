#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>  //包含QT空窗口

class Widget : public QWidget
{
    Q_OBJECT //支持信号和槽

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
