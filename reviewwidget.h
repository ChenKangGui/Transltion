#ifndef REVIEWWIDGET_H
#define REVIEWWIDGET_H

#include <QWidget>
#include <qlabel.h>
#include <qpushbutton.h>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <qfont.h>
#include "mainwindow.h"

class ReviewWidget : public QWidget
{
    Q_OBJECT
public:
    ReviewWidget(QWidget *parent=0);

    int num;
    int totalNum;
    QFont font;

    QLabel *word_label;
    QLabel *chinese_label;
    QPushButton *return_btn;
    QPushButton *next_btn;
    QPushButton *chinese_btn;

    QSqlQuery query;
public slots:
    void ReturnBtn_click();
    void ChineseBtn_click();
    void NextBtn_click();
};

#endif // REVIEWWIDGET_H
