#ifndef MORTGAGE_H
#define MORTGAGE_H

#include <QCalendarWidget>
#include <QDate>
#include <QMainWindow>

#include "../controller/calc_controller.h"
#include "creditpayments.h"
#include "s21_smartcalc.h"

namespace Ui {
class Mortgage;
}

class Mortgage : public QMainWindow {
  Q_OBJECT

 public:
  explicit Mortgage(QWidget *parent = nullptr);
  ~Mortgage();

 private slots:
  void on_actionQuit_triggered();

  void on_actionStandard_triggered();

  void on_pushButton_clicked();

 private:
  Ui::Mortgage *ui;

 signals:
  void sendLoanCalculationData(double s, double p, int n, QDate startDate);

 public slots:
  void showCreditSummary(QString monthlyPayment, QString totalSum,
                         QString overpayment);
};

#endif  // MORTGAGE_H
