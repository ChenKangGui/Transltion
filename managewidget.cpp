#include "managewidget.h"
#include <qfont.h>
#include "adcs_widget.h"

ManageWidget::ManageWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300, 400);//设置窗口大小
    setWindowTitle("管理");

    QFont font;
    font.setBold(true);//字体加粗
    font.setPointSize(14);//字体大小

    QPushButton *add_btn = new QPushButton(this);//创建按键
    add_btn->setGeometry(80, 50, 100, 40);//设置位置以及大小  位置（80， 50）  宽：100  高：40
    add_btn->setText("增加单词"); //设置文本
    add_btn->setFont(font);//设置字体格式
    connect(add_btn, &QPushButton::clicked, this, &ManageWidget::AddBtn_click);//建立信号与槽 当该按键按下时，触发并相应相关事件

    QPushButton *delete_btn = new QPushButton(this);
    delete_btn->setGeometry(80, 110, 100, 40);
    delete_btn->setText("删除单词");
    delete_btn->setFont(font);
    connect(delete_btn, &QPushButton::clicked, this, &ManageWidget::DeleteBtn_click);

    QPushButton *change_btn = new QPushButton(this);
    change_btn->setGeometry(80, 170, 100, 40);
    change_btn->setText("修改单词");
    change_btn->setFont(font);
    connect(change_btn, &QPushButton::clicked, this, &ManageWidget::ChangeBtn_click);

    QPushButton *show_btn = new QPushButton(this);
    show_btn->setGeometry(80, 230, 100, 40);
    show_btn->setText("查看词库");
    show_btn->setFont(font);
    connect(show_btn, &QPushButton::clicked, this, &ManageWidget::ShowBtn_click);

    QPushButton *return_btn = new QPushButton(this);
    return_btn->setGeometry(210, 350, 80, 40);
    return_btn->setText("返回");
    return_btn->setFont(font);
    connect(return_btn, &QPushButton::clicked, this, &ManageWidget::returnBtn_click);
}

ManageWidget::~ManageWidget()
{

}

//当add_btn按键被按下时，该函数被调用
void ManageWidget::AddBtn_click()
{
    ADCS_Widget *a = new ADCS_Widget(ADD);
    a->setAttribute(Qt::WA_DeleteOnClose);
    a->show();
    this->close();
}

//当delete_btn按键被按下时，该函数被调用
void ManageWidget::DeleteBtn_click()
{
    ADCS_Widget *a = new ADCS_Widget(DELETE);//新建窗口并显示
    a->setAttribute(Qt::WA_DeleteOnClose);//关闭该窗口时，立即回收资源
    a->show();
    this->close();
}

//当change_btn按键被按下时，该函数被调用
void ManageWidget::ChangeBtn_click()
{
    ADCS_Widget *a = new ADCS_Widget(CHANGE);
    a->setAttribute(Qt::WA_DeleteOnClose);
    a->show();
    this->close();
}

//当show_btn按键被按下时，该函数被调用
void ManageWidget::ShowBtn_click()
{
    ADCS_Widget *a = new ADCS_Widget(DISPLAY);
    a->setAttribute(Qt::WA_DeleteOnClose);
    a->show();
    this->close();
}

//当return_btn按键被按下时，该函数被调用
void ManageWidget::returnBtn_click()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}


