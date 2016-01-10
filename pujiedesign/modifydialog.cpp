#include "modifydialog.h"
#include "ui_modifydialog.h"

ModifyDialog::ModifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("�޸�Ա����Ϣ");          //���ñ���
    QIcon icon = QIcon(":/image/manage.ico");    //ע���޸������ͼƬĿ¼
    setWindowIcon(icon);

    setMaximumSize(600,430);
    setMinimumSize(600,430);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//ȥ�������ϵ��ʺ�

    //ui->textEdit->setReadOnly(true);                                              //��ֹ��ʾԱ����Ϣ���ı���������Ϣ

    QObject::connect(ui->SubmitButton,SIGNAL(clicked()),this,SLOT(SubmitSlot()));   //�ύ ��
    QObject::connect(ui->CancelButton,SIGNAL(clicked()),this,SLOT(ReturnSlot()));   //���� ��
    QObject::connect(ui->DesignButton,SIGNAL(clicked()),this,SLOT(designSlot()));   //����ͷ���

    this->movie = new QMovie(":/image/wuji.png");                         //��movieʵ����
    ui->photolabel->setMovie(this->movie);                                //����������ʱ��ͼƬ��Ϊ����һ��ͬʱ����
    this->movie->start();

    QString index[20]={"������","��","1977-06-13","�ѻ�","˶ʿ","����","350121198505134897","18068341579","����ʡ������������","����ʦ","���繤��ʦ","2012-2018","�ݼ�","��","�й�������Ա","3131101164","0591-6731947","2010-08-08","����",};
    ui->NameEdit->setText(index[0]);        //����
    ui->SexEdit->setText(index[1]);         //�Ա�
    ui->BrithdayEdit->setText(index[2]);    //��������
    ui->MerryEdit->setText(index[3]);       //����
    ui->CultureEdit->setText(index[4]);     //�Ļ��̶�
    ui->WhereEdit->setText(index[5]);       //����
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

    /*QString str = "����ַ���";
    ui->NameEdit->setText(str);*/

}

ModifyDialog::~ModifyDialog()
{
    delete ui;
}

void ModifyDialog::SubmitSlot()
{
    //��һ��ѡ���жϿ�
    //QString index[20] =


    int index = QMessageBox::information(this,"��ʾ","ȷ��Ҫ�ύ�Ѿ��޸ĵ����ϣ�",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

            if(index == QMessageBox::Yes)
            {
                this->close();
                managesystem  *index = new managesystem; //�ص���һ��
                index->show();

            }
            else if(index == QMessageBox::No)
            {
                qDebug()<<"�û�ѡ����No";
            }
            else if(index == QMessageBox::Cancel)
            {
                qDebug()<<"�û�ѡ����Cancel";
            }
}

void ModifyDialog::ReturnSlot()
{
    this->close();
    managesystem  *index = new managesystem; //�ص���һ��
    index->show();
}


void ModifyDialog::designSlot()
{
    //��̬��������/usr/local/Trolltech
    //QString index = QFileDialog::getOpenFileName("/home","Images (*.png *.xpm *.jpg)",this,"open file dialog","Choose a photo" );
    QString index = QFileDialog::getOpenFileName( this,tr("���ļ�"),"/usr/local/Trolltech",tr("�κ��ļ�(*.*)"";;�ı��ļ�(*.txt)"";;XML�ļ�(*.xml)"";;Images (*.png *.xpm *.jpg)"));
    this->movie = new QMovie(index);

    ui->photolabel->setMovie(this->movie);
    this->movie->start();
}
