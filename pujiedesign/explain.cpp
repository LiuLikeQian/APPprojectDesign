#include "explain.h"
#include "ui_explain.h"

Explain::Explain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Explain)
{
    ui->setupUi(this);
    this->setWindowTitle("ʹ��˵��");       //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");//ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(400,300);
    setMinimumSize(400,300);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

}

Explain::~Explain()
{
    delete ui;
}
