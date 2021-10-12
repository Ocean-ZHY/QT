#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include <QDialog>
#include <QFileDialog> //文件对话框
#include <QColorDialog> //颜色对话框
#include <QFontDialog> //文字对话框
#include <QMessageBox> //消息对话框 （警告，普通，错误）
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
    auto tb = ui->textEdit;
    auto lb = ui->label;
    connect(ui->textEdit, &QTextEdit::textChanged, [tb, lb](){
        lb->setText(tb->toPlainText());
    });


    //-------------对话框
    //自定义对话框
    //   a.模态对话框:阻塞式创建对话框，无法对其他对话框做操作
    //   b.非模态对话框：非阻塞式 激活时可以对其他窗口做操作

    //模态对话框创建
    connect(ui->btn1, &QPushButton::clicked, this, [this](){
        //创建窗口
        QDialog dialog(this);
        dialog.resize(200, 200);
        dialog.exec(); //进入消息捕捉循环
    });

    //非模态对话框创建
    //方式一：在模块对话框中加入dialog.show();
    //方式二：使用指针创建
    connect(ui->btn2, &QPushButton::clicked, [this](){
       QDialog* dialogP = new QDialog(this);
       dialogP->resize(200, 200);
       dialogP->show();
       dialogP->setAttribute(Qt::WA_DeleteOnClose); //关闭时释放对话框
    });

    /*
    QT内置对话框
        1.文件对话框 QFileDialog::getOpenFileName
        2.颜色对话框 QColorDialog::getColor
        3.文字对话框 QFontDialog::getFont
        4.消息对话框 （1：父亲，2：标题，3：内容，4：按钮，5：回车时默认选择）
                   QMessageBox::critical       错误
                   QMessageBox::warning        警告
                   QMessageBox::information    信息
    */
    connect(ui->btn3, &QPushButton::clicked, [this](){
        //(参数1：父亲， 参数2:标题，参数3：默认打开路径，参数4:文件格式)
        QString fileName = QFileDialog::getOpenFileName(this,"打开文件", "D:/", "*.txt");

        //(默认颜色， 父亲， 标题)
        auto color = QColorDialog::getColor(Qt::blue, this, "文字颜色");
        //ui->label->setPalette(color);

        //文字对话框
        bool bl = true; //是否使用用户选择的字体
        QFont font = QFontDialog::getFont(&bl);
        ui->label->setFont(font);
        ui->label->setText("你好");

    });

    QMessageBox::critical(this, "错误", "你错了");
    QMessageBox::warning(this, "警告", "你错了");
    QMessageBox::information(this, "提示", "你错了");
    auto btn = QMessageBox::question(this, "问题", "问题1？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(btn==QMessageBox::Yes)
    {
        QMessageBox::information(this, "", "问题二");
    }
    else
    {
        QMessageBox::critical(this, "错误", "回答错误");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

