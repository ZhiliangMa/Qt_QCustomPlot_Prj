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

    void demoStyle_1(QCustomPlot *customPlot);
    void demoStyle_2(QCustomPlot *customPlot);
    void demoStyle_3(QCustomPlot *customPlot);
    void demoStyle_4(QCustomPlot *customPlot);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
