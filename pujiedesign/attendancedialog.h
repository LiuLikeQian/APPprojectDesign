#ifndef ATTENDANCEDIALOG_H
#define ATTENDANCEDIALOG_H

#include <QDialog>
#include "managesystem.h"
namespace Ui {
class AttendanceDialog;
}

class AttendanceDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AttendanceDialog(QWidget *parent = 0);
    ~AttendanceDialog();
    
private:
    Ui::AttendanceDialog *ui;
private slots:
    void ReturnSlot();  //���ز�
};

#endif // ATTENDANCEDIALOG_H
