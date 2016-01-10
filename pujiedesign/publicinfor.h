#ifndef PUBLICINFOR_H
#define PUBLICINFOR_H

#include <QDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QDebug>
#include "managesystem.h"
namespace Ui {
class PublicInfor;
}

class PublicInfor : public QDialog
{
    Q_OBJECT
    
public:
    explicit PublicInfor(QWidget *parent = 0);
    ~PublicInfor();
    
private:
    Ui::PublicInfor *ui;
private slots:
    void OkSlot();      //È·¶¨²Û
    void ReturnSlot();  //·µ»Ø²Û
};

#endif // PUBLICINFOR_H
