#include "wagedialog.h"
#include "ui_wagedialog.h"

WageDialog::WageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WageDialog)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setWindowTitle("���ʲ�ѯ");       //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(490,360);
    setMinimumSize(490,360);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));       //�����ź����
}

WageDialog::~WageDialog()
{
    delete ui;
}

void WageDialog::ReturnSlot()
{
    this->close();
    managesystem *dialog = new managesystem;
    dialog->show();
}
