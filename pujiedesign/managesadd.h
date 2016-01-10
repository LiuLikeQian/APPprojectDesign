#ifndef MANAGESADD_H
#define MANAGESADD_H

#include <QDialog>
#include "managesystem.h"
#include <QMovie>
namespace Ui {
class managesAdd;
}

class managesAdd : public QDialog
{
    Q_OBJECT
    
public:
    explicit managesAdd(QWidget *parent = 0);
    ~managesAdd();
    
private:
    Ui::managesAdd *ui;
    QMovie *movie;

private slots:
    void SubmitSlot();      //提交槽
    void CancelSlot();      //取消槽

    void DesignSlot();      //设置头像 槽
};

#endif // MANAGESADD_H
