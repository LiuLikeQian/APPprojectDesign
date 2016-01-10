#include "employeedialog.h"
#include "ui_employeedialog.h"

EmployeeDialog::EmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("人事管理系统");     //设置标题
    QIcon icon = QIcon(":/image/manage.ico");//注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(540,440);
    setMinimumSize(540,440);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    ui->InForButton->setStyleSheet("QPushButton{border-image: url(:/image/通知.png);}"
    "QPushButton:hover{border-image: url(:/image/通知ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/通知s.png);}");

    ui->PersonalButton->setStyleSheet("QPushButton{border-image: url(:/image/个人信息.png);}"
    "QPushButton:hover{border-image: url(:/image/个人信息ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/个人信息s.png);}");

    ui->PublicButton->setStyleSheet("QPushButton{border-image: url(:/image/公告.png);}"
    "QPushButton:hover{border-image: url(:/image/公告ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/公告s.png);}");

    ui->ExitButton->setStyleSheet("QPushButton{border-image: url(:/image/退出系统.png);}"
    "QPushButton:hover{border-image: url(:/image/退出系统ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/退出系统s.png);}");

    ui->ApplyButton->setStyleSheet("QPushButton{border-image: url(:/image/培训申请.png);}"
    "QPushButton:hover{border-image: url(:/image/培训申请ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/培训申请s.png);}");

    ui->ExplainButton->setStyleSheet("QPushButton{border-image: url(:/image/使用说明.png);}"
    "QPushButton:hover{border-image: url(:/image/使用说明ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/使用说明s.png);}");

    ui->AttendanceButton->setStyleSheet("QPushButton{border-image: url(:/image/个人出勤.png);}"
    "QPushButton:hover{border-image: url(:/image/个人出勤ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/个人出勤s.png);}");


    QObject::connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(close()));           //退出系统信号与槽
    QObject::connect(ui->ExplainButton,SIGNAL(clicked()),this,SLOT(Explainslot()));  //使用说明信号与槽
    QObject::connect(ui->ApplyButton,SIGNAL(clicked()),this,SLOT(ApplySlot()));      //培训申请信号与槽

    QObject::connect(ui->InForButton,SIGNAL(clicked()),this,SLOT(InForSlot()));      //通知信号与槽
    QObject::connect(ui->PersonalButton,SIGNAL(clicked()),this,SLOT(PersonalSlot()));//个人信息信号与槽
    QObject::connect(ui->PublicButton,SIGNAL(clicked()),this,SLOT(PublicSlot()));    //公告信号与槽
}

EmployeeDialog::~EmployeeDialog()
{
    delete ui;
}

void EmployeeDialog::Explainslot()  //使用说明
{
    Explain*dialog = new Explain;
    dialog->exec();                 //这个会使窗口在最前面
}

void EmployeeDialog::ApplySlot()
{
    int index = QMessageBox::information(this,"提示","确定要申请当前公司的培训吗？",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if(index == QMessageBox::Yes)
    {
        QMessageBox::information(this,"提示","您已经提交了培训申请");
    }

    else if(index == QMessageBox::No)
    {
        QMessageBox::information(this,"提示","您取消了培训申请",tr("确定"));
    }
    else if(index == QMessageBox::Cancel)
    {
        qDebug()<<"您取消了请求";
    }
}


void EmployeeDialog::InForSlot()            //通知
{
    this->close();
    InformationDialog *dialog = new InformationDialog;
    dialog->show();
}


void EmployeeDialog::PersonalSlot()         //个人信息
{
    this->close();
   // ModifyDialog*dialog = new ModifyDialog;
    MyInforDialog *dialog = new MyInforDialog;
    dialog->show();
}


void EmployeeDialog::PublicSlot()           //公告
{
    this->close();
    MyPublicDialog*dialog = new MyPublicDialog;
    dialog->show();
}
