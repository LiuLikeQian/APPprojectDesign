#include "searchemployeedialog.h"
#include "ui_searchemployeedialog.h"


SearchEmployeeDialog::SearchEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchEmployeeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Ա����Ϣ�޸�");
    QIcon icon = QIcon(":/image/manage.ico");                      //ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(350,250);
    setMinimumSize(350,250);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    QRegExp Countdator("[1-9][0-9]{1,9}$");                        //ʹ��������ʽ�����˻�����ĸʲô�ģ�ֻ����Ա���ţ��޶�10λ
    QValidator *validator = new QRegExpValidator(Countdator,0);
    ui->lineEdit->setValidator(validator);

    QObject::connect(ui->SearchAdultButton,SIGNAL(clicked()),this,SLOT(SearchEmployeeSlot()));//������
    QObject::connect(ui->GoHomeButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));             //���ز�

}

SearchEmployeeDialog::~SearchEmployeeDialog()
{
    delete ui;
}

void SearchEmployeeDialog::SearchEmployeeSlot()
{
    QString index = ui->lineEdit->text();
    if(index.isEmpty())
    {
        QMessageBox::information(this,"����","������Ա���ţ�");
    }
    else
    {
        this->close();
        ModifyDialog *dialog = new ModifyDialog;
        dialog->show();

    }
}
void SearchEmployeeDialog::ReturnSlot()
{

    this->close();
    managesystem  *index = new managesystem; //�ص���һ��
    index->show();

}
