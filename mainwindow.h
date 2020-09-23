#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qmainwindow.h>
#include <qpushbutton.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void StudyBtn_click();
    void ReviewBtn_click();
    void WordNumBtn_click();
    void TranslationBtn_click();
    void ManageBtn_click();
};

#endif // MAINWINDOW_H
