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
     void SearchEmployeeSlot();      //����Ա���Ų�
     void ReturnSlot();              //���� ��
};

#endif // SEARCHEMPLOYEEDIALOG_H
