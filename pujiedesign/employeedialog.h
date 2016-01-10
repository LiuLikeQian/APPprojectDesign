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
    void Explainslot();     //使用说明槽
    void ApplySlot();       //培训申请槽
    void InForSlot();       //通知槽
    void PersonalSlot();    //个人信息与槽
    void PublicSlot();      //公告信号与槽
};

#endif // EMPLOYEEDIALOG_H
