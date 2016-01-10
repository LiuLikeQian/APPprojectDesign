#include "managesadd.h"
#include "ui_managesadd.h"

managesAdd::managesAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managesAdd)
{
    ui->setupUi(this);
    this->setWindowTitle("����Ա��");             //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");    //ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(600,430);
    setMinimumSize(600,430);

    //ui->textEdit->setReadOnly(true);                                                    //��ֹ��ʾԱ����Ϣ���ı���������Ϣ


    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QObject ::connect(ui->SubmitButton,SIGNAL(clicked()),this,SLOT(SubmitSlot()));  //�ύ ��ť���
    QObject ::connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(CancelSlot()));  //ȡ�� ��ť���

    QObject ::connect(ui->DesignButton,SIGNAL(clicked()),this,SLOT(DesignSlot()));  //����ͷ�� ��ť���
}

managesAdd::~managesAdd()
{
    delete ui;
}

void managesAdd::SubmitSlot()                                   //���ӳ�Ա�Ӵ���  �ύ��ť
{
    QString Nameindex = ui->NameEdit->text();                   //����
    QString Setindex = ui->SexEdit->text();                     //�Ա�
    QString Cultureindex = ui->CultureEdit->text();             //�Ļ��̶�
    QString PersonNumberindex = ui->PersonNumberEdit->text();   //���֤����
    QString Periodindex = ui->PeriodEdit->text();               //��ͬ����
    QString WorkNumindex = ui->WorkNumEdit->text();             //Ա����
    QString Stateindex =  ui->StateEdit->text();                //Ա��״̬
    QString Palceindex =  ui->PlaceEdit->text();                //�������ڵ�

    if(Nameindex.isEmpty())                                     //�жϻ�����Ϣ��û������û�еĻ������ύ
    {
        QMessageBox::information(this,"��ʾ","������������");
    }
        else if(Setindex.isEmpty())
    {
        QMessageBox::information(this,"��ʾ","�������Ա�");
    }
        else if(Cultureindex.isEmpty())
    {
        QMessageBox::information(this,"��ʾ","�������Ļ��̶ȣ�");
    }
        else if(PersonNumberindex.isEmpty())
    {
        QMessageBox::information(this,"��ʾ","���������֤���룡");
    }
        else if(Periodindex.isEmpty())
    {
        QMessageBox::information(this,"��ʾ","�������Լ���ޣ�");
    }
        else if(WorkNumindex.isEmpty())
    {
        QMessageBox::information(this,"��ʾ","������Ա���ţ�");
    }
        else if(Stateindex.isEmpty())
    {
        QMessageBox::information(this,"��ʾ","������Ա��״̬��");
    }
        else if(Palceindex.isEmpty())
    {
        QMessageBox::information(this,"��ʾ","������Ա���������ڵأ�");
    }
    else
    {
    this->close();                           //�ر��Ӵ���
    managesystem  *index = new managesystem; //�ص���һ��
    index->show();
}
}


void managesAdd::CancelSlot()                //���ӳ�Ա�Ӵ���  ȡ����ť
{
    this->close();                           //�ر��Ӵ���
    managesystem  *index = new managesystem; //�ص���һ��
    index->show();
}

void managesAdd::DesignSlot()
{
    ///usr/local/Trolltech
    QString index = QFileDialog::getOpenFileName( this,tr("���ļ�"),"/usr/local/Trolltech",tr("�κ��ļ�(*.*)"";;�ı��ļ�(*.txt)"";;XML�ļ�(*.xml)"";;Images (*.png *.xpm *.jpg)"));
    this->movie = new QMovie(index);

    ui->photolabel->setMovie(this->movie);
    this->movie->start();
}
