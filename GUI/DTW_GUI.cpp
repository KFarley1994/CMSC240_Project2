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
    
    //QPoint p1,p2,p3;

    //QVector vector = p1;
    
    //painter.setPen(linePen);
    //painter.drawLines(p1);
    
    painter.setPen(pointPen);
    painter.drawRect(QRect(100, 100, 200, 1000));//(40,40,200,1000)); 100, 100, 200, 1000
    painter.drawRect(QRect(310,100, 1000, 1000));//250,40,1000,1000));
    painter.drawRect(QRect(310, 1110, 1000, 200));//250,1050,1000,200));
}