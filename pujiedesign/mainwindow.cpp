#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->PassWordEdit->setEchoMode(QLineEdit::Password);//明文加密



    //获取系统编码，当输出中文的时候不会乱码！！记得包含头文件#include <QTextCodec>后面出现的中文都不会乱码了！！
     QTextCodec *codec = QTextCodec::codecForName("System");       //获取系统编码
     QTextCodec::setCodecForLocale(codec);
     QTextCodec::setCodecForCStrings(codec);
     QTextCodec::setCodecForTr(codec);
    this->setWindowTitle("人事信息管理系统");                         //设置标题

    QIcon icon = QIcon(":/image/manage.ico");                      //注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(460,350);
    setMinimumSize(460,350);

    QRegExp Countdator("[1-9][0-9]{1,9}$");                        //使用正则表达式过滤账户中字母什么的，只能用员工号，限定10位
    QValidator *validator = new QRegExpValidator(Countdator,0);
    ui->comboBox->setValidator(validator);
    //ui->CountEdit->setValidator(validator);


    QRegExp PassWord("[A-Za-z0-9_]{6,15}");                        //使用正则表达式过滤密码中文字符号什么的(限定数字字母)，长度限定15
    QValidator *Passvalidator = new QRegExpValidator(PassWord,0);
    ui->PassWordEdit->setValidator(Passvalidator);


    ui->MemberButton->setChecked(true);                            //默认员工被选中







    QObject ::connect(ui->LoadingButton,SIGNAL(clicked()),this,SLOT(LandingSlot()));            //按钮登录与槽
    QObject ::connect(ui->Forgetlabel,SIGNAL(linkActivated(QString)),this,SLOT(openurlSLOt())); //忘记密码，打开外部超链接（默认url是"百度一下"）

    QObject ::connect(ui->PassWordEdit,SIGNAL(returnPressed()),this,SLOT(LandingSlot()));       //设置默认回车按钮是登录

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: LandingSlot()                               //登录槽
{
    int count=0,sum=0;
   QString stringBBQ = ui->comboBox->currentText();


    //QString Countindex = ui->CountEdit->text();
    QString Passindex  = ui->PassWordEdit->text();
    if(ui->ManageButton->isChecked())
    {
        if(stringBBQ.isEmpty())
        {
            QMessageBox::information(this,"tips","请输入账号");
        }
        else if(Passindex.isEmpty())
        {
            QMessageBox::information(this,"tips","请输入密码");
        }
        //QMessageBox::information(this,"tips","管理员被选中");
        else if(Passindex == "3131101106"|stringBBQ=="3131101104"|stringBBQ=="3131101111"|stringBBQ=="3131101125")
        {
        this->close();                                         //关闭主程序窗口

        managesystemSlot();                                    //显示管理系统界面
        }
        else
        {
            if(count<3)
            {
            QMessageBox::information(this,"tips","密码错误");
            }
            else
            {
                int examt =  QMessageBox::warning(this,"警告","由于输入密码错误次数过多请稍后重试！",QMessageBox::Yes|QMessageBox::Cancel);
                if(examt == QMessageBox::Yes)
                    this->close();
                else
                    this->close();
            }

            count++;
        }
    }
    else if(ui->MemberButton->isChecked())
    {
        if(stringBBQ.isEmpty())
        {
            QMessageBox::information(this,"tips","请输入账号");
        }
        else if(Passindex.isEmpty())
        {
            QMessageBox::information(this,"tips","请输入密码");
        }
        //QMessageBox::information(this,"tips","员工被选中");
        else if(Passindex == "3131101106"|stringBBQ=="3131101104"|stringBBQ=="3131101111"|stringBBQ=="3131101125")
        {
        this->close();                                         //关闭主程序窗口

        employeeSlot();                                    //显示管理系统界面
        }
        else
        {
            if(sum<3)
            {
            QMessageBox::information(this,"tips","密码错误");
            }
            else
            {
              int text =  QMessageBox::warning(this,"警告","由于输入密码错误次数过多请稍后重试！",QMessageBox::Yes|QMessageBox::Cancel);
              if(text == QMessageBox::Yes)
                  this->close();
              else
                  this->close();
            }
            sum++;
        }

    }

}

void MainWindow::managesystemSlot()                            //显示子窗口槽
{

    managesystem *dialog = new managesystem;
    dialog->show();
}


void MainWindow::openurlSLOt()                                 //打开超链接槽
{
    QDesktopServices::openUrl( QUrl("https://www.baidu.com/"));
}

void MainWindow::employeeSlot()
{
    EmployeeDialog *dialog = new EmployeeDialog;
    dialog->show();
}



