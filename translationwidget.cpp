#include "translationwidget.h"
#include <qfont.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <string.h>
#include <QDebug>
#include <qmessagebox.h>
#include "mainwindow.h"

TranslationWidget::TranslationWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 300);
    setWindowTitle("翻译");

    QFont font;
    font.setBold(true);
    font.setPointSize(12);

    QLabel *tipLabel = new QLabel(this);
    tipLabel->setGeometry(20, 20, 90, 40);
    tipLabel->setText("输入单词：");
    tipLabel->setFont(font);

    wordLineedit = new QLineEdit(this);
    wordLineedit->setGeometry(105, 20, 150, 40);
    wordLineedit->setFont(font);

    QPushButton *translationBtn = new QPushButton(this);
    translationBtn->setGeometry(270, 20, 80, 40);
    translationBtn->setText("翻译");
    translationBtn->setFont(font);
    connect(translationBtn, &QPushButton::clicked, this, &TranslationWidget::TranslationBtn_click);

    font.setPointSize(20);
    chineseLabel = new QLabel(this);
    chineseLabel->setGeometry(0, 150, 400, 50);
    chineseLabel->setFont(font);
    chineseLabel->setAlignment(Qt::AlignHCenter);

    return_btn = new QPushButton(this);
    return_btn->setGeometry(310, 250, 80, 40);
    return_btn->setText("返回");
    return_btn->setFont(font);
    connect(return_btn, &QPushButton::clicked, this, &TranslationWidget::ReturnBtn_click);
}

TranslationWidget::~TranslationWidget()
{

}

void TranslationWidget::TranslationBtn_click()
{
    bool flag = false;
    QString word = wordLineedit->text();

    QSqlQuery query;
    QString str = QString("select * from word where English = '%1'").arg(word);

    query.exec(str);
    while(query.next())
    {
        flag = true;
        chineseLabel->setText(query.value(1).toString());
    }

    if(!flag)//词库中没有该单词，显示提示框
    {
        QMessageBox::about(this, "tips", "对不起，小译也不认识该单词");
        return ;
    }
}

void TranslationWidget::ReturnBtn_click()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}



