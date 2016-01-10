#ifndef INFORMATIONDIALOG_H
#define INFORMATIONDIALOG_H

#include <QDialog>
#include "employeedialog.h"
#include <QFile>

namespace Ui {
class InformationDialog;
}

class InformationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit InformationDialog(QWidget *parent = 0);
    ~InformationDialog();
    
private:
    Ui::InformationDialog *ui;

private slots:
    void ReturnSlot();      //·µ»Ø²Û
};

#endif // INFORMATIONDIALOG_H
