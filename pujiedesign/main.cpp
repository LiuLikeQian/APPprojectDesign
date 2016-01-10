#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //w.setWindowIcon(QIcon("windows.ico"));

    QPixmap pixmap(":/image/displays.png");        //加载图片
    QSplashScreen splash(pixmap);                  //构造splash 并显示到屏幕上
    splash.show();                                 //显示splash

    Sleep(3000);
    splash.finish(&w);


    w.show();
    return a.exec();
}
