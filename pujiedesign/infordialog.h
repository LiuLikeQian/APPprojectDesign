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
    void ReturnSlot();      //返回槽
    void EditNoticeSlot();  //编辑通知槽
    void SingleInforSlot(); //发送通知槽
    void AllSlot();         //全体通知槽
};

#endif // INFORDIALOG_H
