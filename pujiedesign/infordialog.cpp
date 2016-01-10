#include "infordialog.h"
#include "ui_infordialog.h"

InforDialog::InforDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InforDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("��˾֪ͨ");       //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(495,400);
    setMinimumSize(495,400);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));       //�����ź����
    QObject::connect(ui->EditInforButton,SIGNAL(clicked()),this,SLOT(EditNoticeSlot()));//�༭�ź����
    QObject::connect(ui->SingleInforButton,SIGNAL(clicked()),this,SLOT(SingleInforSlot()));//����֪ͨ�ź����
    QObject::connect(ui->AllInforButton,SIGNAL(clicked()),this,SLOT(AllSlot()));        //ȫ��֪ͨ�ź����
}

InforDialog::~InforDialog()
{
    delete ui;
}
void InforDialog::ReturnSlot()
{
    this->close();
    managesystem  *dialog = new managesystem; //�ص���һ��
    dialog->show();
}


void InforDialog::EditNoticeSlot()
{
    this->close();
    EditNoticeDialog*dialog = new EditNoticeDialog;
    dialog->show();
}

void InforDialog::SingleInforSlot()
{
    QMessageBox::information(this,"��ʾ","֪ͨ�ѷ��ͣ�",tr("ȷ��"));
}

void InforDialog::AllSlot()
{
    int index = QMessageBox::information(this,"��ʾ","Ҫȫ�巢��֪ͨ��",QMessageBox::Yes|QMessageBox::No);
     if(index ==QMessageBox::Yes)
     {
         QMessageBox::information(this,"��ʾ","��Ϣ�ѷ��ͣ�",tr("ȷ��"));
            }
      else if(index ==QMessageBox::No)
     {
         qDebug()<<"��ȡ����ȫ�巢��֪ͨ";
            }
}
