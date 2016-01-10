#include "myinfordialog.h"
#include "ui_myinfordialog.h"

MyInforDialog::MyInforDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyInforDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("������Ϣ");          //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");    //ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(600,430);
    setMinimumSize(600,430);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    this->movie = new QMovie(":/image/zhangsa.png");                         //��movieʵ����
    ui->photolabel_4->setMovie(this->movie);                                //����������ʱ��ͼƬ��Ϊ����һ��ͬʱ����
    this->movie->start();

    QString index[20]={"���","��","1980-05-13","δ��","˶ʿ","����","350121198505134897","15668151579","����ʡ����","����ʦ","�������ʦ","2012-2018","����","��","�й�������Ա","3131101164","0591-6731947","2010-08-08","����",};
    ui->NameEdit_2->setText(index[0]);        //����
    ui->SexEdit_2->setText(index[1]);         //�Ա�
    ui->BrithdayEdit_2->setText(index[2]);    //��������
    ui->MerryEdit_2->setText(index[3]);       //����
    ui->CultureEdit_2->setText(index[4]);     //�Ļ��̶�
    ui->WhereEdit_2->setText(index[5]);       //����
    ui->PersonNumberEdit->setText(index[6]);//���֤
    ui->TelEdit->setText(index[7]);         //�ֻ�
    ui->PlaceEdit->setText(index[8]);       //����
    ui->SituationEdit->setText(index[9]);   //��λ
    ui->PostEdit->setText(index[10]);       //ְ��
    ui->PeriodEdit->setText(index[11]);     //��ͬ��Ч��
    ui->StateEdit->setText(index[12]);      //״̬
    ui->NationEdit->setText(index[13]);     //����
    ui->BackgroundEdit->setText(index[14]); //������ò
    ui->WorkNumEdit->setText(index[15]);    //Ա����
    ui->WorkTelEdit->setText(index[16]);    //�칫�绰

    QDateTime time =  QDateTime::fromString(index[17], "yyyy-MM-dd");
    ui->ReachEdit->setTime(time.time());    //��������
    ui->OtherEdit->setText(index[18]);      //��ע


    QObject::connect(ui->ReturnButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));       //�����ź����
}

MyInforDialog::~MyInforDialog()
{
    delete ui;
}

void MyInforDialog::ReturnSlot()
{
    this->close();
    EmployeeDialog *dialog = new EmployeeDialog; //�ص���һ��
    dialog->show();
}
