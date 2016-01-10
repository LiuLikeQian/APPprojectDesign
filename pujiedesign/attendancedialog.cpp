#include "attendancedialog.h"
#include "ui_attendancedialog.h"

AttendanceDialog::AttendanceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AttendanceDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("出勤管理");
    setMaximumSize(400,350);
    setMinimumSize(400,350);

    //ui->listWidget->setViewMode(QListView::IconMode);                             //初始化图标显示

    QIcon icon = QIcon(":/image/manage.ico");                                       //注意修改这里的图片目录
    setWindowIcon(icon);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);              //去掉窗口上的问号
    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));   //返回槽
}

AttendanceDialog::~AttendanceDialog()
{
    delete ui;
}


void AttendanceDialog::ReturnSlot()         //返回上级槽
{
    this->close();
    managesystem *dialog = new managesystem;
    dialog->show();
}
