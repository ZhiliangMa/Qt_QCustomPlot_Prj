#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 给widget绘图控件，设置个别名，方便书写
    QCustomPlot *pGraph1 = ui->widget_1;
    QCustomPlot *pGraph2 = ui->widget_2;
    QCustomPlot *pGraph3 = ui->widget_3;
    QCustomPlot *pGraph4 = ui->widget_4;

    // 运行示例代码，大部分参照别人博客，以附链接
    demoStyle_1(pGraph1);
    demoStyle_2(pGraph2);
    demoStyle_3(pGraph3);
    demoStyle_4(pGraph4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 样式参照：https://www.cnblogs.com/jeffkuang/articles/6477790.html
void MainWindow::demoStyle_1(QCustomPlot *customPlot)
{
    // 样式参照：https://www.cnblogs.com/jeffkuang/articles/6477790.html
    // 设置坐标轴标签名称
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");

    // 设置坐标轴显示范围，默认范围为 0~5
    customPlot->xAxis->setRange(-11, 11);
    customPlot->yAxis->setRange(-1100, 1100);

    // 设置背景色
    customPlot->setBackground(QColor(50, 50, 50));

    // 设置x轴文本色、轴线色、字体等
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(QColor(0, 160, 230));
    customPlot->xAxis->setBasePen(QPen(QColor(32, 178, 170)));
    customPlot->xAxis->setTickPen(QPen(QColor(128, 0, 255)));
    customPlot->xAxis->setSubTickPen(QColor(255, 165, 0));
    QFont xFont = customPlot->xAxis->labelFont();
    xFont.setPixelSize(20);
    customPlot->xAxis->setLabelFont(xFont);

    // 设置y轴文本色、轴线色、字体等
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(QColor(0, 160, 230));
    customPlot->yAxis->setBasePen(QPen(QColor(32, 178, 170)));
    customPlot->yAxis->setTickPen(QPen(QColor(128, 0, 255)));
    customPlot->yAxis->setSubTickPen(QColor(255, 165, 0));
    QFont yFont = customPlot->yAxis->labelFont();
    yFont.setPixelSize(20);
    customPlot->yAxis->setLabelFont(yFont);


    // 向绘图区域QCustomPlot添加一条曲线
    QCPGraph *pGraph = customPlot->addGraph();
    // 设置曲线颜色
    pGraph->setPen(QPen(QColor(32, 178, 170)));
    // 可变数组存放绘图的坐标的数据，分别存放x和y坐标的数据，101为数据长度
    QVector<double> x(101), y(101);
    // 添加数据，这里演示y = x^3，为了正负对称，x从-10到+10
    for (int i = 0; i < 101; ++i)
    {
        x[i] = i/5 - 10;
        y[i] = qPow(x[i], 3);  // x的y次方;
    }
    // 添加数据
    customPlot->graph(0)->setData(x, y);


    // 导出图片
    customPlot->savePng("customPlot.png", 480, 320);
}

// 样式参照：http://voidcat.cn/index.php/2018/12/10/qcustomplot/
void MainWindow::demoStyle_2(QCustomPlot *customPlot)
{
    QVector<double> x, y;
    for (double i=-10; i <= 10; i=i+0.1)
    {
        double x1 = i;
        double y1 = qSin(i) * 100;
        x.append(x1);
        y.append(y1);
    }
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::red));
    customPlot->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    //customPlot->graph(0)->setLineStyle(QCPGraph::lsStepCenter);// 搜LineStyle：lsNone,lsLine(默认的，连线),lsStepLeft,lsStepRight,lsStepCenter,lsImpulse
    customPlot->graph(0)->setData(x, y);
    customPlot->xAxis->setLabel("time");
    customPlot->yAxis->setLabel("value");
    customPlot->xAxis->setRange(-10, 10);
    customPlot->yAxis->setRange(-100, 100);
}

void MainWindow::demoStyle_3(QCustomPlot *customPlot)
{
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

// 样式参照：https://www.cnblogs.com/swarmbees/p/6057798.html
void MainWindow::demoStyle_4(QCustomPlot *customPlot)
{
    customPlot->legend->setVisible(true);
    customPlot->legend->setFont(QFont("Helvetica", 9));
    QPen pen;
    QStringList lineNames;//设置图例的文本
    lineNames << "lsNone" << "lsLine" << "lsStepLeft" << "lsStepRight" << "lsStepCenter" << "lsImpulse";
    // add graphs with different line styles:
    for (int i = QCPGraph::lsNone; i <= QCPGraph::lsImpulse; ++i)
    {
        customPlot->addGraph();
        pen.setColor(QColor(qSin(i * 1 + 1.2) * 80 + 80, qSin(i*0.3 + 0) * 80 + 80, qSin(i*0.3 + 1.5) * 80 + 80));
        customPlot->graph()->setPen(pen);
        customPlot->graph()->setName(lineNames.at(i - QCPGraph::lsNone));
        customPlot->graph()->setLineStyle((QCPGraph::LineStyle)i);//设置线性
        customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));//设置每个节点数据绘制风格，默认是空，这里设置为空心圆
        // generate data:
        QVector<double> x(15), y(15);
        for (int j = 0; j < 15; ++j)
        {
            x[j] = j / 15.0 * 5 * 3.14 + 0.01;
            y[j] = 7 * qSin(x[j]) / x[j] - (i - QCPGraph::lsNone) * 5 + (QCPGraph::lsImpulse) * 5 + 2;
        }
        customPlot->graph()->setData(x, y);
        customPlot->graph()->rescaleAxes(true);//坐标轴自适应
    }
    // zoom out a bit:
    customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());
    customPlot->xAxis->scaleRange(1.1, customPlot->xAxis->range().center());
    // set blank axis lines:
    customPlot->xAxis->setTicks(false);//x轴不显示刻度
    customPlot->yAxis->setTicks(true);//y轴显示刻度
    customPlot->xAxis->setTickLabels(false);//x轴不显示文本
    customPlot->yAxis->setTickLabels(true);//y轴显示文本
    // make top right axes clones of bottom left axes:
    customPlot->axisRect()->setupFullAxesBox();//一个默认的坐标轴矩形配置，包括：顶部坐标轴跟随底部坐标轴同步、右侧坐标轴跟随左侧坐标轴同步，不仅仅是坐标轴范围跟随同步，包括文本精度、文本格式、坐标轴类型、是否自动生成刻度、刻度间距等等。
}
