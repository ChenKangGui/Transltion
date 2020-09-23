#ifndef MANAGEWIDGET_H
#define MANAGEWIDGET_H

#include <QWidget>
#include <qlabel.h>
#include <qpushbutton.h>
#include "mainwindow.h"

class ManageWidget : public QWidget
{
    Q_OBJECT
public:
    ManageWidget(QWidget *parent=0);
    ~ManageWidget();

public slots:
    void returnBtn_click();
    void AddBtn_click();
    void DeleteBtn_click();
    void ChangeBtn_click();
    void ShowBtn_click();
};

#endif // MANAGEWIDGET_H
