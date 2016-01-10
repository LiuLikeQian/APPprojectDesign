#include "mypublicdialog.h"
#include "ui_mypublicdialog.h"

MyPublicDialog::MyPublicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyPublicDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("����");     //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QTextCodec* codec=QTextCodec::codecForName("UTF-8");    //���ý���

    QFile file("����.txt");                      //·���������һ����= =
     ui->textEdit->clear();                     //��֮ǰ��textedit�ı����
     if(file.open(QIODevice::ReadOnly))         //�ж��ı��ǲ�����ֻ����ʽ��
        {
        QTextStream read(&file);                //��txt�������ı���
         read.setCodec(codec);                  //���ñ���,Ҫô���Ķ���������
         while(!read.atEnd() )                  //һ��һ�е�д��textEdit����
         {
          ui->textEdit->append(read.readLine());
          }
        }
     file.close();


     QObject::connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(OkSlot()));      //ȷ���ź����
}

MyPublicDialog::~MyPublicDialog()
{
    delete ui;
}

void MyPublicDialog::OkSlot()
{
    this->close();
    EmployeeDialog *dialog = new EmployeeDialog;
    dialog->show();
}
