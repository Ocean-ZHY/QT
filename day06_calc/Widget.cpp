#include "Widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //数字按钮绑定
    connect(ui->num0, &QPushButton::clicked, [this](){OnClicked(num, "0");});
    connect(ui->num1, &QPushButton::clicked, [this](){OnClicked(num, "1");});
    connect(ui->num2, &QPushButton::clicked, [this](){OnClicked(num, "2");});
    connect(ui->num3, &QPushButton::clicked, [this](){OnClicked(num, "2");});
    connect(ui->num4, &QPushButton::clicked, [this](){OnClicked(num, "4");});
    connect(ui->num5, &QPushButton::clicked, [this](){OnClicked(num, "5");});
    connect(ui->num6, &QPushButton::clicked, [this](){OnClicked(num, "6");});
    connect(ui->num7, &QPushButton::clicked, [this](){OnClicked(num, "7");});
    connect(ui->num8, &QPushButton::clicked, [this](){OnClicked(num, "8");});
    connect(ui->num9, &QPushButton::clicked, [this](){OnClicked(num, "9");});

    //运算符按钮绑定
    connect(ui->sum, &QPushButton::clicked, [this](){OnClicked(Op, "+");});
    connect(ui->sub, &QPushButton::clicked, [this](){OnClicked(Op, "-");});
    connect(ui->mul, &QPushButton::clicked, [this](){OnClicked(Op, "*");});
    connect(ui->div, &QPushButton::clicked, [this](){OnClicked(Op, "/");});

    //其他按钮绑定
    connect(ui->dot, &QPushButton::clicked, [this](){OnClicked(dot, ".");});
    connect(ui->back, &QPushButton::clicked, [this](){OnClicked(back, "Back");});
    connect(ui->equal, &QPushButton::clicked, [this](){OnClicked(equal, "Equal");});
    connect(ui->clear, &QPushButton::clicked, [this](){OnClicked(clear, "Clear");});
}

Widget::~Widget()
{
    delete ui;
}


void Widget::OnClicked(BtnType _type, QString _btn)
{
    if(!equ.isEmpty())
    {
        if(_type==Op)
        {
            num1 = res;
        }
        else
        {
            num1.clear();
        }
        num2.clear();
        op.clear();
        equ.clear();
        res.clear();
    }
    switch (_type) //按钮类型
    {
        case num:
        {
           if(op.isEmpty())
           {
               num1 += _btn;
           }
           else
           {
               num2 += _btn;
           }
            break;
        }
        case Op: //运算符
        {
            op = _btn;
            break;
        }
        case clear: //清除
        {
            num1.clear();
            num2.clear();
            op.clear();
        }
        case dot: //点
        {
            if(op.isEmpty())
            {
                //操作数一的小数点
                if(!num1.isEmpty() && !num1.contains("."))//操作数没有点且不空
                {
                     num1 += _btn;
                }
            }
            else
            {
                //操作数二的点
                if(!num2.isEmpty() && !num2.contains("."))
                {
                    num2 += _btn;
                }
            }
            break;
        }
        case equal:  //结果
        {
            if(!num2.isEmpty())
            {
                equ = "=";
                double n1 = num1.toDouble(); //将字符串转换为小数
                double n2 = num2.toDouble();
                double result = 0.0;
                if(op=="+")
                {
                    result = n1 + n2;
                }
                else if(op=="-")
                {
                    result = n1- n2;
                }
                else if(op=="*")
                {
                    result = n1 * n2;
                }
                else if(op=="/")
                {
                    if(n2!=0)
                    {
                        result = n1 / n2;
                    }
                    else
                    {
                        ui->lineEdit->setText("错误");
                        return;
                    }
                }
                res = QString::number(result);
                break;
            }
        }
        case back:
        {
            if(!num2.isEmpty())
            {
                num2.chop(1);
            }
            else if(!op.isEmpty())
            {
                op.chop(1);
            }
            else if(!num1.isEmpty())
            {
                num1.chop(1);
            }
            break;
        }
    }

    ui->lineEdit->setText(num1 + op + num2 + equ + res);
}
