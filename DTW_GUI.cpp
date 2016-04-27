#include "DTW_GUI.h"
#include "ui_DTW_GUI.h"

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

    // all of this from doc.qt.io/QtCharts/qtcharts-customchart-example.html
    QLineSeries *series = new QLineSeries();
    *series << QPoint(0, 6) << QPoint(9, 4) << QPoint(15, 20) << QPoint(25, 12);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);

    QPen pointPen(Qt::black);
    pointPen.setWidth(6);
    series->setPen(pointPen);

    // Chart Title
    QFont font;
    font.setPixelSize(15);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Timeseries Alignment")

    // Customize axis label
    QFont labelsFont;
    labelFont.setPixelSize(12);
    axisX->setLabelsFont(labelsFont);
    axisY->setLabelsFont(labelsFont);

    QBrush axisBrush(Qt::black);
    axisX->setLabelsBrush(axisBrush);
    axisY->setLabelsBrush(axisBrush);

    // Customize axis
    QPen axisPen(Qt::black);
    axisPen.setWidth(2);
    axisX->setLinePen(axisPen);
    axisY->setLinePen(axisPen);

    // Customize axis label values and ranges
    axisX->append("0", 10);
    axisX->append("500", 20);
    axisX->append("1000", 30);
    axisX->append("1500", 40);
    axisX->append("2000", 50);
    axisX->setRange(0,50);

    axisY->append("0", 10);
    axisY->append("500", 20);
    axisY->append("1000", 30);
    axisY->append("1500", 40);
    axisY->append("2000", 50);
    axisY->setRange(0,50);

    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);


    QPen linePen(Qt::red);
    linePen.setWidth(2);

    QPoint p1,p2;
    p1.setX(10); p1.setY(10);
    p2.setX(100); p2.setY(100);

    painter.setPen(linePen);
    painter.drawLine(p1,p2);

    painter.setPen(pointPen);
    painter.drawRect(QRect(10,10,40,40));

    // Create a view containing the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Show the chart on a main window
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}