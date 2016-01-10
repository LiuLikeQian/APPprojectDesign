#ifndef MYPUBLICDIALOG_H
#define MYPUBLICDIALOG_H

#include <QDialog>
#include "employeedialog.h"
namespace Ui {
class MyPublicDialog;
}

class MyPublicDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MyPublicDialog(QWidget *parent = 0);
    ~MyPublicDialog();
    
private:
    Ui::MyPublicDialog *ui;
private slots:
    void OkSlot();      //»∑»œ≤€
};

#endif // MYPUBLICDIALOG_H
