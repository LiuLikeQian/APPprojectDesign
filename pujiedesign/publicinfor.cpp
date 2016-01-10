#include "publicinfor.h"
#include "ui_publicinfor.h"

PublicInfor::PublicInfor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PublicInfor)
{
    ui->setupUi(this);
    this->setWindowTitle("��˾����");          //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);
    setMaximumSize(495,400);
    setMinimumSize(495,400);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QObject::connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(OkSlot()));
    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));
}

PublicInfor::~PublicInfor()
{
    delete ui;
}
void PublicInfor::OkSlot()                    //ȷ����
{

    if(ui->textEdit->document()->isModified())//���ж��ı��ǲ����Ѿ����޸�
    {
        int tips =  QMessageBox::information(this,"����","�������޸ģ�Ҫ����������",QMessageBox :: Yes|QMessageBox :: No|QMessageBox :: Cancel);
                if(tips == QMessageBox::Yes)
                {

                    QString StrData = ui->textEdit->toPlainText();          //��ȡ���������ݲ���ת��ΪQString����
                    QFile file("����.txt");                                  //�����ļ���
                    QTextCodec* codec=QTextCodec::codecForName("UTF-8");    //���ý���
                    if(!file.open(QIODevice::ReadWrite))
                     {
                        qDebug()<<"�ļ���ʧ��";
                        return;
                     }

                    qDebug()<<StrData;                                      //���������Ƿ���ȷ����
                    QTextStream madan(&file);                               //�����ļ���
                    madan.setCodec(codec);                                  //���ñ���
                    madan << StrData;                                       //���ַ������뵽�ļ�
                    file.flush();                                           //ˢ�»�����
                    file.close();                                           //�ر��ļ�





                    this->close();
                    managesystem  *index = new managesystem; //�ص���һ��
                    index->show();
                }
                    else if(tips == QMessageBox :: No)
                    qDebug()<<"��ȡ���˰�ť";
                    else if(tips == QMessageBox :: Cancel)
                    qDebug()<<"��ʲôҲ����";
    }
    else
    {
        QMessageBox::information(this,"��ʾ","��û�����κθ��ģ���");
    }
}

void PublicInfor::ReturnSlot()               //���ز�
{
    this->close();
    managesystem  *index = new managesystem; //�ص���һ��
    index->show();
}
