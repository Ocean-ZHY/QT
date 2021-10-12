#include "Mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //----------菜单栏再主窗口中只存在一个
    QMenuBar* menuBar = new QMenuBar;
    QMenu* childMenuF = new QMenu;
    QMenu* childMenuS = new QMenu;
    childMenuF->addAction("1");
    childMenuF->addAction("2");
    childMenuF->addAction("3");
    childMenuS->addAction("4");
    childMenuS->addAction("5");

    childMenuF->addMenu(childMenuS); //在菜单中加入菜单

    childMenuF->setTitle("数字");
    childMenuS->setTitle("测试");
    this->setMenuBar(menuBar); //设置菜单栏
    menuBar->addMenu(childMenuF); // 在菜单栏上加菜单
    menuBar->addMenu("文件")->addAction("打开"); //在文件子项中加打开子项

    //-----------工具栏  存在多个
    QToolBar* toolBar = new QToolBar;
    this->addToolBar(Qt::RightToolBarArea, toolBar);//设置工具栏 (默认停靠范围 工具栏)
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea); //设置工具栏允许停靠的位置
    toolBar->setMovable(true); //设置是否可以拖拽移动
    toolBar->setFloatable(false); //工具栏是否可悬浮
    toolBar->addAction("编辑");
    toolBar->addSeparator(); //在工具选项中间加分割线
    toolBar->addAction("打开");


    //------------状态栏
    QStatusBar* status = new QStatusBar;
    status->addWidget(new QPushButton("FPS 600")); //状态添加按钮
    status->addWidget(new QLabel("PIN 20")); //状态添加文本
    status->addPermanentWidget(new QLabel("今天天气很好")); //在右边添加
    this->setStatusBar(status);


    //-----------------中心部件
    this->setCentralWidget(new QTextEdit("请输入....."));


    //----------------衔接部件 （浮动窗口）
    QDockWidget* dock = new QDockWidget("文本一");
    this->addDockWidget(Qt::LeftDockWidgetArea, dock);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
}

MainWindow::~MainWindow()
{
}

