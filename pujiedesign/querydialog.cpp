#include "querydialog.h"
#include "ui_querydialog.h"
#include <QIODevice>

QueryDialog::QueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("查询员工");
    QIcon icon = QIcon(":/image/manage.ico");                      //注意修改这里的图片目录
    setWindowIcon(icon);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QRegExp Countdator("[1-9][0-9]{1,9}$");                        //使用正则表达式过滤员工号中字母什么的，只能用员工号，限定10位
    QValidator *validator = new QRegExpValidator(Countdator,0);
    ui->lineEdit->setValidator(validator);

    setMaximumSize(550,430);
    setMinimumSize(550,430);

    ui->textEdit->setReadOnly(true);                                                    //禁止显示员工信息的文本框输入信息

    QObject ::connect(ui->SeachButton,SIGNAL(clicked()),this,SLOT(PersonNumSlot()));    //搜索员工号槽
    QObject ::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));      //返回槽
    QObject ::connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(PersonNumSlot())); //设置默认回车按钮是搜索
}

QueryDialog::~QueryDialog()
{
    delete ui;
}


void QueryDialog::PersonNumSlot()
{
    QFile file(":/information.txt");            //路径错误搞了一下午= =
     ui->textEdit->clear();                     //打开之前把textedit文本清空
     if(file.open(QIODevice::ReadOnly))         //判断文本是不是以只读形式打开
        {
        QTextStream read(&file);                //将txt关联到文本流

         while(!read.atEnd() )                  //一行一行的写到textEdit上面
         {
          ui->textEdit->append(read.readLine());
          }
        }
     file.close();
}


void QueryDialog::ReturnSlot()                  //返回、关闭当前窗口
{
    this->close();
    managesystem  *dialog = new managesystem; //回到上一层
    dialog->show();
}
