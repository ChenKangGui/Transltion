#include "studywidget.h"
#include "mainwindow.h"
#include <qobject.h>
#include <QDebug>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QSqlDatabase>

StudyWidget::StudyWidget()
{
    setFixedSize(400, 400);//设置窗口大小
    setWindowTitle("学习");

    font;
    font.setBold(true); //字体加粗
    font.setPointSize(13);//字体大小

    tip_label = new QLabel(this);//创建label以显示文本
    tip_label->setGeometry(20, 150, 150, 40);//设置位置以及大小  位置（20， 150）  宽：150  高：40
    tip_label->setText("今日学习目标数：");//设置文本
    tip_label->setFont(font);//设置字体格式

    num_lineEdit = new QLineEdit(this);//创建输入框
    num_lineEdit->setGeometry(170, 150, 150, 40);
    num_lineEdit->setFont(font);

    confirm_btn = new QPushButton(this);
    confirm_btn->setGeometry(100, 230, 80, 40);
    confirm_btn->setText("确定");
    confirm_btn->setFont(font);
    connect(confirm_btn, &QPushButton::clicked, this, &StudyWidget::ConfirmBtn_click);//建立信号与槽 当该按键按下时，触发ConfirmBtn_click事件

    return_btn = new QPushButton(this);
    return_btn->setGeometry(200, 230, 80, 40);
    return_btn->setText("返回");
    return_btn->setFont(font);
    connect(return_btn, &QPushButton::clicked, this, &StudyWidget::ReturnBtn_click);//建立信号与槽 当该按键按下时，触发ReturnBtn_click事件

}

StudyWidget::~StudyWidget()
{

}

void StudyWidget::ConfirmBtn_click()
{
    if(num_lineEdit->text().isEmpty())//判断输入框不能为空
    {
        QMessageBox::about(this, "tips", "输入不能为空");//当输入框为空时，弹出提示框
        return ;
    }

    totalNum = num_lineEdit->text().toInt();//获取输入框的内容并转换为int

    delete tip_label;//删除label
    delete num_lineEdit;
    delete confirm_btn;
    return_btn->move(320, 340);//移动返回按键

    word_label = new QLabel(this);
    word_label->setGeometry(50, 100, 150, 40);
    word_label->setFont(font);
    word_label->setAlignment(Qt::AlignCenter);
    word_label->show();//显示label出来

    next_btn = new QPushButton(this);
    next_btn->setGeometry(200, 100, 80, 40);
    next_btn->setFont(font);
    next_btn->setText("下一个");
    next_btn->show();
    connect(next_btn, &QPushButton::clicked, this, &StudyWidget::NextBtn_click);

    chinese_btn = new QPushButton(this);
    chinese_btn->setGeometry(100, 160, 80, 40);
    chinese_btn->setFont(font);
    chinese_btn->setText("中文：");
    chinese_btn->show();
    connect(chinese_btn, &QPushButton::clicked, this, &StudyWidget::ChineseBtn_click);

    chinese_label = new QLabel(this);
    chinese_label->setGeometry(180, 160, 100, 40);
    chinese_label->setFont(font);
    chinese_label->setAlignment(Qt::AlignCenter);
    chinese_label->show();

    QString word;
    QString str = QString("select * from word where study = '%1'").arg(0);//拼接字符串  语句：根据指定条件查询数据库
    QSqlQuery query;
    query.exec(str);
    while(query.next())
    {
        word = query.value(0).toString();//获取数据库中的数据出来
        word_label->setText(word);//设置label的文本出来
        break;
    }

    str = QString("update word set study = '%1'  where English = '%2'").arg(1).arg(word);//修改数据库中的数据，表示已学
    query.exec(str);


    num++;
}

void StudyWidget::ChineseBtn_click()
{
    QString word = word_label->text();
    QString str = QString("select * from word where English = '%1'").arg(word);

    QSqlQuery query;
    query.exec(str);
    while(query.next())
    {
        word = query.value(1).toString();
        chinese_label->setText(word);
        break;
    }
}

void StudyWidget::NextBtn_click()
{
    if(num >= totalNum)//当达到学习目标时，弹出提示框，并返回首页。 不然继续显示下一个
    {
        QMessageBox::question(this, "tips", "已完成今日学习目标", QMessageBox::Ok);
        MainWindow *m = new MainWindow();
        m->show();
        this->close();
    }
    chinese_label->clear();

    QString word;
    QString str = QString("select * from word where study = '%1'").arg(0);
    QSqlQuery query;
    query.exec(str);
    while(query.next())
    {
        word = query.value(0).toString();
        word_label->setText(word);
        break;
    }

    str = QString("update word set study = '%1'  where English = '%2'").arg(1).arg(word);//修改数据库中的数据，表示已学
    query.exec(str);

    num++;
}


void StudyWidget::ReturnBtn_click()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}

