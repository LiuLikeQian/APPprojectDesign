#ifndef WAGEDIALOG_H
#define WAGEDIALOG_H

#include <QDialog>
#include "managesystem.h"

namespace Ui {
class WageDialog;
}

class WageDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit WageDialog(QWidget *parent = 0);
    ~WageDialog();
    
private:
    Ui::WageDialog *ui;
private slots:
    void ReturnSlot();    //¹¤×Ê²Û
};

#endif // WAGEDIALOG_H
