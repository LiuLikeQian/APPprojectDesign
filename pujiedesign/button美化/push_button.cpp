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
    update();			//���´��ڲ���״̬,�ٶȱ�repaint�죬������˸
}

void PushButton::mousePressEvent(QMouseEvent *event)
{
    //�����������
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        status = PRESS;
        update();
    }
}

void PushButton::mouseReleaseEvent(QMouseEvent *)
{
    //�����������
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
    //rect()��ȡ����ļ���(����ߵ�)  copy���rect���صļ�������Ȼ�����drawPixmap�ػ�
}
