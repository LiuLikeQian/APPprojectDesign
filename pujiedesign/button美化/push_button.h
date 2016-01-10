#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

//按钮类
class PushButton : public QPushButton
{
    Q_OBJECT

public:


    explicit PushButton(QWidget *parent = 0);
    ~PushButton();
    void loadPixmap(QString pic_name,int iChoice = 0);//按钮加载图片,iChoice 不等于0的时候图片不变化

protected:

    void enterEvent(QEvent *);//鼠标移进事件
    void leaveEvent(QEvent *);//鼠标移出事件
    void mousePressEvent(QMouseEvent *event);//鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    void paintEvent(QPaintEvent *);//绘图事件

private:

    //枚举按钮的几种状态
    enum ButtonStatus{NORMAL, ENTER, PRESS, NOSTATUS};
    ButtonStatus status;
    QPixmap pixmap;

    int btn_width; //按钮宽度
    int btn_height; //按钮高度
    bool mouse_press; //按钮左键是否按下
};


#endif // PUSH_BUTTON_H
