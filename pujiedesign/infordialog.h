#ifndef INFORDIALOG_H
#define INFORDIALOG_H

#include <QDialog>
#include "managesadd.h"
namespace Ui {
class InforDialog;
}

class InforDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InforDialog(QWidget *parent = 0);
    ~InforDialog();
    
private:
    Ui::InforDialog *ui;
private slots:
    void ReturnSlot();      //���ز�
    void EditNoticeSlot();  //�༭֪ͨ��
    void SingleInforSlot(); //����֪ͨ��
    void AllSlot();         //ȫ��֪ͨ��
};

#endif // INFORDIALOG_H
