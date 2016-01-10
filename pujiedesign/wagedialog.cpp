#include "wagedialog.h"
#include "ui_wagedialog.h"

WageDialog::WageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WageDialog)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setWindowTitle("工资查询");       //设置标题
    QIcon icon = QIcon(":/image/manage.ico");//注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(490,360);
    setMinimumSize(490,360);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));       //返回信号与槽
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
