#include "managesystem.h"


managesystem::managesystem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managesystem)
{
    ui->setupUi(this);

    this->setWindowTitle("人事管理系统");     //设置标题
    QIcon icon = QIcon(":/image/manage.ico");//注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(570,440);
    setMinimumSize(570,440);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    ui->AddButton->setStyleSheet("QPushButton{border-image: url(:/image/增加员工.png);}"
    "QPushButton:hover{border-image: url(:/image/增加员工ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/增加员工s.png);}");

    ui->DeleteButton->setStyleSheet("QPushButton{border-image: url(:/image/删除员工.png);}"
    "QPushButton:hover{border-image: url(:/image/删除员工ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/删除员工s.png);}");

    ui->QueryButton->setStyleSheet("QPushButton{border-image: url(:/image/员工信息查询.png);}"
    "QPushButton:hover{border-image: url(:/image/员工信息查询ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/员工信息查询s.png);}");

    ui->ModifyButton->setStyleSheet("QPushButton{border-image: url(:/image/修改信息.png);}"
    "QPushButton:hover{border-image: url(:/image/修改信息ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/修改信息s.png);}");

    ui->WageButton->setStyleSheet("QPushButton{border-image: url(:/image/工资信息.png);}"
    "QPushButton:hover{border-image: url(:/image/工资信息ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/工资信息s.png);}");

    ui->PublicButton->setStyleSheet("QPushButton{border-image: url(:/image/公告.png);}"
    "QPushButton:hover{border-image: url(:/image/公告ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/公告s.png);}");

    ui->ExitButton->setStyleSheet("QPushButton{border-image: url(:/image/退出系统.png);}"
    "QPushButton:hover{border-image: url(:/image/退出系统ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/退出系统s.png);}");

    ui->InforButton->setStyleSheet("QPushButton{border-image: url(:/image/发送通知.png);}"
    "QPushButton:hover{border-image: url(:/image/发送通知ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/发送通知s.png);}");

    ui->TrainButton->setStyleSheet("QPushButton{border-image: url(:/image/培训管理.png);}"
    "QPushButton:hover{border-image: url(:/image/培训管理ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/培训管理s.png);}");

    ui->AttendanceButton->setStyleSheet("QPushButton{border-image: url(:/image/出勤审查.png);}"
    "QPushButton:hover{border-image: url(:/image/出勤审查ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/出勤审查s.png);}");

    ui->ExplainButton->setStyleSheet("QPushButton{border-image: url(:/image/使用说明.png);}"
    "QPushButton:hover{border-image: url(:/image/使用说明ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/使用说明s.png);}");



    QObject::connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(close()));          //退出系统槽
    QObject::connect(ui->AddButton,SIGNAL(clicked()),this,SLOT(managesAddSlot()));  //增加员工槽
    QObject::connect(ui->ExplainButton,SIGNAL(clicked()),this,SLOT(ExplainSlot())); //使用说明槽
    QObject::connect(ui->PublicButton,SIGNAL(clicked()),this,SLOT(PublicSlot()));   //公告槽
    QObject::connect(ui->QueryButton,SIGNAL(clicked()),this,SLOT(QuerySlot()));     //查询员工槽
    QObject::connect(ui->DeleteButton,SIGNAL(clicked()),this,SLOT(DeleteSlot()));   //删除员工槽
    QObject::connect(ui->ModifyButton,SIGNAL(clicked()),this,SLOT(ModifySlot()));   //修改员工槽
    QObject::connect(ui->TrainButton,SIGNAL(clicked()),this,SLOT(TrainSlot()));     //培训信号与槽
    QObject::connect(ui->InforButton,SIGNAL(clicked()),this,SLOT(InforSlot()));     //通知信号与槽
    QObject::connect(ui->WageButton,SIGNAL(clicked()),this,SLOT(WageSlot()));       //工资信号与槽
    QObject::connect(ui->AttendanceButton,SIGNAL(clicked()),this,SLOT(AttendanceSlot()));//出勤信号与槽


}

managesystem::~managesystem()
{
    delete ui;
}

/*void managesystem :: closeEvent(QCloseEvent* event)       //防止误操作
{
    int index = QMessageBox::information(this,"提示","要退出程序吗？",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

            if(index == QMessageBox::Yes)
            {
                this->close();
            }
            else if(index == QMessageBox::No)
            {
                event->ignore();
            }
            else if(index == QMessageBox::Cancel)
            {
                event->ignore();
            }

}

void managesystem ::AddSlot()                 //增加员工
{
    this->close();                            //隐藏主程序窗口

    managesAddSlot();                         //显示管理系统界面
}*/

void managesystem :: managesAddSlot()         //增加 显示增加员工子窗口
{
  this->close();
  managesAdd  *dialog = new managesAdd;
  dialog->show();
}

void managesystem ::DeleteSlot()              //删除删除
{
    this->close();
    DeleteDialog *dialog = new DeleteDialog;
    dialog->show();
}

void managesystem ::InforSlot()               //消息通知
{
    this->close();
    InforDialog*dialog = new InforDialog;
    dialog->show();

}

void managesystem ::PublicSlot()              //公告 显示公告窗口
{
    this->close();
    PublicInfor *dialog = new PublicInfor;
    dialog->show();
}

void managesystem ::ExplainSlot()             //使用说明 显示子窗口
{
    Explain *dialog = new Explain;
    dialog->exec();
}

void managesystem :: TrainSlot()              //培训管理
{
    this->close();
    TrainDialog *dialog = new TrainDialog;
    dialog->show();
}

void managesystem ::ModifySlot()              //修改员工
{
    this->close();
    SearchEmployeeDialog *dialog = new SearchEmployeeDialog;
    dialog->show();

}

void managesystem ::QuerySlot()               //查询员工 并显示子窗口
{
    this->close();
    QueryDialog *dialog = new QueryDialog;
    dialog->show();
}

void managesystem::WageSlot()                 //工资查看
{
    this->close();
    WageDialog *dialog = new WageDialog;
    dialog->show();
}

void managesystem::AttendanceSlot()           //出勤管理
{
    this->close();
    AttendanceDialog *dialog = new AttendanceDialog;
    dialog->show();
}
