#include "creditpayments.h"
#include "ui_creditpayments.h"

CreditPayments::CreditPayments(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreditPayments) {
  ui->setupUi(this);
  this->setWindowTitle("Payments paln");
}

CreditPayments::~CreditPayments() { delete ui; }

void CreditPayments::receiveAnnuityData(double s, double p, int n,
                                        QDate startDate) {
  double payment = annuity_payment(s, p, n);
  double overpayment = 0;
  double totalSum = s;
  QDate date = startDate;
  for (int i = 0; n > 0; i++, n--) {
    date = date.addMonths(1);
    double interestSum = interest_sum(s, p);
    overpayment += interestSum;
    double loanCoverage = payment - interestSum;
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(
        i, 0, new QTableWidgetItem(QDate(date).toString("dd-MMM-yyyy")));
    ui->tableWidget->setItem(
        i, 1, new QTableWidgetItem(QString::number(payment, 'f', 2)));
    ui->tableWidget->setItem(
        i, 2, new QTableWidgetItem(QString::number(loanCoverage, 'f', 2)));
    ui->tableWidget->setItem(
        i, 3, new QTableWidgetItem(QString::number(interestSum, 'f', 2)));
    s -= loanCoverage;
    s = fabs(s);
    ui->tableWidget->setItem(i, 4,
                             new QTableWidgetItem(QString::number(s, 'f', 2)));
  }
  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  totalSum += overpayment;
  QString monthlyPayment = QString::number(payment, 'f', 2);
  QString totalSum_str = QString::number(totalSum, 'f', 2);
  QString overpayment_str = QString::number(overpayment, 'f', 2);
  emit sendCreditSummary(monthlyPayment, totalSum_str, overpayment_str);
}

void CreditPayments::receiveDifferentiatedData(double s, double p, int n,
                                               QDate startDate) {
  double overpayment = 0;
  double totalSum = s;
  double loanCoverage = s / n;
  double interestSum = interest_sum(s, p);
  double payment = loanCoverage + interestSum;
  QString monthlyPayment = QString::number(payment, 'f', 2);
  QDate date = startDate;
  for (int i = 0; n > 0; i++, n--) {
    date = date.addMonths(1);
    interestSum = interest_sum(s, p);
    overpayment += interestSum;
    payment = loanCoverage + interestSum;
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(
        i, 0, new QTableWidgetItem(QDate(date).toString("dd-MMM-yyyy")));
    ui->tableWidget->setItem(
        i, 1, new QTableWidgetItem(QString::number(payment, 'f', 2)));
    ui->tableWidget->setItem(
        i, 2, new QTableWidgetItem(QString::number(loanCoverage, 'f', 2)));
    ui->tableWidget->setItem(
        i, 3, new QTableWidgetItem(QString::number(interestSum, 'f', 2)));
    s -= loanCoverage;
    ui->tableWidget->setItem(i, 4,
                             new QTableWidgetItem(QString::number(s, 'f', 2)));
  }
  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  totalSum += overpayment;
  monthlyPayment.append("... ");
  monthlyPayment.append(QString::number(payment, 'f', 2));
  QString totalSum_str = QString::number(totalSum, 'f', 2);
  QString overpayment_str = QString::number(overpayment, 'f', 2);
  emit sendCreditSummary(monthlyPayment, totalSum_str, overpayment_str);
}
