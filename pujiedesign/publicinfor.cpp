#include "publicinfor.h"
#include "ui_publicinfor.h"

PublicInfor::PublicInfor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PublicInfor)
{
    ui->setupUi(this);
    this->setWindowTitle("公司公告");          //设置标题
    QIcon icon = QIcon(":/image/manage.ico");//注意修改这里的图片目录
    setWindowIcon(icon);
    setMaximumSize(495,400);
    setMinimumSize(495,400);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QObject::connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(OkSlot()));
    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));
}

PublicInfor::~PublicInfor()
{
    delete ui;
}
void PublicInfor::OkSlot()                    //确定槽
{

    if(ui->textEdit->document()->isModified())//简单判断文本是不是已经被修改
    {
        int tips =  QMessageBox::information(this,"公告","公告已修改，要立即启用吗？",QMessageBox :: Yes|QMessageBox :: No|QMessageBox :: Cancel);
                if(tips == QMessageBox::Yes)
                {

                    QString StrData = ui->textEdit->toPlainText();          //获取输入框的内容并且转换为QString类型
                    QFile file("公告.txt");                                  //设置文件名
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





                    this->close();
                    managesystem  *index = new managesystem; //回到上一层
                    index->show();
                }
                    else if(tips == QMessageBox :: No)
                    qDebug()<<"您取消了按钮";
                    else if(tips == QMessageBox :: Cancel)
                    qDebug()<<"您什么也不做";
    }
    else
    {
        QMessageBox::information(this,"提示","你没有做任何更改！！");
    }
}

void PublicInfor::ReturnSlot()               //返回槽
{
    this->close();
    managesystem  *index = new managesystem; //回到上一层
    index->show();
}
