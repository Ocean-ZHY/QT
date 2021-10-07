#ifndef ROLE_H
#define ROLE_H

#include <QWidget>

class Role : public QWidget
{
    Q_OBJECT
public:
    explicit Role(QWidget* parent = nullptr);

signals:


public slots:
    void GetExp();
    void GetExp(int _exp);
};

#endif // ROLE_H
