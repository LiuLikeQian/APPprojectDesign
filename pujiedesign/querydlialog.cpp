#include "querydlialog.h"
#include "ui_querydlialog.h"

QueryDlialog::QueryDlialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDlialog)
{
    ui->setupUi(this);
    this->setWindowTitle("查询员工信息");
}

QueryDlialog::~QueryDlialog()
{
    delete ui;
}
