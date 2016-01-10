#include "deletedialog.h"
#include "ui_deletedialog.h"

DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Ա������");
    setMaximumSize(430,380);
    setMinimumSize(430,380);

    ui->listWidget->setViewMode(QListView::IconMode);                              //��ʼ��ͼ����ʾ

    QIcon icon = QIcon(":/image/manage.ico");                                      //ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QObject::connect(ui->DeleteButton,SIGNAL(clicked()),this,SLOT(DeleteSlot()));  //ɾ���ź����
    QObject::connect(ui->DisPlayButton,SIGNAL(clicked()),this,SLOT(DisPlaySlot()));//��ʾ�ź����
    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));  //�����ź����

}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}
void DeleteDialog::DeleteSlot()
{
    QListWidgetItem * item = ui->listWidget->takeItem(ui->listWidget->currentRow());  //ͨ��listWidget��ͼ����䴰���ڵ���Ŀ(����)
    delete item;
}

void DeleteDialog::DisPlaySlot()                //��ʾԱ����Ϣ
{
    //���ڼ�������û������ǩ�����ͷ����ʾԱ������Ϣ����
    QMessageBox::information(this,"��","Ա��");
}


void DeleteDialog::ReturnSlot()                  //���ء��رյ�ǰ����
{
    this->close();
    managesystem  *index = new managesystem;    //�ص���һ��
    index->show();
}
