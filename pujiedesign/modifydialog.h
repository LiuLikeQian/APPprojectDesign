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
    void SubmitSlot();          //提交槽
    void ReturnSlot();          //返回槽
    void designSlot();          //设置头像槽
};

#endif // MODIFYDIALOG_H
