#pragma once
#include <QtCharts/QtCharts>
class graph
{
private:
    static int SeriesMaxLen;
    QVector<QLineSeries *> series;
    QChart *chart;
    QChartView *chartView;

public:
    graph(int nOfSeries = 1);
    ~graph();
    void ClearSeries();
    void AppendSeries(int, double, double);
    void AppendSeries(double, double);
    void UpdateGraph();
    void PutInFrame(QFrame *);
    QLineSeries *getSeries(int n = 0);
    void setAxisTitles(const QString &, const QString &);
    static void setSeriesMaxLen(int);
};
