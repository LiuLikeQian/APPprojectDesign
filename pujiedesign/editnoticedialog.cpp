#include "editnoticedialog.h"
#include "ui_editnoticedialog.h"

EditNoticeDialog::EditNoticeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditNoticeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("�༭֪ͨ");     //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));       //�����ź����
    QObject::connect(ui->SubmitButton,SIGNAL(clicked()),this,SLOT(SubmitSlot()));       //�ύ�ź����
}

EditNoticeDialog::~EditNoticeDialog()
{
    delete ui;
}


void EditNoticeDialog::ReturnSlot()
{
    this->close();
    InforDialog *dialog = new InforDialog;
    dialog->show();
}

void EditNoticeDialog::SubmitSlot()
{
    if(!ui->textEdit->document()->isModified())
    {
        QMessageBox::information(this,"��ʾ","����û���޸��κ����ݣ�",tr("ȷ��"));
    }
    else
    {
        int index = QMessageBox::information(this,"��ʾ","��Ҫ���������",QMessageBox::Yes|QMessageBox::No);
        if(index == QMessageBox::Yes)
        {
            QString StrData = ui->textEdit->toPlainText();          //��ȡ���������ݲ���ת��ΪQString����
            QFile file("֪ͨ.txt");                                  //�����ļ���
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

        }
        else if(index == QMessageBox::No)
        {
            qDebug()<<"��ȡ���˱������";
        }
    }

}
