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
    void ReturnSlot();      //���ز�
    void AddSlot();         //������ѵ��Ա
    void DeleteSlot();      //ɾ����ѵ��Ա

};

#endif // TRAINDIALOG_H
