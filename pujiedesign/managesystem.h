#ifndef MANAGESYSTEM_H
#define MANAGESYSTEM_H

#include <QDialog>

#include <QCloseEvent>
#include <QMessageBox>

#include "managesadd.h"
#include "ui_managesystem.h"
#include "explain.h"
#include "publicinfor.h"
#include "querydialog.h"
#include "deletedialog.h"
#include "modifydialog.h"
#include "searchemployeedialog.h"
#include "traindialog.h"
#include "infordialog.h"
#include "wagedialog.h"
#include "attendancedialog.h"
#include "employeedialog.h"

namespace Ui {
class managesystem;
}

class managesystem : public QDialog
{
    Q_OBJECT
    
public:
    explicit managesystem(QWidget *parent = 0);
    ~managesystem();

  /*friend class managesAdd;
    friend class Explain;
    friend class publicinfor;
    friend class QueryDialog;
    friend class DeleteDialog;
    friend class ModifyDialog;
    friend class searchemployee;
    friend class traindialog;
    friend class infordialog;
    friend class wagedialog;
    friend class attendancedialog;
    friend class employeedialog;*/


private:
    Ui::managesystem *ui;

private slots:
    //void closeEvent(QCloseEvent* );

    //void AddSlot();               //����Ա��
    void DeleteSlot();              //ɾ��ɾ��
    void InforSlot();               //��Ϣ֪ͨ
    void PublicSlot();              //����
    void ExplainSlot();             //ʹ��˵��
    void TrainSlot();               //��ѵ����
    void ModifySlot();              //�޸�Ա��
    void QuerySlot();               //��ѯԱ��
    void managesAddSlot();          //���Ա���Ӵ��ڲ�

    void WageSlot();                //���ʹ���
    void AttendanceSlot();          //���ڹ���




};

#endif // MANAGESYSTEM_H
