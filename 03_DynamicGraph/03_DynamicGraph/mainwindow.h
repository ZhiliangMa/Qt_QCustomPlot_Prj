#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void TimeData_Update(void);

private slots:
    void on_checkBox_1_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    // 绘图控件的指针
    QCustomPlot *pPlot1;
    // 状态栏指针
    QStatusBar *sBar;
    // 绘图控件中曲线的指针
    QCPGraph *pGraph1_1;
    QCPGraph *pGraph1_2;

    void QPlot_init(QCustomPlot *customPlot);
    void Show_Plot(QCustomPlot *customPlot, double num);
};
#endif // MAINWINDOW_H
