#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->PassWordEdit->setEchoMode(QLineEdit::Password);//���ļ���



    //��ȡϵͳ���룬��������ĵ�ʱ�򲻻����룡���ǵð���ͷ�ļ�#include <QTextCodec>������ֵ����Ķ����������ˣ���
     QTextCodec *codec = QTextCodec::codecForName("System");       //��ȡϵͳ����
     QTextCodec::setCodecForLocale(codec);
     QTextCodec::setCodecForCStrings(codec);
     QTextCodec::setCodecForTr(codec);
    this->setWindowTitle("������Ϣ����ϵͳ");                         //���ñ���

    QIcon icon = QIcon(":/image/manage.ico");                      //ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(460,350);
    setMinimumSize(460,350);

    QRegExp Countdator("[1-9][0-9]{1,9}$");                        //ʹ��������ʽ�����˻�����ĸʲô�ģ�ֻ����Ա���ţ��޶�10λ
    QValidator *validator = new QRegExpValidator(Countdator,0);
    ui->comboBox->setValidator(validator);
    //ui->CountEdit->setValidator(validator);


    QRegExp PassWord("[A-Za-z0-9_]{6,15}");                        //ʹ��������ʽ�������������ַ���ʲô��(�޶�������ĸ)�������޶�15
    QValidator *Passvalidator = new QRegExpValidator(PassWord,0);
    ui->PassWordEdit->setValidator(Passvalidator);


    ui->MemberButton->setChecked(true);                            //Ĭ��Ա����ѡ��







    QObject ::connect(ui->LoadingButton,SIGNAL(clicked()),this,SLOT(LandingSlot()));            //��ť��¼���
    QObject ::connect(ui->Forgetlabel,SIGNAL(linkActivated(QString)),this,SLOT(openurlSLOt())); //�������룬���ⲿ�����ӣ�Ĭ��url��"�ٶ�һ��"��

    QObject ::connect(ui->PassWordEdit,SIGNAL(returnPressed()),this,SLOT(LandingSlot()));       //����Ĭ�ϻس���ť�ǵ�¼

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: LandingSlot()                               //��¼��
{
    int count=0,sum=0;
   QString stringBBQ = ui->comboBox->currentText();


    //QString Countindex = ui->CountEdit->text();
    QString Passindex  = ui->PassWordEdit->text();
    if(ui->ManageButton->isChecked())
    {
        if(stringBBQ.isEmpty())
        {
            QMessageBox::information(this,"tips","�������˺�");
        }
        else if(Passindex.isEmpty())
        {
            QMessageBox::information(this,"tips","����������");
        }
        //QMessageBox::information(this,"tips","����Ա��ѡ��");
        else if(Passindex == "3131101106"|stringBBQ=="3131101104"|stringBBQ=="3131101111"|stringBBQ=="3131101125")
        {
        this->close();                                         //�ر������򴰿�

        managesystemSlot();                                    //��ʾ����ϵͳ����
        }
        else
        {
            if(count<3)
            {
            QMessageBox::information(this,"tips","�������");
            }
            else
            {
                int examt =  QMessageBox::warning(this,"����","�������������������������Ժ����ԣ�",QMessageBox::Yes|QMessageBox::Cancel);
                if(examt == QMessageBox::Yes)
                    this->close();
                else
                    this->close();
            }

            count++;
        }
    }
    else if(ui->MemberButton->isChecked())
    {
        if(stringBBQ.isEmpty())
        {
            QMessageBox::information(this,"tips","�������˺�");
        }
        else if(Passindex.isEmpty())
        {
            QMessageBox::information(this,"tips","����������");
        }
        //QMessageBox::information(this,"tips","Ա����ѡ��");
        else if(Passindex == "3131101106"|stringBBQ=="3131101104"|stringBBQ=="3131101111"|stringBBQ=="3131101125")
        {
        this->close();                                         //�ر������򴰿�

        employeeSlot();                                    //��ʾ����ϵͳ����
        }
        else
        {
            if(sum<3)
            {
            QMessageBox::information(this,"tips","�������");
            }
            else
            {
              int text =  QMessageBox::warning(this,"����","�������������������������Ժ����ԣ�",QMessageBox::Yes|QMessageBox::Cancel);
              if(text == QMessageBox::Yes)
                  this->close();
              else
                  this->close();
            }
            sum++;
        }

    }

}

void MainWindow::managesystemSlot()                            //��ʾ�Ӵ��ڲ�
{

    managesystem *dialog = new managesystem;
    dialog->show();
}


void MainWindow::openurlSLOt()                                 //�򿪳����Ӳ�
{
    QDesktopServices::openUrl( QUrl("https://www.baidu.com/"));
}

void MainWindow::employeeSlot()
{
    EmployeeDialog *dialog = new EmployeeDialog;
    dialog->show();
}



