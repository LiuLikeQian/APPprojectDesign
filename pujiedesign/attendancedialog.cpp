#include "attendancedialog.h"
#include "ui_attendancedialog.h"

AttendanceDialog::AttendanceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AttendanceDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("���ڹ���");
    setMaximumSize(400,350);
    setMinimumSize(400,350);

    //ui->listWidget->setViewMode(QListView::IconMode);                             //��ʼ��ͼ����ʾ

    QIcon icon = QIcon(":/image/manage.ico");                                       //ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);              //ȥ�������ϵ��ʺ�
    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));   //���ز�
}

AttendanceDialog::~AttendanceDialog()
{
    delete ui;
}


void AttendanceDialog::ReturnSlot()         //�����ϼ���
{
    this->close();
    managesystem *dialog = new managesystem;
    dialog->show();
}
