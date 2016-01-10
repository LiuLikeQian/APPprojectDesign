#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTextCodec>

#include <QString>
#include <QMessageBox>
#include <QRegExp>
#include <QValidator>

#include <QUrl>
#include <QDesktopServices>
#include "managesystem.h"
#include "explain.h"
#include <QIcon>
#include "employeedialog.h"



#include <QStyledItemDelegate>
#include <QWidget>
#include <QModelIndex>
#include <QPainter>
#include <QMouseEvent>
#include <QStyledItemDelegate>
#include <QToolTip>
#include <QApplication>
#include <QDebug>

#include <QSplashScreen>
#include <windows.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
signals:


private:
    Ui::MainWindow *ui;

private slots:
    void  LandingSlot();      //登录槽     bug在一般情况下密码框是不允许全选的，时间不允许就不弄了。。。

    void managesystemSlot();  //管理界面槽

    void openurlSLOt();       //打开超链接槽

    void employeeSlot();      //员工界面槽


};

#endif // MAINWINDOW_H
