#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include <QDialog>
#include "managesystem.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QMovie>

#include <QFileDialog>

namespace Ui {
class ModifyDialog;
}

class ModifyDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ModifyDialog(QWidget *parent = 0);
    ~ModifyDialog();
    friend class searchemployee;
    
private:
    Ui::ModifyDialog *ui;
    QMovie *movie;
private slots:
    void SubmitSlot();          //�ύ��
    void ReturnSlot();          //���ز�
    void designSlot();          //����ͷ���
};

#endif // MODIFYDIALOG_H
