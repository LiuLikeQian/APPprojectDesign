#include "employeedialog.h"
#include "ui_employeedialog.h"

EmployeeDialog::EmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("���¹���ϵͳ");     //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(540,440);
    setMinimumSize(540,440);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    ui->InForButton->setStyleSheet("QPushButton{border-image: url(:/image/֪ͨ.png);}"
    "QPushButton:hover{border-image: url(:/image/֪ͨss.png);}"
    "QPushButton:pressed{border-image: url(:/image/֪ͨs.png);}");

    ui->PersonalButton->setStyleSheet("QPushButton{border-image: url(:/image/������Ϣ.png);}"
    "QPushButton:hover{border-image: url(:/image/������Ϣss.png);}"
    "QPushButton:pressed{border-image: url(:/image/������Ϣs.png);}");

    ui->PublicButton->setStyleSheet("QPushButton{border-image: url(:/image/����.png);}"
    "QPushButton:hover{border-image: url(:/image/����ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/����s.png);}");

    ui->ExitButton->setStyleSheet("QPushButton{border-image: url(:/image/�˳�ϵͳ.png);}"
    "QPushButton:hover{border-image: url(:/image/�˳�ϵͳss.png);}"
    "QPushButton:pressed{border-image: url(:/image/�˳�ϵͳs.png);}");

    ui->ApplyButton->setStyleSheet("QPushButton{border-image: url(:/image/��ѵ����.png);}"
    "QPushButton:hover{border-image: url(:/image/��ѵ����ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/��ѵ����s.png);}");

    ui->ExplainButton->setStyleSheet("QPushButton{border-image: url(:/image/ʹ��˵��.png);}"
    "QPushButton:hover{border-image: url(:/image/ʹ��˵��ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/ʹ��˵��s.png);}");

    ui->AttendanceButton->setStyleSheet("QPushButton{border-image: url(:/image/���˳���.png);}"
    "QPushButton:hover{border-image: url(:/image/���˳���ss.png);}"
    "QPushButton:pressed{border-image: url(:/image/���˳���s.png);}");


    QObject::connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(close()));           //�˳�ϵͳ�ź����
    QObject::connect(ui->ExplainButton,SIGNAL(clicked()),this,SLOT(Explainslot()));  //ʹ��˵���ź����
    QObject::connect(ui->ApplyButton,SIGNAL(clicked()),this,SLOT(ApplySlot()));      //��ѵ�����ź����

    QObject::connect(ui->InForButton,SIGNAL(clicked()),this,SLOT(InForSlot()));      //֪ͨ�ź����
    QObject::connect(ui->PersonalButton,SIGNAL(clicked()),this,SLOT(PersonalSlot()));//������Ϣ�ź����
    QObject::connect(ui->PublicButton,SIGNAL(clicked()),this,SLOT(PublicSlot()));    //�����ź����
}

EmployeeDialog::~EmployeeDialog()
{
    delete ui;
}

void EmployeeDialog::Explainslot()  //ʹ��˵��
{
    Explain*dialog = new Explain;
    dialog->exec();                 //�����ʹ��������ǰ��
}

void EmployeeDialog::ApplySlot()
{
    int index = QMessageBox::information(this,"��ʾ","ȷ��Ҫ���뵱ǰ��˾����ѵ��",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if(index == QMessageBox::Yes)
    {
        QMessageBox::information(this,"��ʾ","���Ѿ��ύ����ѵ����");
    }

    else if(index == QMessageBox::No)
    {
        QMessageBox::information(this,"��ʾ","��ȡ������ѵ����",tr("ȷ��"));
    }
    else if(index == QMessageBox::Cancel)
    {
        qDebug()<<"��ȡ��������";
    }
}


void EmployeeDialog::InForSlot()            //֪ͨ
{
    this->close();
    InformationDialog *dialog = new InformationDialog;
    dialog->show();
}


void EmployeeDialog::PersonalSlot()         //������Ϣ
{
    this->close();
   // ModifyDialog*dialog = new ModifyDialog;
    MyInforDialog *dialog = new MyInforDialog;
    dialog->show();
}


void EmployeeDialog::PublicSlot()           //����
{
    this->close();
    MyPublicDialog*dialog = new MyPublicDialog;
    dialog->show();
}
