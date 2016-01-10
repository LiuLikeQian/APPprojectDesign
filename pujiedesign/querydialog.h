#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include <QDialog>
#include "managesystem.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QDebug>
namespace Ui {
class QueryDialog;
}

class QueryDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit QueryDialog(QWidget *parent = 0);
    ~QueryDialog();
    
private:
    Ui::QueryDialog *ui;
private slots:
    void PersonNumSlot();
    void ReturnSlot();
};

#endif // QUERYDIALOG_H
