#include "infordialog.h"
#include "ui_infordialog.h"

InforDialog::InforDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InforDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("公司通知");       //设置标题
    QIcon icon = QIcon(":/image/manage.ico");//注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(495,400);
    setMinimumSize(495,400);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));       //返回信号与槽
    QObject::connect(ui->EditInforButton,SIGNAL(clicked()),this,SLOT(EditNoticeSlot()));//编辑信号与槽
    QObject::connect(ui->SingleInforButton,SIGNAL(clicked()),this,SLOT(SingleInforSlot()));//发送通知信号与槽
    QObject::connect(ui->AllInforButton,SIGNAL(clicked()),this,SLOT(AllSlot()));        //全体通知信号与槽
}

InforDialog::~InforDialog()
{
    delete ui;
}
void InforDialog::ReturnSlot()
{
    this->close();
    managesystem  *dialog = new managesystem; //回到上一层
    dialog->show();
}


void InforDialog::EditNoticeSlot()
{
    this->close();
    EditNoticeDialog*dialog = new EditNoticeDialog;
    dialog->show();
}

void InforDialog::SingleInforSlot()
{
    QMessageBox::information(this,"提示","通知已发送！",tr("确定"));
}

void InforDialog::AllSlot()
{
    int index = QMessageBox::information(this,"提示","要全体发送通知吗？",QMessageBox::Yes|QMessageBox::No);
     if(index ==QMessageBox::Yes)
     {
         QMessageBox::information(this,"提示","消息已发送！",tr("确定"));
            }
      else if(index ==QMessageBox::No)
     {
         qDebug()<<"您取消了全体发送通知";
            }
}
