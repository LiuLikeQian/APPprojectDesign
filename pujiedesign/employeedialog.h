#ifndef EMPLOYEEDIALOG_H
#define EMPLOYEEDIALOG_H

#include <QDialog>
#include "explain.h"
#include <QMessageBox>
#include <QDebug>
#include "informationdialog.h"
#include "modifydialog.h"
#include "myinfordialog.h"
#include "mypublicdialog.h"

namespace Ui {
class EmployeeDialog;
}

class EmployeeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EmployeeDialog(QWidget *parent = 0);
    ~EmployeeDialog();
    friend class InformationDialog;


private:
    Ui::EmployeeDialog *ui;
private slots:
    void Explainslot();     //ʹ��˵����
    void ApplySlot();       //��ѵ�����
    void InForSlot();       //֪ͨ��
    void PersonalSlot();    //������Ϣ���
    void PublicSlot();      //�����ź����
};

#endif // EMPLOYEEDIALOG_H
