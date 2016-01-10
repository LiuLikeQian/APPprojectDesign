#include "informationdialog.h"
#include "ui_informationdialog.h"

InformationDialog::InformationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformationDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("通知");             //设置标题
    QIcon icon = QIcon(":/image/manage.ico");//注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(460,370);
    setMinimumSize(460,370);

    ui->textEdit->setReadOnly(true);            //禁止显示员工信息的文本框输入信息

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QTextCodec* codec=QTextCodec::codecForName("UTF-8");    //设置解码
    QFile file("通知.txt");                      //路径错误搞了一下午= =
     ui->textEdit->clear();                     //打开之前把textedit文本清空
     if(file.open(QIODevice::ReadOnly))         //判断文本是不是以只读形式打开
        {
        QTextStream read(&file);                //将txt关联到文本流
         read.setCodec(codec);                  //设置编码,要么中文读出来乱码
         while(!read.atEnd() )                  //一行一行的写到textEdit上面
         {
          ui->textEdit->append(read.readLine());
          }
        }
     file.close();



    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));   //返回信号与槽

}

InformationDialog::~InformationDialog()
{
    delete ui;
}

void InformationDialog::ReturnSlot()
{
    this->close();
    EmployeeDialog *dialog = new EmployeeDialog;
    dialog->show();
}
