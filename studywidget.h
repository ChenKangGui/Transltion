#ifndef STUDYWIDGET_H
#define STUDYWIDGET_H

#include <qwidget.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qfont.h>

class StudyWidget : public QWidget
{
    Q_OBJECT
public:
    StudyWidget();
    ~StudyWidget();
    
    QLabel *word_label;
    QLabel *tip_label;
    QLabel *chinese_label;
    QLineEdit *num_lineEdit;
    QPushButton *confirm_btn;
    QPushButton *return_btn;
    QPushButton *next_btn;
    QPushButton *chinese_btn;

    
    QFont font;

    int totalNum;
    int num;

public slots:
    void ConfirmBtn_click();
    void ReturnBtn_click();
    void ChineseBtn_click();
    void NextBtn_click();
};

#endif // STUDYWIDGET_H
