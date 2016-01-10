#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

//��ť��
class PushButton : public QPushButton
{
    Q_OBJECT

public:


    explicit PushButton(QWidget *parent = 0);
    ~PushButton();
    void loadPixmap(QString pic_name,int iChoice = 0);//��ť����ͼƬ,iChoice ������0��ʱ��ͼƬ���仯

protected:

    void enterEvent(QEvent *);//����ƽ��¼�
    void leaveEvent(QEvent *);//����Ƴ��¼�
    void mousePressEvent(QMouseEvent *event);//��갴���¼�
    void mouseReleaseEvent(QMouseEvent *event);//����ͷ��¼�
    void paintEvent(QPaintEvent *);//��ͼ�¼�

private:

    //ö�ٰ�ť�ļ���״̬
    enum ButtonStatus{NORMAL, ENTER, PRESS, NOSTATUS};
    ButtonStatus status;
    QPixmap pixmap;

    int btn_width; //��ť���
    int btn_height; //��ť�߶�
    bool mouse_press; //��ť����Ƿ���
};


#endif // PUSH_BUTTON_H
