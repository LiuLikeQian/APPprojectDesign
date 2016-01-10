#include "explain.h"
#include "ui_explain.h"

Explain::Explain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Explain)
{
    ui->setupUi(this);
    this->setWindowTitle("使用说明");       //设置标题
    QIcon icon = QIcon(":/image/manage.ico");//注意修改这里的图片目录
    setWindowIcon(icon);

    setMaximumSize(400,300);
    setMinimumSize(400,300);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint);//去掉窗口上的问号

}

Explain::~Explain()
{
    delete ui;
}
