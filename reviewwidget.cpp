#include "reviewwidget.h"
#include <QDebug>

ReviewWidget::ReviewWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 400); //设置窗口大小
    setWindowTitle("复习");
    num = 0;
    totalNum = 0;

    font;
    font.setBold(true);//字体加粗
    font.setPointSize(13);//字体大小

    word_label = new QLabel(this);//创建一个label用来显示文本
    word_label->setGeometry(50, 100, 150, 40);//设置位置以及大小  位置（50， 100）  宽：150  高：40
    word_label->setFont(font); //设置字体格式
    word_label->setAlignment(Qt::AlignCenter);//设置文本居中显示

    next_btn = new QPushButton(this);//创建按键
    next_btn->setGeometry(200, 100, 80, 40);
    next_btn->setFont(font);
    next_btn->setText("下一个");
    connect(next_btn, &QPushButton::clicked, this, &ReviewWidget::NextBtn_click);//建立信号与槽 当该按键按下时，触发并NextBtn_click事件

    chinese_btn = new QPushButton(this);
    chinese_btn->setGeometry(100, 160, 80, 40);
    chinese_btn->setFont(font);
    chinese_btn->setText("中文：");
    connect(chinese_btn, &QPushButton::clicked, this, &ReviewWidget::ChineseBtn_click);

    chinese_label = new QLabel(this);
    chinese_label->setGeometry(180, 160, 100, 40);
    chinese_label->setFont(font);
    chinese_label->setAlignment(Qt::AlignCenter);

    return_btn = new QPushButton(this);
    return_btn->setGeometry(310, 350, 80, 40);
    return_btn->setText("返回");
    return_btn->setFont(font);
    connect(return_btn, &QPushButton::clicked, this, &ReviewWidget::ReturnBtn_click);

    QString str = QString("select * from word where study = '%1'").arg(1);//拼接字符串  语句：根据指定条件查询数据库
    query.exec(str);//执行该语句
    while(query.next())
    {
        word_label->setText(query.value(0).toString());//在label中显示单词
        break;
    }
    num++;

    str = QString("select * from word where study = '%1'").arg(1);//拼接字符串  语句：根据指定条件查询数据库
    query.exec(str);
    while(query.next())
    {
        totalNum++;//统计已学习单词数
    }
}

//当chinese_btn按键被按下时，该函数被调用
void ReviewWidget::ChineseBtn_click()
{
    QString word = word_label->text();
    QString str = QString("select * from word where English = '%1'").arg(word);//拼接字符串  语句：根据指定条件查询数据库

    QSqlQuery query;
    query.exec(str);
    while(query.next())
    {
        chinese_label->setText(query.value(1).toString());//在label中显示翻译中文
        break;
    }

}

void ReviewWidget::NextBtn_click()
{
    chinese_label->clear();//清除chinese_label中的文本

    int i = 0;

    QString str = QString("select * from word where study = '%1'").arg(1);
    query.exec(str);
    while(query.next())
    {
        if(i >= num)//查询它的下一个单词
        {
            num++;
            word_label->setText(query.value(0).toString());
            break;
        }

        i++;
    }

    if(num >= totalNum)//当复习完所有单词时，重新从第一个开始
    {
        num = 0;
    }
}


void ReviewWidget::ReturnBtn_click()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}

