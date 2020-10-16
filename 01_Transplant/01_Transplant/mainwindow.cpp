#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 给widget绘图控件，设置个别名，方便书写
    QCustomPlot *customPlot = ui->widget;

    // 设置坐标轴标签名称
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");

    // 设置坐标轴显示范围，不设置时默认范围为 0~5
    customPlot->xAxis->setRange(-10, 10);
    customPlot->yAxis->setRange(-100, 100);

    /// 添加曲线有两种方法
    /// 第一种直接插入，使用控件的曲线数组 graph()。但要注意：曲线从 graph(0)开始递增的，超出添加的个数使用会报错。不推荐这种方式，容易搞错。
    // 添加一条绘图曲线
    customPlot->addGraph();
    // 设置曲线颜色
    customPlot->graph(0)->setPen(QPen(QColor(255, 0, 0)));
    // 曲线的坐标数据，计算x和y的坐标
    QVector<double> x(201), y(201);
    for (int i = 0; i < 201; ++i)
    {
        x[i] = -10 + 0.1f *i;
        y[i] = sin(x[i])*50;  // y = 50sinx
    }
    // 设置曲线的坐标数据
    customPlot->graph(0)->setData(x, y);


    /// 第二种使用返回的指针，推荐使用这种方式，不容易出错。
    // 添加一条绘图曲线
    QCPGraph *pGraph2 = customPlot->addGraph();/// 这行代码等同于 customPlot->addGraph(); QCPGraph *pGraph2 = customPlot->graph(1);
    // 设置曲线颜色
    pGraph2->setPen(QPen(QColor(0, 0, 255)));
    // 曲线的坐标数据，计算x和y的坐标
    QVector<double> x1(201), y1(201);
    for (int i = 0; i < 201; ++i)
    {
        x1[i] = -10 + 0.1f *i;
        y1[i] = cos(x1[i])*50;  // y = 50cosx
    }
    // 设置曲线的坐标数据
    pGraph2->setData(x1, y1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

