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
    void DeleteSlot();                  //ɾ��Ա��
    void DisPlaySlot();                 //��ʾԱ��
    void ReturnSlot();                  //���ء��رյ�ǰ����
};

#endif // DELETEDIALOG_H
