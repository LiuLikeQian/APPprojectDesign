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
    void SubmitSlot();      //�ύ��
    void CancelSlot();      //ȡ����

    void DesignSlot();      //����ͷ�� ��
};

#endif // MANAGESADD_H
