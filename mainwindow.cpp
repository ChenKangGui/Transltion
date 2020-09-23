#include "mainwindow.h"
#include <qfont.h>
#include "translationwidget.h"
#include "studywidget.h"
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "reviewwidget.h"
#include "managewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(300, 400); //设置窗口大小
    setWindowTitle("博博的翻译小助手"); //设置窗口标题

    QFont font;
    font.setBold(true); //字体加粗
    font.setPointSize(13);  //字体大小

    QPushButton *studyBtn = new QPushButton(this);  //创建按键
    studyBtn->setText("学习单词");      //设置文本
    studyBtn->setGeometry(100, 40, 100, 50);    //设置位置以及大小  位置（100， 40）  宽：100  高：50
    studyBtn->setFont(font);        //设置字体格式
    connect(studyBtn, &QPushButton::clicked, this, &MainWindow::StudyBtn_click);//建立信号与槽 当该按键按下时，触发StudyBtn_click事件

    QPushButton *reviewBtn = new QPushButton(this);//创建按键
    reviewBtn->setText("复习单词");//设置文本
    reviewBtn->setGeometry(100, 110, 100, 50);//设置位置以及大小  位置（100， 110)  宽：100  高：50
    reviewBtn->setFont(font);//设置字体格式
    connect(reviewBtn, &QPushButton::clicked, this, &MainWindow::ReviewBtn_click);

    QPushButton *wordNumBtn = new QPushButton(this);
    wordNumBtn->setText("已学单词数");
    wordNumBtn->setGeometry(100, 180, 100, 50);
    wordNumBtn->setFont(font);
    connect(wordNumBtn, &QPushButton::clicked, this, &MainWindow::WordNumBtn_click);

    QPushButton *TranslationBtn = new QPushButton(this);
    TranslationBtn->setText("翻译单词");
    TranslationBtn->setGeometry(100, 250, 100, 50);
    TranslationBtn->setFont(font);
    connect(TranslationBtn, &QPushButton::clicked, this, &MainWindow::TranslationBtn_click);

    QPushButton *ManageBtn = new QPushButton(this);
    ManageBtn->setText("管理词库");
    ManageBtn->setGeometry(100, 320, 100, 50);
    ManageBtn->setFont(font);
    connect(ManageBtn, &QPushButton::clicked, this, &MainWindow::ManageBtn_click);

}

MainWindow::~MainWindow()
{

}

//当studyBtn按键被按下时，该函数被调用
void MainWindow::StudyBtn_click()
{
    StudyWidget *s = new StudyWidget();
    s->setAttribute(Qt::WA_DeleteOnClose);//关闭该窗口时，立即回收资源
    s->show();  //新建窗口并显示
    this->close();  //关闭当前窗口
}

//当reviewBtn按键被按下时，该函数被调用
void MainWindow::ReviewBtn_click()
{
    ReviewWidget *v = new ReviewWidget();
    v->setAttribute(Qt::WA_DeleteOnClose);
    v->show();
    this->close();
}

//当wordNumBtn按键被按下时，该函数被调用
void MainWindow::WordNumBtn_click()
{
    int num = 0;
    QString str = QString("select * from word where study = '%1'").arg(1);//拼接字符串 语句：根据指定条件（已学习的单词）查询数据库数据

    QSqlQuery query;
    query.exec(str);//执行该查询语句
    while(query.next())//实现查询
    {
        num++;
    }
    str = QString("已学习单词数：%1").arg(num); //拼接字符串

    QMessageBox::about(this, "tips", str);  //显示提示框
}
//当ManageBtn按键被按下时，该函数被调用
void MainWindow::ManageBtn_click()
{
    ManageWidget *m = new ManageWidget();
    m->setAttribute(Qt::WA_DeleteOnClose);
    m->show();
    this->close();
}
//当TranslationBtn按键被按下时，该函数被调用
void MainWindow::TranslationBtn_click()
{
    TranslationWidget *w = new TranslationWidget();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
    this->close();
}
