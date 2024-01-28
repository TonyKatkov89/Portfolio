#ifndef SCALE_H
#define SCALE_H

#include <QDialog>

#include "../controller/calc_controller.h"
#include "graph.h"

namespace Ui {
class Scale;
}

class Scale : public QDialog {
  Q_OBJECT

 public:
  explicit Scale(QWidget *parent = nullptr);
  ~Scale();

 private:
  Ui::Scale *ui;
  QString formula;
  double xMin, xMax, yMin, yMax;
  Graph *window;

 signals:
  void sendDataToGraph(QString formula, double xMin, double xMax, double yMin,
                       double yMax);

 public slots:
  void receiveFormula(QString formula);

 private slots:
  void on_pushButton_drawGraph_clicked();
};

#endif  // SCALE_H
