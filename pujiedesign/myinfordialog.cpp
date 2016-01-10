#include "myinfordialog.h"
#include "ui_myinfordialog.h"

MyInforDialog::MyInforDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyInforDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("个人信息");          //设置标题
    QIcon icon = QIcon(":/image/manage.ico");    //注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(600,430);
    setMinimumSize(600,430);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

    this->movie = new QMovie(":/image/zhangsa.png");                         //将movie实例化
    ui->photolabel_4->setMovie(this->movie);                                //窗口启动的时候图片作为窗口一样同时启动
    this->movie->start();

    QString index[20]={"李白","男","1980-05-13","未婚","硕士","安徽","350121198505134897","15668151579","安徽省阜阳","工程师","网络测试师","2012-2018","病假","汉","中国共产党员","3131101164","0591-6731947","2010-08-08","暂无",};
    ui->NameEdit_2->setText(index[0]);        //姓名
    ui->SexEdit_2->setText(index[1]);         //性别
    ui->BrithdayEdit_2->setText(index[2]);    //出生日期
    ui->MerryEdit_2->setText(index[3]);       //婚姻
    ui->CultureEdit_2->setText(index[4]);     //文化程度
    ui->WhereEdit_2->setText(index[5]);       //籍贯
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


    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));       //返回信号与槽
}

MyInforDialog::~MyInforDialog()
{
    delete ui;
}

void MyInforDialog::ReturnSlot()
{
    this->close();
    EmployeeDialog *dialog = new EmployeeDialog; //回到上一层
    dialog->show();
}
