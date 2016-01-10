#ifndef QUERYDLIALOG_H
#define QUERYDLIALOG_H

#include <QDialog>

namespace Ui {
class QueryDlialog;
}

class QueryDlialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit QueryDlialog(QWidget *parent = 0);
    ~QueryDlialog();
    
private:
    Ui::QueryDlialog *ui;
private slots:
    void Personnumber();    //Ô±¹¤ºÅ
};

#endif // QUERYDLIALOG_H
