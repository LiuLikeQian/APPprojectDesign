#include "traindialog.h"
#include "ui_traindialog.h"


TrainDialog::TrainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainDialog)

{
    ui->setupUi(this);
    this->setWindowTitle("公司培训管理");       //设置标题
    QIcon icon = QIcon(":/image/manage.ico");//注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(495,400);
    setMinimumSize(495,400);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));   //返回信号与槽
    QObject::connect(ui->AddButton,SIGNAL(clicked()),this,SLOT(AddSlot()));         //添加信号与槽
    QObject::connect(ui->DeleteButton,SIGNAL(clicked()),this,SLOT(DeleteSlot()));   //删除信号与槽

}

TrainDialog::~TrainDialog()
{
    delete ui;
}
void TrainDialog::ReturnSlot()
{
    this->close();
    managesystem  *dialog = new managesystem; //回到上一层
    dialog->show();
}

void TrainDialog::AddSlot()
{
    //QFont font = ui->lineEdit->text();
    //font.setPixelSize(24);
    //QString index = font.toString();
    QString index = ui->lineEdit->text();             //获得文本中的内容，并以字符串返回到index中。
    QListWidgetItem * nimabo =  new QListWidgetItem;  //创建一个QListWidgetItem的对象
    nimabo->setText(index);                           //设置文本到QListWidgetItem

    ui->listWidget->addItem(index);                   //在ui的listWidget上也要添加相对应的内容

    ui->lineEdit->clear();                           //设置好之后把tetxEdit中的内容清空一下
}


void TrainDialog::DeleteSlot()
{
    QListWidgetItem * item = ui->listWidget->takeItem(ui->listWidget->currentRow());  //通过listWidget视图获得其窗口内的项目(单个)
    delete item;
}

