#include "adcs_widget.h"
#include <QWidget>
#include "managewidget.h"
#include <qmessagebox.h>

ADCS_Widget::ADCS_Widget(Widget widget, QWidget *parent) : widget(widget), QWidget(parent)
{
    font.setBold(true);
    font.setPointSize(14);

    switch (widget)
    {
        case ADD://增
        {
            setFixedSize(300, 300);
            setWindowTitle("添加");

            QLabel *tip_label = new QLabel(this);
            tip_label->setGeometry(20, 50, 90, 40);
            tip_label->setText("输入单词：");
            tip_label->setFont(font);

            word_lineEdit = new QLineEdit(this);
            word_lineEdit->setGeometry(110, 50, 150, 40);
            word_lineEdit->setFont(font);

            QLabel *tip1_label = new QLabel(this);
            tip1_label->setGeometry(20, 100, 90, 40);
            tip1_label->setText("输入中文：");
            tip1_label->setFont(font);

            chinese_lineEdit = new QLineEdit(this);
            chinese_lineEdit->setGeometry(110, 100, 150, 40);
            chinese_lineEdit->setFont(font);

            confirm_btn = new QPushButton(this);
            confirm_btn->setGeometry(80, 200, 70, 40);
            confirm_btn->setText("确定");
            confirm_btn->setFont(font);
            connect(confirm_btn, &QPushButton::clicked, this, &ADCS_Widget::confirmBtn_click);

            cancle_btn = new QPushButton(this);
            cancle_btn->setGeometry(170, 200, 70, 40);
            cancle_btn->setText("取消");
            cancle_btn->setFont(font);
            connect(cancle_btn, &QPushButton::clicked, this, &ADCS_Widget::cancleBtn_click);
        }
        break;
        case DELETE://删
        {
            setFixedSize(300, 200);
            setWindowTitle("删除");

            QLabel *tip_label = new QLabel(this);
            tip_label->setGeometry(20, 50, 90, 40);
            tip_label->setText("输入单词：");
            tip_label->setFont(font);

            word_lineEdit = new QLineEdit(this);
            word_lineEdit->setGeometry(110, 50, 150, 40);
            word_lineEdit->setFont(font);

            confirm_btn = new QPushButton(this);
            confirm_btn->setGeometry(70, 120, 60, 40);
            confirm_btn->setText("确定");
            confirm_btn->setFont(font);
            connect(confirm_btn, &QPushButton::clicked, this, &ADCS_Widget::confirmBtn_click);

            cancle_btn = new QPushButton(this);
            cancle_btn->setGeometry(150, 120, 60, 40);
            cancle_btn->setText("取消");
            cancle_btn->setFont(font);
            connect(cancle_btn, &QPushButton::clicked, this, &ADCS_Widget::cancleBtn_click);
        }
        break;
        case CHANGE://改
        {
            setFixedSize(300, 300);
            setWindowTitle("修改");

            QLabel *tip_label = new QLabel(this);
            tip_label->setGeometry(20, 50, 90, 40);
            tip_label->setText("输入单词：");
            tip_label->setFont(font);

            word_lineEdit = new QLineEdit(this);
            word_lineEdit->setGeometry(110, 50, 150, 40);
            word_lineEdit->setFont(font);

            QLabel *tip1_label = new QLabel(this);
            tip1_label->setGeometry(20, 100, 90, 40);
            tip1_label->setText("输入中文：");
            tip1_label->setFont(font);

            chinese_lineEdit = new QLineEdit(this);
            chinese_lineEdit->setGeometry(110, 100, 150, 40);
            chinese_lineEdit->setFont(font);

            confirm_btn = new QPushButton(this);
            confirm_btn->setGeometry(80, 200, 70, 40);
            confirm_btn->setText("确定");
            confirm_btn->setFont(font);
            connect(confirm_btn, &QPushButton::clicked, this, &ADCS_Widget::confirmBtn_click);

            cancle_btn = new QPushButton(this);
            cancle_btn->setGeometry(170, 200, 70, 40);
            cancle_btn->setText("取消");
            cancle_btn->setFont(font);
            connect(cancle_btn, &QPushButton::clicked, this, &ADCS_Widget::cancleBtn_click);
        }
        break;
        case DISPLAY://查
        {
            setFixedSize(400, 600);
            QStandardItemModel* model = new QStandardItemModel();
            QStringList labels = QObject::trUtf8("单词,中文").simplified().split(",");//设置表头文本
            model->setHorizontalHeaderLabels(labels);//设置为表头

            int i = 0;
            QString word, chinese;
            QStandardItem* item;
            QString str = QString("select * from word");
            query.exec(str);
            while(query.next())
            {
                word = query.value(0).toString();
                chinese = query.value(1).toString();

                item = new QStandardItem(QString("%1").arg(word));
                model->setItem(i,0,item);//显示在方框中
                item = new QStandardItem(QString("%1").arg(chinese));
                model->setItem(i,1,item);//显示在方框中

                i++;
            }

            QTableView *tableView = new QTableView(this);//创建一个表格
            tableView->setFixedSize(400, 540);//设置大小
            tableView->setShowGrid(true);//显示网格
            tableView->setGridStyle(Qt::SolidLine);//设置网格线为实线
            tableView->setModel(model);//将刚才设置的表头和内容显示在里面
            tableView->verticalHeader()->setVisible(false);  // 隐藏行号
            tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //点击选中一行
            tableView->horizontalHeader()->setHighlightSections(false);//点击表时不对表头行光亮
            tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//设置每一列大小都一样
            tableView->setStyleSheet("QHeaderView::section { background-color:green; color:white};");//设置点击时整行显示绿色，其余时候为白色

            cancle_btn = new QPushButton(this);
            cancle_btn->setGeometry(320, 560, 80, 40);
            cancle_btn->setText("返回");
            cancle_btn->setFont(font);
            connect(cancle_btn, &QPushButton::clicked, this, &ADCS_Widget::cancleBtn_click);
        }
        break;
        default:
            break;
    }


}

ADCS_Widget::~ADCS_Widget()
{

}

void ADCS_Widget::confirmBtn_click()
{
    switch(widget)
    {
        case ADD:
        {
            QString word = word_lineEdit->text();
            QString chinese = chinese_lineEdit->text();

            if(word.isEmpty() || chinese.isEmpty())
            {
                QMessageBox::about(this, "tips", "输入不能为空");
                return ;
            }

            QString str = QString("select * from word where English = '%1'").arg(word);
            query.exec(str);
            while(query.next())
            {
                QMessageBox::about(this, "tips", "单词已存在");
                return ;
            }

            str = QString("insert into word(English, Chinese, study) \
                                values('%1', '%2', '%3')").arg(word).arg(chinese).arg(0);
            query.exec(str);
            QMessageBox::about(this, "tips", "添加成功");
            break;
        }
        case DELETE:
        {
            QString word = word_lineEdit->text();
            if(word.isEmpty())
            {
                QMessageBox::about(this, "tips", "输入不能为空");
                return ;
            }

            QString str = QString("DELETE FROM word WHERE  English = '%1'").arg(word);
            query.exec(str);
            QMessageBox::about(this, "tips", "删除成功");
        }
        break;
        case CHANGE:
        {
            QString word = word_lineEdit->text();
            QString chinese = chinese_lineEdit->text();

            if(word.isEmpty() || chinese.isEmpty())
            {
                QMessageBox::about(this, "tips", "输入不能为空");
                return ;
            }

            QString str = QString("update word set Chinese = '%1'  where English = '%2'").arg(chinese).arg(word);
            query.exec(str);
            QMessageBox::about(this, "tips", "修改成功");
        }
        break;
        default:
            break;
    }
}

void ADCS_Widget::cancleBtn_click()
{
    ManageWidget *m = new ManageWidget();
    m->show();
    m->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}

