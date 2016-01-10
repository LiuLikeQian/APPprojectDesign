#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //w.setWindowIcon(QIcon("windows.ico"));

    QPixmap pixmap(":/image/displays.png");        //����ͼƬ
    QSplashScreen splash(pixmap);                  //����splash ����ʾ����Ļ��
    splash.show();                                 //��ʾsplash

    Sleep(3000);
    splash.finish(&w);


    w.show();
    return a.exec();
}
