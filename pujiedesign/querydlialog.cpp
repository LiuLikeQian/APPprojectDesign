#include "querydlialog.h"
#include "ui_querydlialog.h"

QueryDlialog::QueryDlialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDlialog)
{
    ui->setupUi(this);
    this->setWindowTitle("��ѯԱ����Ϣ");
}

QueryDlialog::~QueryDlialog()
{
    delete ui;
}
