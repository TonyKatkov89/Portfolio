#include "mortgage.h"

#include "ui_mortgage.h"

Mortgage::Mortgage(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Mortgage) {
  ui->setupUi(this);
  this->setWindowTitle("S21_SmartCalc");
  QDoubleValidator *loanValidator = new QDoubleValidator(1, 100000000, 2, this);
  loanValidator->setLocale(QLocale("en_US"));
  QDoubleValidator *interestValidator = new QDoubleValidator(0, 100, 2, this);
  interestValidator->setLocale(QLocale("en_US"));
  ui->lineEdit_loanValue->setValidator(loanValidator);
  ui->lineEdit_term->setValidator(new QIntValidator(1, 360, this));
  ui->lineEdit_interest->setValidator(interestValidator);
  ui->lineEdit_loanValue->insert("1000000");
  ui->lineEdit_term->insert("60");
  ui->lineEdit_interest->insert("10");
  ui->dateEdit->setDate(QDate::currentDate());
}

Mortgage::~Mortgage() { delete ui; }

void Mortgage::on_actionQuit_triggered() { QApplication::quit(); }

void Mortgage::on_actionStandard_triggered() {
  S21_SmartCalc *smartcalc = new S21_SmartCalc();
  smartcalc->show();
  close();
}

void Mortgage::on_pushButton_clicked() {
  double s, p, n;
  QDate startDate;
  s = ui->lineEdit_loanValue->text().toDouble();
  p = ui->lineEdit_interest->text().toDouble() / 100;
  n = ui->lineEdit_term->text().toDouble();
  startDate = ui->dateEdit->date();
  CreditPayments *payments = new CreditPayments(this);
  payments->show();
  connect(payments, &CreditPayments::sendCreditSummary, this,
          &Mortgage::showCreditSummary);
  if (ui->comboBox_type->currentText() == "annuity") {
    connect(this, &Mortgage::sendLoanCalculationData, payments,
            &CreditPayments::receiveAnnuityData);
  }
  if (ui->comboBox_type->currentText() == "differential") {
    connect(this, &Mortgage::sendLoanCalculationData, payments,
            &CreditPayments::receiveDifferentiatedData);
  }
  emit sendLoanCalculationData(s, p, n, startDate);
}

void Mortgage::showCreditSummary(QString monthlyPayment, QString totalSum,
                                 QString overpayment) {
  ui->label_monFee->setText(monthlyPayment);
  ui->label_loanSum->setText(totalSum);
  ui->label_overay->setText(overpayment);
}
