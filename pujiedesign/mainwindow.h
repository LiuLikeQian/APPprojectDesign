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
    void  LandingSlot();      //��¼��     bug��һ�������������ǲ�����ȫѡ�ģ�ʱ�䲻����Ͳ�Ū�ˡ�����

    void managesystemSlot();  //��������

    void openurlSLOt();       //�򿪳����Ӳ�

    void employeeSlot();      //Ա�������


};

#endif // MAINWINDOW_H
