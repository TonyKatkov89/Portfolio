#include "graph.h"

#include <QVector>

#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QDialog(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
}

Graph::~Graph() { delete ui; }

void Graph::receiveGraphData(QString formula, double xBegin, double xEnd,
                             double yMin, double yMax) {
  this->setWindowTitle(formula);
  h = fabs(yMax - yMin) / 10000;
  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(yMin, yMax);
  std::string input = formula.toStdString();
  s21::CalcController calc(input);

  for (X = xBegin; X <= xEnd; X += h) {
    double result = calc.Result(X);
    double Y;
    if (result > yMax + (yMax - yMin) || result < yMin - (yMax - yMin)) {
      Y = NAN;
    } else {
      Y = result;
    }
    x.push_back(X);
    y.push_back(Y);
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}
