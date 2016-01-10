#include "traindialog.h"
#include "ui_traindialog.h"


TrainDialog::TrainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainDialog)

{
    ui->setupUi(this);
    this->setWindowTitle("��˾��ѵ����");       //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(495,400);
    setMinimumSize(495,400);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));   //�����ź����
    QObject::connect(ui->AddButton,SIGNAL(clicked()),this,SLOT(AddSlot()));         //����ź����
    QObject::connect(ui->DeleteButton,SIGNAL(clicked()),this,SLOT(DeleteSlot()));   //ɾ���ź����

}

TrainDialog::~TrainDialog()
{
    delete ui;
}
void TrainDialog::ReturnSlot()
{
    this->close();
    managesystem  *dialog = new managesystem; //�ص���һ��
    dialog->show();
}

void TrainDialog::AddSlot()
{
    //QFont font = ui->lineEdit->text();
    //font.setPixelSize(24);
    //QString index = font.toString();
    QString index = ui->lineEdit->text();             //����ı��е����ݣ������ַ������ص�index�С�
    QListWidgetItem * nimabo =  new QListWidgetItem;  //����һ��QListWidgetItem�Ķ���
    nimabo->setText(index);                           //�����ı���QListWidgetItem

    ui->listWidget->addItem(index);                   //��ui��listWidget��ҲҪ������Ӧ������

    ui->lineEdit->clear();                           //���ú�֮���tetxEdit�е��������һ��
}


void TrainDialog::DeleteSlot()
{
    QListWidgetItem * item = ui->listWidget->takeItem(ui->listWidget->currentRow());  //ͨ��listWidget��ͼ����䴰���ڵ���Ŀ(����)
    delete item;
}

