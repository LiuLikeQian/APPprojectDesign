#include "managesadd.h"
#include "ui_managesadd.h"

managesAdd::managesAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managesAdd)
{
    ui->setupUi(this);
    this->setWindowTitle("新增员工");             //设置标题
    QIcon icon = QIcon(":/image/manage.ico");    //注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(600,430);
    setMinimumSize(600,430);

    //ui->textEdit->setReadOnly(true);                                                    //禁止显示员工信息的文本框输入信息


    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QObject ::connect(ui->SubmitButton,SIGNAL(clicked()),this,SLOT(SubmitSlot()));  //提交 按钮与槽
    QObject ::connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(CancelSlot()));  //取消 按钮与槽

    QObject ::connect(ui->DesignButton,SIGNAL(clicked()),this,SLOT(DesignSlot()));  //设置头像 按钮与槽
}

managesAdd::~managesAdd()
{
    delete ui;
}

void managesAdd::SubmitSlot()                                   //增加成员子窗口  提交按钮
{
    QString Nameindex = ui->NameEdit->text();                   //姓名
    QString Setindex = ui->SexEdit->text();                     //性别
    QString Cultureindex = ui->CultureEdit->text();             //文化程度
    QString PersonNumberindex = ui->PersonNumberEdit->text();   //身份证号码
    QString Periodindex = ui->PeriodEdit->text();               //合同期限
    QString WorkNumindex = ui->WorkNumEdit->text();             //员工号
    QString Stateindex =  ui->StateEdit->text();                //员工状态
    QString Palceindex =  ui->PlaceEdit->text();                //户口所在地

    if(Nameindex.isEmpty())                                     //判断基本信息有没有输入没有的话不能提交
    {
        QMessageBox::information(this,"提示","请输入姓名！");
    }
        else if(Setindex.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入性别！");
    }
        else if(Cultureindex.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入文化程度！");
    }
        else if(PersonNumberindex.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入身份证号码！");
    }
        else if(Periodindex.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入合约期限！");
    }
        else if(WorkNumindex.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入员工号！");
    }
        else if(Stateindex.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入员工状态！");
    }
        else if(Palceindex.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入员工户口所在地！");
    }
    else
    {
    this->close();                           //关闭子窗口
    managesystem  *index = new managesystem; //回到上一层
    index->show();
}
}


void managesAdd::CancelSlot()                //增加成员子窗口  取消按钮
{
    this->close();                           //关闭子窗口
    managesystem  *index = new managesystem; //回到上一层
    index->show();
}

void managesAdd::DesignSlot()
{
    ///usr/local/Trolltech
    QString index = QFileDialog::getOpenFileName( this,tr("打开文件"),"/usr/local/Trolltech",tr("任何文件(*.*)"";;文本文件(*.txt)"";;XML文件(*.xml)"";;Images (*.png *.xpm *.jpg)"));
    this->movie = new QMovie(index);

    ui->photolabel->setMovie(this->movie);
    this->movie->start();
}
