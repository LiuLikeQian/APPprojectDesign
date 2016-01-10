#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "managesystem.h"


namespace Ui {
class DeleteDialog;
}

class DeleteDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DeleteDialog(QWidget *parent = 0);
    ~DeleteDialog();
    
private:
    Ui::DeleteDialog *ui;
private slots:
    void DeleteSlot();                  //删除员工
    void DisPlaySlot();                 //显示员工
    void ReturnSlot();                  //返回、关闭当前窗口
};

#endif // DELETEDIALOG_H
