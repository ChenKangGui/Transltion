#ifndef TRANSLATIONWIDGET_H
#define TRANSLATIONWIDGET_H

#include <qwidget.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <qpushbutton.h>

class TranslationWidget : public QWidget
{
    Q_OBJECT
public:
    TranslationWidget(QWidget *parent=0);
    ~TranslationWidget();

    QLineEdit *wordLineedit;
    QLabel *chineseLabel;
    QPushButton *return_btn;

public slots:
    void TranslationBtn_click();
    void ReturnBtn_click();
};

#endif // TRANSLATIONWIDGET_H
