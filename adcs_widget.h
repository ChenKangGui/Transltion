#ifndef ADCS_WIDGET_H
#define ADCS_WIDGET_H

#include <QWidget>
#include <qfont.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>

enum Widget
{
    ADD,
    DELETE,
    CHANGE,
    DISPLAY
};

class ADCS_Widget : public QWidget
{
    Q_OBJECT
public:
    ADCS_Widget(Widget f, QWidget *parent=0);
    ~ADCS_Widget();

    QFont font;
    Widget widget;
    QSqlQuery query;

    QLineEdit *word_lineEdit;
    QLineEdit *chinese_lineEdit;

    QPushButton *confirm_btn;
    QPushButton *cancle_btn;

public slots:
    void confirmBtn_click();
    void cancleBtn_click();
};

#endif // ADCS_WIDGET_H
