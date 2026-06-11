#include "graph.h"
#include <stdexcept>

int graph::SeriesMaxLen = 50;
graph::graph(int nOfSeries)
{
    if (nOfSeries <= 0)
        throw std::out_of_range("Tried initialize graph with series <= 0");
    for (int i = 0; i < nOfSeries; i++) {
        series.append(new QLineSeries());
    }
    chart = new QChart();
    for (int i = 0; i < series.length(); i++) {
        chart->addSeries(series[i]);
    }
    chart->createDefaultAxes();
    chartView = new QChartView(chart);
}
graph::~graph()
{
    for (int i = 0; i < series.length(); i++) {
        delete series[i];
    }
    delete chart;
    delete chartView;
}

void graph::ClearSeries()
{
    for (int i = 0; i < series.length(); i++) {
        series[i]->clear();
    }
}
void graph::AppendSeries(int series_n, double x, double y)
{
    if (series_n < 0 || series_n >= series.size())
        return;
    series[series_n]->append(x, y);
    UpdateGraph();
}
void graph::AppendSeries(double x, double y)
{
    if (series.isEmpty())
        return;
    series[0]->append(x, y);
    UpdateGraph();
}
void graph::UpdateGraph()
{
    if (series.isEmpty())
        return;

    if (series[0]->count() > SeriesMaxLen) {
        for (int n = 0; n < series.count(); ++n) {
            series[n]->removePoints(0, series[n]->count() - SeriesMaxLen);
        }
    }
    double minX = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::lowest();
    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::lowest();
    bool foundAnyPoints = false;
    for (QLineSeries *s : series) {
        QList<QPointF> points = s->points();
        if (points.isEmpty())
            continue;
        foundAnyPoints = true;
        for (const QPointF &p : points) {
            if (p.x() < minX)
                minX = p.x();
            if (p.x() > maxX)
                maxX = p.x();
            if (p.y() < minY)
                minY = p.y();
            if (p.y() > maxY)
                maxY = p.y();
        }
    }
    if (!foundAnyPoints)
        return;
    if (qAbs(maxY - minY) < 0.0001) {
        minY -= 1.0;
        maxY += 1.0;
    }
    double marginY = (maxY - minY) * 0.05;
    if (marginY == 0)
        marginY = 0.1;
    if (!chart->axes(Qt::Vertical).isEmpty()) {
        chart->axes(Qt::Vertical).first()->setRange(minY - marginY, maxY + marginY);
    }
    if (!chart->axes(Qt::Horizontal).isEmpty()) {
        chart->axes(Qt::Horizontal).first()->setRange(minX, maxX);
    }
}

void graph::PutInFrame(QFrame *frame)
{
    if (frame->layout() != nullptr) {
        QLayout *oldLayout = frame->layout();
        int i = 0;
        QLayoutItem *item = oldLayout->takeAt(i);
        while (item != nullptr) {
            delete item->widget();
            delete item;
            item = oldLayout->takeAt(++i);
        }
    }
    QVBoxLayout *layout = new QVBoxLayout(frame);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(chartView);
}

QLineSeries *graph::getSeries(int n)
{
    return series[n];
}

void graph::setAxisTitles(const QString &xTitle, const QString &yTitle)
{
    auto Xaxes = chart->axes(Qt::Horizontal);
    if (!Xaxes.isEmpty()) {
        Xaxes.first()->setTitleText(xTitle);
        Xaxes.first()->setVisible(true);
    }
    auto Yaxes = chart->axes(Qt::Vertical);
    if (!Yaxes.isEmpty()) {
        Yaxes.first()->setTitleText(yTitle);
        Yaxes.first()->setVisible(true);
    }
}
void graph::setSeriesMaxLen(int n)
{
    SeriesMaxLen = n;
}
