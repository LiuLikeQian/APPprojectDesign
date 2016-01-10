#ifndef TRAINDIALOG_H
#define TRAINDIALOG_H

#include <QDialog>
#include "managesystem.h"
#include <QFont>
#include "editnoticedialog.h"
namespace Ui {
class TrainDialog;
}

class TrainDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TrainDialog(QWidget *parent = 0);
    ~TrainDialog();
    
private:
    Ui::TrainDialog *ui;
private slots:
    void ReturnSlot();      //返回槽
    void AddSlot();         //增加培训人员
    void DeleteSlot();      //删除培训人员

};

#endif // TRAINDIALOG_H
