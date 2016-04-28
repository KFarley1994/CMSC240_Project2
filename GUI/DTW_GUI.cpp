#include "DTW_GUI.h"
#include "ui_DTW_GUI.h"
#include <QVector>
#include <QPointF>

DTW_GUI::DTW_GUI(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::DTW_GUI)
{
    ui->setupUi(this);
}

DTW_GUI::~DTW_GUI()
{
    delete ui;
}

void DTW_GUI::paintEvent(QPaintEvent *e)
{
    // This is an example paintEvent method only.  You should
    // modify appropriately, consulting Qt references for
    // alternate components to do the job you need....
    
    QPainter painter(this);
    
    QPen pointPen(Qt::black);
    pointPen.setWidth(6);
    
    QPen linePen(Qt::red);
    linePen.setWidth(2);
    
    QPoint p1;
    p1.setX(p.x() + 1.0);
    p += QPointF(1.0,0.0);
    p.rx()++;
    
    painter.setPen(linePen);
    painter.drawLine(p1);
    
    painter.setPen(pointPen);
    painter.drawRect(QRect(10,10,40,40));
}