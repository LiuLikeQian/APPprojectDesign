#include "querydialog.h"
#include "ui_querydialog.h"
#include <QIODevice>

QueryDialog::QueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("��ѯԱ��");
    QIcon icon = QIcon(":/image/manage.ico");                      //ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QRegExp Countdator("[1-9][0-9]{1,9}$");                        //ʹ��������ʽ����Ա��������ĸʲô�ģ�ֻ����Ա���ţ��޶�10λ
    QValidator *validator = new QRegExpValidator(Countdator,0);
    ui->lineEdit->setValidator(validator);

    setMaximumSize(550,430);
    setMinimumSize(550,430);

    ui->textEdit->setReadOnly(true);                                                    //��ֹ��ʾԱ����Ϣ���ı���������Ϣ

    QObject ::connect(ui->SeachButton,SIGNAL(clicked()),this,SLOT(PersonNumSlot()));    //����Ա���Ų�
    QObject ::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));      //���ز�
    QObject ::connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(PersonNumSlot())); //����Ĭ�ϻس���ť������
}

QueryDialog::~QueryDialog()
{
    delete ui;
}


void QueryDialog::PersonNumSlot()
{
    QFile file(":/information.txt");            //·���������һ����= =
     ui->textEdit->clear();                     //��֮ǰ��textedit�ı����
     if(file.open(QIODevice::ReadOnly))         //�ж��ı��ǲ�����ֻ����ʽ��
        {
        QTextStream read(&file);                //��txt�������ı���

         while(!read.atEnd() )                  //һ��һ�е�д��textEdit����
         {
          ui->textEdit->append(read.readLine());
          }
        }
     file.close();
}


void QueryDialog::ReturnSlot()                  //���ء��رյ�ǰ����
{
    this->close();
    managesystem  *dialog = new managesystem; //�ص���һ��
    dialog->show();
}
