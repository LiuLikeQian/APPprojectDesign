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

    //void AddSlot();               //增加员工
    void DeleteSlot();              //删除删除
    void InforSlot();               //消息通知
    void PublicSlot();              //公告
    void ExplainSlot();             //使用说明
    void TrainSlot();               //培训管理
    void ModifySlot();              //修改员工
    void QuerySlot();               //查询员工
    void managesAddSlot();          //添加员工子窗口槽

    void WageSlot();                //工资管理
    void AttendanceSlot();          //出勤管理




};

#endif // MANAGESYSTEM_H
