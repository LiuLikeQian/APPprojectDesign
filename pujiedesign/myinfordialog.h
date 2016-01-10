#ifndef MYINFORDIALOG_H
#define MYINFORDIALOG_H

#include <QDialog>
#include "employeedialog.h"

namespace Ui {
class MyInforDialog;
}

class MyInforDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MyInforDialog(QWidget *parent = 0);
    ~MyInforDialog();
    QMovie *movie;
    
private:
    Ui::MyInforDialog *ui;
private slots:
    void ReturnSlot();      //·µ»Ø²Û
};

#endif // MYINFORDIALOG_H
