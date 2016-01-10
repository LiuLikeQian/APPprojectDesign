#include "editnoticedialog.h"
#include "ui_editnoticedialog.h"

EditNoticeDialog::EditNoticeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditNoticeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("编辑通知");     //设置标题
    QIcon icon = QIcon(":/image/manage.ico");//注意修改这里的图片目录
    setWindowIcon(icon);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));       //返回信号与槽
    QObject::connect(ui->SubmitButton,SIGNAL(clicked()),this,SLOT(SubmitSlot()));       //提交信号与槽
}

EditNoticeDialog::~EditNoticeDialog()
{
    delete ui;
}


void EditNoticeDialog::ReturnSlot()
{
    this->close();
    InforDialog *dialog = new InforDialog;
    dialog->show();
}

void EditNoticeDialog::SubmitSlot()
{
    if(!ui->textEdit->document()->isModified())
    {
        QMessageBox::information(this,"提示","您并没有修改任何内容！",tr("确定"));
    }
    else
    {
        int index = QMessageBox::information(this,"提示","您要保存操作吗？",QMessageBox::Yes|QMessageBox::No);
        if(index == QMessageBox::Yes)
        {
            QString StrData = ui->textEdit->toPlainText();          //获取输入框的内容并且转换为QString类型
            QFile file("通知.txt");                                  //设置文件名
            QTextCodec* codec=QTextCodec::codecForName("UTF-8");    //设置解码
            if(!file.open(QIODevice::ReadWrite))
             {
                qDebug()<<"文件打开失败";
                return;
             }

            qDebug()<<StrData;                                      //测试输入是否被正确解码
            QTextStream madan(&file);                               //关联文件流
            madan.setCodec(codec);                                  //设置编码
            madan << StrData;                                       //将字符串输入到文件
            file.flush();                                           //刷新缓冲区
            file.close();                                           //关闭文件

        }
        else if(index == QMessageBox::No)
        {
            qDebug()<<"您取消了保存操作";
        }
    }

}
