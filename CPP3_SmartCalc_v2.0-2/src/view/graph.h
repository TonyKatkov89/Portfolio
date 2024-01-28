#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>

#include "../controller/calc_controller.h"

namespace Ui {
class Graph;
}

class Graph : public QDialog {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();

 private:
  Ui::Graph *ui;
  double xBegin, xEnd, yMin, yMax, h, X;
  int N;
  QVector<double> x, y;

 public slots:
  void receiveGraphData(QString formula, double xBegin, double xEnd,
                        double yMin, double yMax);
};

#endif  // GRAPH_H
