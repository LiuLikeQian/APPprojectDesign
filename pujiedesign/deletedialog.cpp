#include "deletedialog.h"
#include "ui_deletedialog.h"

DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("员工管理");
    setMaximumSize(430,380);
    setMinimumSize(430,380);

    ui->listWidget->setViewMode(QListView::IconMode);                              //初始化图标显示

    QIcon icon = QIcon(":/image/manage.ico");                                      //注意修改这里的图片目录
    setWindowIcon(icon);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QObject::connect(ui->DeleteButton,SIGNAL(clicked()),this,SLOT(DeleteSlot()));  //删除信号与槽
    QObject::connect(ui->DisPlayButton,SIGNAL(clicked()),this,SLOT(DisPlaySlot()));//显示信号与槽
    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));  //返回信号与曹

}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}
void DeleteDialog::DeleteSlot()
{
    QListWidgetItem * item = ui->listWidget->takeItem(ui->listWidget->currentRow());  //通过listWidget视图获得其窗口内的项目(单个)
    delete item;
}

void DeleteDialog::DisPlaySlot()                //显示员工信息
{
    //由于技术不足没有作标签，点击头像显示员工的信息！！
    QMessageBox::information(this,"　","员工");
}


void DeleteDialog::ReturnSlot()                  //返回、关闭当前窗口
{
    this->close();
    managesystem  *index = new managesystem;    //回到上一层
    index->show();
}
