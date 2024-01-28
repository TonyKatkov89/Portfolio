#include <QVector>

#include "graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QDialog(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
}

Graph::~Graph() { delete ui; }

void Graph::receiveGraphData(QString formula, double xBegin, double xEnd,
                             double yMin, double yMax) {
  this->setWindowTitle(formula);
  h = fabs(yMax - yMin) / 50000;
  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(yMin, yMax);
  QByteArray ba = formula.toLocal8Bit();
  char *input = ba.data();
  stack_s *notation;
  notation = parcing(input);
  stack_s *reversed_notation = notation_reverse(notation, xBegin);
  double prevY = calculate(reversed_notation);
  //  double trend = 2;

  for (X = xBegin; X <= xEnd; X += h) {
    free_stack(reversed_notation);
    reversed_notation = notation_reverse(notation, X);
    double result = calculate(reversed_notation);
    double Y;
    //    if (trend >= 1 && result / prevY <= 0) {
    //        Y = NAN;
    //    } else {
    //        Y = result;
    //    }
    //    trend = fabs(result / prevY);

    if (fabs(result - prevY) > fabs(yMax - yMin) / 5) {
      Y = NAN;
    } else {
      Y = result;
    }
    x.push_back(X);
    y.push_back(Y);
    prevY = result;
  }

  free_stack(notation);

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}
