#ifndef EDITNOTICEDIALOG_H
#define EDITNOTICEDIALOG_H

#include <QDialog>
#include "infordialog.h"
#include "QTextCodec"
#include <QDebug>
namespace Ui {
class EditNoticeDialog;
}

class EditNoticeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditNoticeDialog(QWidget *parent = 0);
    ~EditNoticeDialog();
    
private:
    Ui::EditNoticeDialog *ui;
private slots:
    void ReturnSlot();      //∑µªÿ≤€
    void SubmitSlot();      //Ã·Ωª≤€
};

#endif // EDITNOTICEDIALOG_H
