#include "scale.h"

#include <QDoubleValidator>

#include "qvalidator.h"
#include "ui_scale.h"

Scale::Scale(QWidget *parent) : QDialog(parent), ui(new Ui::Scale) {
  ui->setupUi(this);
  this->setWindowTitle("Scale set");
  ui->lineEdit_xMin->setValidator(
      new QDoubleValidator(-1000000, 1000000, 2, this));
  ui->lineEdit_xMax->setValidator(
      new QDoubleValidator(-1000000, 1000000, 2, this));
  ui->lineEdit_yMin->setValidator(
      new QDoubleValidator(-1000000, 1000000, 2, this));
  ui->lineEdit_yMax->setValidator(
      new QDoubleValidator(-1000000, 1000000, 2, this));
  ui->lineEdit_xMin->insert("-5");
  ui->lineEdit_xMax->insert("5");
  ui->lineEdit_yMin->insert("-5");
  ui->lineEdit_yMax->insert("5");
}

Scale::~Scale() { delete ui; }

void Scale::receiveFormula(QString receivedFormula) {
  formula = receivedFormula;
}

void Scale::on_pushButton_drawGraph_clicked() {
  xMin = QString(ui->lineEdit_xMin->text()).toDouble();
  xMax = QString(ui->lineEdit_xMax->text()).toDouble();
  yMin = QString(ui->lineEdit_yMin->text()).toDouble();
  yMax = QString(ui->lineEdit_yMax->text()).toDouble();
  window = new Graph(this);
  window->show();
  connect(this, &Scale::sendDataToGraph, window, &Graph::receiveGraphData);
  emit sendDataToGraph(formula, xMin, xMax, yMin, yMax);
  close();
}
