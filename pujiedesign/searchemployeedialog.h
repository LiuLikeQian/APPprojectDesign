#ifndef SEARCHEMPLOYEEDIALOG_H
#define SEARCHEMPLOYEEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "modifydialog.h"
namespace Ui {
class SearchEmployeeDialog;
}

class SearchEmployeeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SearchEmployeeDialog(QWidget *parent = 0);
    ~SearchEmployeeDialog();
    
private:
    Ui::SearchEmployeeDialog *ui;

private slots:
     void SearchEmployeeSlot();      //ËÑË÷Ô±¹¤ºÅ²Û
     void ReturnSlot();              //·µ»Ø ²Û
};

#endif // SEARCHEMPLOYEEDIALOG_H
