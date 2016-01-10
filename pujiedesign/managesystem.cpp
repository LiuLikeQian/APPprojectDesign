#include "managesystem.h"


managesystem::managesystem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managesystem)
{
    ui->setupUi(this);

    this->setWindowTitle("���¹���ϵͳ");     //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(570,440);
    setMinimumSize(570,440);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    ui->AddButton->setStyleSheet("QPushButton{border-image: url(:/image/����Ա��.png);}"
    "QPushButton:hover{border-image: url(:/image/����Ա��ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/����Ա��s.png);}");

    ui->DeleteButton->setStyleSheet("QPushButton{border-image: url(:/image/ɾ��Ա��.png);}"
    "QPushButton:hover{border-image: url(:/image/ɾ��Ա��ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/ɾ��Ա��s.png);}");

    ui->QueryButton->setStyleSheet("QPushButton{border-image: url(:/image/Ա����Ϣ��ѯ.png);}"
    "QPushButton:hover{border-image: url(:/image/Ա����Ϣ��ѯss.png);}"
    "QPushButton:pressed{border-image: url(:/image/Ա����Ϣ��ѯs.png);}");

    ui->ModifyButton->setStyleSheet("QPushButton{border-image: url(:/image/�޸���Ϣ.png);}"
    "QPushButton:hover{border-image: url(:/image/�޸���Ϣss.png);}"
    "QPushButton:pressed{border-image: url(:/image/�޸���Ϣs.png);}");

    ui->WageButton->setStyleSheet("QPushButton{border-image: url(:/image/������Ϣ.png);}"
    "QPushButton:hover{border-image: url(:/image/������Ϣss.png);}"
    "QPushButton:pressed{border-image: url(:/image/������Ϣs.png);}");

    ui->PublicButton->setStyleSheet("QPushButton{border-image: url(:/image/����.png);}"
    "QPushButton:hover{border-image: url(:/image/����ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/����s.png);}");

    ui->ExitButton->setStyleSheet("QPushButton{border-image: url(:/image/�˳�ϵͳ.png);}"
    "QPushButton:hover{border-image: url(:/image/�˳�ϵͳss.png);}"
    "QPushButton:pressed{border-image: url(:/image/�˳�ϵͳs.png);}");

    ui->InforButton->setStyleSheet("QPushButton{border-image: url(:/image/����֪ͨ.png);}"
    "QPushButton:hover{border-image: url(:/image/����֪ͨss.png);}"
    "QPushButton:pressed{border-image: url(:/image/����֪ͨs.png);}");

    ui->TrainButton->setStyleSheet("QPushButton{border-image: url(:/image/��ѵ����.png);}"
    "QPushButton:hover{border-image: url(:/image/��ѵ����ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/��ѵ����s.png);}");

    ui->AttendanceButton->setStyleSheet("QPushButton{border-image: url(:/image/�������.png);}"
    "QPushButton:hover{border-image: url(:/image/�������ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/�������s.png);}");

    ui->ExplainButton->setStyleSheet("QPushButton{border-image: url(:/image/ʹ��˵��.png);}"
    "QPushButton:hover{border-image: url(:/image/ʹ��˵��ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/ʹ��˵��s.png);}");



    QObject::connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(close()));          //�˳�ϵͳ��
    QObject::connect(ui->AddButton,SIGNAL(clicked()),this,SLOT(managesAddSlot()));  //����Ա����
    QObject::connect(ui->ExplainButton,SIGNAL(clicked()),this,SLOT(ExplainSlot())); //ʹ��˵����
    QObject::connect(ui->PublicButton,SIGNAL(clicked()),this,SLOT(PublicSlot()));   //�����
    QObject::connect(ui->QueryButton,SIGNAL(clicked()),this,SLOT(QuerySlot()));     //��ѯԱ����
    QObject::connect(ui->DeleteButton,SIGNAL(clicked()),this,SLOT(DeleteSlot()));   //ɾ��Ա����
    QObject::connect(ui->ModifyButton,SIGNAL(clicked()),this,SLOT(ModifySlot()));   //�޸�Ա����
    QObject::connect(ui->TrainButton,SIGNAL(clicked()),this,SLOT(TrainSlot()));     //��ѵ�ź����
    QObject::connect(ui->InforButton,SIGNAL(clicked()),this,SLOT(InforSlot()));     //֪ͨ�ź����
    QObject::connect(ui->WageButton,SIGNAL(clicked()),this,SLOT(WageSlot()));       //�����ź����
    QObject::connect(ui->AttendanceButton,SIGNAL(clicked()),this,SLOT(AttendanceSlot()));//�����ź����


}

managesystem::~managesystem()
{
    delete ui;
}

/*void managesystem :: closeEvent(QCloseEvent* event)       //��ֹ�����
{
    int index = QMessageBox::information(this,"��ʾ","Ҫ�˳�������",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

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

void managesystem ::AddSlot()                 //����Ա��
{
    this->close();                            //���������򴰿�

    managesAddSlot();                         //��ʾ����ϵͳ����
}*/

void managesystem :: managesAddSlot()         //���� ��ʾ����Ա���Ӵ���
{
  this->close();
  managesAdd  *dialog = new managesAdd;
  dialog->show();
}

void managesystem ::DeleteSlot()              //ɾ��ɾ��
{
    this->close();
    DeleteDialog *dialog = new DeleteDialog;
    dialog->show();
}

void managesystem ::InforSlot()               //��Ϣ֪ͨ
{
    this->close();
    InforDialog*dialog = new InforDialog;
    dialog->show();

}

void managesystem ::PublicSlot()              //���� ��ʾ���洰��
{
    this->close();
    PublicInfor *dialog = new PublicInfor;
    dialog->show();
}

void managesystem ::ExplainSlot()             //ʹ��˵�� ��ʾ�Ӵ���
{
    Explain *dialog = new Explain;
    dialog->exec();
}

void managesystem :: TrainSlot()              //��ѵ����
{
    this->close();
    TrainDialog *dialog = new TrainDialog;
    dialog->show();
}

void managesystem ::ModifySlot()              //�޸�Ա��
{
    this->close();
    SearchEmployeeDialog *dialog = new SearchEmployeeDialog;
    dialog->show();

}

void managesystem ::QuerySlot()               //��ѯԱ�� ����ʾ�Ӵ���
{
    this->close();
    QueryDialog *dialog = new QueryDialog;
    dialog->show();
}

void managesystem::WageSlot()                 //���ʲ鿴
{
    this->close();
    WageDialog *dialog = new WageDialog;
    dialog->show();
}

void managesystem::AttendanceSlot()           //���ڹ���
{
    this->close();
    AttendanceDialog *dialog = new AttendanceDialog;
    dialog->show();
}
