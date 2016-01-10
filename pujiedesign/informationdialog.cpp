#include "informationdialog.h"
#include "ui_informationdialog.h"

InformationDialog::InformationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformationDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("֪ͨ");             //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(460,370);
    setMinimumSize(460,370);

    ui->textEdit->setReadOnly(true);            //��ֹ��ʾԱ����Ϣ���ı���������Ϣ

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QTextCodec* codec=QTextCodec::codecForName("UTF-8");    //���ý���
    QFile file("֪ͨ.txt");                      //·���������һ����= =
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



    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));   //�����ź����

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
