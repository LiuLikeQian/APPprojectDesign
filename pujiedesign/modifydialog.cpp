#include "modifydialog.h"
#include "ui_modifydialog.h"

ModifyDialog::ModifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("修改员工信息");          //设置标题
    QIcon icon = QIcon(":/image/manage.ico");    //注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(600,430);
    setMinimumSize(600,430);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    //ui->textEdit->setReadOnly(true);                                              //禁止显示员工信息的文本框输入信息

    QObject::connect(ui->SubmitButton,SIGNAL(clicked()),this,SLOT(SubmitSlot()));   //提交 槽
    QObject::connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));   //返回 槽
    QObject::connect(ui->DesignButton,SIGNAL(clicked()),this,SLOT(designSlot()));   //设置头像槽

    this->movie = new QMovie(":/image/wuji.png");                         //将movie实例化
    ui->photolabel->setMovie(this->movie);                                //窗口启动的时候图片作为窗口一样同时启动
    this->movie->start();

    QString index[20]={"王尼玛","男","1977-06-13","已婚","硕士","福建","350121198505134897","18068341579","福建省福州市闽侯县","工程师","网络工程师","2012-2018","休假","汉","中国共产党员","3131101164","0591-6731947","2010-08-08","暂无",};
    ui->NameEdit->setText(index[0]);        //姓名
    ui->SexEdit->setText(index[1]);         //性别
    ui->BrithdayEdit->setText(index[2]);    //出生日期
    ui->MerryEdit->setText(index[3]);       //婚姻
    ui->CultureEdit->setText(index[4]);     //文化程度
    ui->WhereEdit->setText(index[5]);       //籍贯
    ui->PersonNumberEdit->setText(index[6]);//身份证
    ui->TelEdit->setText(index[7]);         //手机
    ui->PlaceEdit->setText(index[8]);       //户籍
    ui->SituationEdit->setText(index[9]);   //岗位
    ui->PostEdit->setText(index[10]);       //职务
    ui->PeriodEdit->setText(index[11]);     //合同有效期
    ui->StateEdit->setText(index[12]);      //状态
    ui->NationEdit->setText(index[13]);     //民族
    ui->BackgroundEdit->setText(index[14]); //政治面貌
    ui->WorkNumEdit->setText(index[15]);    //员工号
    ui->WorkTelEdit->setText(index[16]);    //办公电话

    QDateTime time =  QDateTime::fromString(index[17], "yyyy-MM-dd");
    ui->ReachEdit->setTime(time.time());    //到港日期
    ui->OtherEdit->setText(index[18]);      //备注

    /*QString str = "你的字符串";
    ui->NameEdit->setText(str);*/

}

ModifyDialog::~ModifyDialog()
{
    delete ui;
}

void ModifyDialog::SubmitSlot()
{
    //做一个选择判断框
    //QString index[20] =


    int index = QMessageBox::information(this,"提示","确定要提交已经修改的资料？",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

            if(index == QMessageBox::Yes)
            {
                this->close();
                managesystem  *index = new managesystem; //回到上一层
                index->show();

            }
            else if(index == QMessageBox::No)
            {
                qDebug()<<"用户选择了No";
            }
            else if(index == QMessageBox::Cancel)
            {
                qDebug()<<"用户选择了Cancel";
            }
}

void ModifyDialog::ReturnSlot()
{
    this->close();
    managesystem  *index = new managesystem; //回到上一层
    index->show();
}


void ModifyDialog::designSlot()
{
    //静态方法创建/usr/local/Trolltech
    //QString index = QFileDialog::getOpenFileName("/home","Images (*.png *.xpm *.jpg)",this,"open file dialog","Choose a photo" );
    QString index = QFileDialog::getOpenFileName( this,tr("打开文件"),"/usr/local/Trolltech",tr("任何文件(*.*)"";;文本文件(*.txt)"";;XML文件(*.xml)"";;Images (*.png *.xpm *.jpg)"));
    this->movie = new QMovie(index);

    ui->photolabel->setMovie(this->movie);
    this->movie->start();
}
