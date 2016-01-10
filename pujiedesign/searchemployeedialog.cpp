#include "searchemployeedialog.h"
#include "ui_searchemployeedialog.h"


SearchEmployeeDialog::SearchEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchEmployeeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("员工信息修改");
    QIcon icon = QIcon(":/image/manage.ico");                      //注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(350,250);
    setMinimumSize(350,250);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QRegExp Countdator("[1-9][0-9]{1,9}$");                        //使用正则表达式过滤账户中字母什么的，只能用员工号，限定10位
    QValidator *validator = new QRegExpValidator(Countdator,0);
    ui->lineEdit->setValidator(validator);

    QObject::connect(ui->SearchAdultButton,SIGNAL(clicked()),this,SLOT(SearchEmployeeSlot()));//搜索槽
    QObject::connect(ui->GoHomeButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));             //返回槽

}

SearchEmployeeDialog::~SearchEmployeeDialog()
{
    delete ui;
}

void SearchEmployeeDialog::SearchEmployeeSlot()
{
    QString index = ui->lineEdit->text();
    if(index.isEmpty())
    {
        QMessageBox::information(this,"搜索","请输入员工号！");
    }
    else
    {
        this->close();
        ModifyDialog *dialog = new ModifyDialog;
        dialog->show();

    }
}
void SearchEmployeeDialog::ReturnSlot()
{

    this->close();
    managesystem  *index = new managesystem; //回到上一层
    index->show();

}
