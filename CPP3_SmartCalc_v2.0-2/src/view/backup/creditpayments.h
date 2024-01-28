#ifndef CREDITPAYMENTS_H
#define CREDITPAYMENTS_H

#include <QDate>
#include <QDialog>

extern "C" {
#include "calculation.h"
}

namespace Ui {
class CreditPayments;
}

class CreditPayments : public QDialog {
  Q_OBJECT

public:
  explicit CreditPayments(QWidget *parent = nullptr);
  ~CreditPayments();

private:
  Ui::CreditPayments *ui;

signals:
  void sendCreditSummary(QString monthlyPayment, QString totalSum,
                         QString overpayment);

public slots:
  void receiveAnnuityData(double s, double p, int n, QDate startDate);
  void receiveDifferentiatedData(double s, double p, int n, QDate startDate);
};

#endif // CREDITPAYMENTS_H
