#include "push_button.h"

PushButton::PushButton(QWidget *parent)
    :QPushButton(parent)
{
    status = NORMAL;
    mouse_press = false;
}

PushButton::~PushButton()
{

}

void PushButton::loadPixmap(QString pic_name,int iChoice)
{
    if(iChoice == 0)
    {
        pixmap.load(pic_name);
        btn_width = pixmap.width()/4;
        btn_height = pixmap.height();
        setFixedSize(btn_width, btn_height);
    }
    else
    {
        pixmap.load(pic_name);
        btn_width = pixmap.width();
        btn_height = pixmap.height();
        setFixedSize(btn_width, btn_height);
    }
}

void PushButton::enterEvent(QEvent *)
{
    status = ENTER;
    update();			//更新窗口部件状态,速度比repaint快，更少闪烁
}

void PushButton::mousePressEvent(QMouseEvent *event)
{
    //若点击鼠标左键
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        status = PRESS;
        update();
    }
}

void PushButton::mouseReleaseEvent(QMouseEvent *)
{
    //若点击鼠标左键
    if(mouse_press)
    {
        mouse_press = false;
        status = ENTER;
        update();
        emit clicked();
    }
}

void PushButton::leaveEvent(QEvent *)
{
    status = NORMAL;
    update();
}

void PushButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), pixmap.copy(btn_width * status, 0, btn_width, btn_height));
    //rect()获取窗体的几何(长宽高等)  copy深拷贝rect返回的几何数据然后调用drawPixmap重画
}
