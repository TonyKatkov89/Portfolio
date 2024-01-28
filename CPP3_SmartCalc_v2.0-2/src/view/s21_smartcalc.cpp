#include "s21_smartcalc.h"

#include "./ui_s21_smartcalc.h"

S21_SmartCalc::S21_SmartCalc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::S21_SmartCalc) {
  ui->setupUi(this);
  QDoubleValidator *xValidator = new QDoubleValidator();
  xValidator->setLocale(QLocale("en_US"));
  ui->lineEdit_x->setValidator(xValidator);
  ui->lineEdit_x->insert("0");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Enter) {
    on_pushButton_exe_clicked();
  }
}

S21_SmartCalc::~S21_SmartCalc() { delete ui; }

void S21_SmartCalc::on_pushButton_exe_clicked() {
  double x = ui->lineEdit_x->text().toDouble();
  field = ui->lineEdit->text();
  std::string input = field.toStdString();
  ui->lineEdit->clear();
  s21::CalcController calc(input);
  double result = calc.Result(x);
  int dec = 7;
  field = QString::number(result, 'f', dec);
  for (int i = 0; field[field.size() - 1 - i] == '0'; i++) {
    dec--;
  }
  field = QString::number(result, 'f', dec);
  ui->lineEdit->insert(field);
}

void S21_SmartCalc::on_pushButton_graph_clicked() {
  field = ui->lineEdit->text();
  window = new Scale(this);
  window->show();
  connect(this, &S21_SmartCalc::sendFormulaToScale, window,
          &Scale::receiveFormula);
  emit sendFormulaToScale(field);
}

void S21_SmartCalc::on_actionMortgage_triggered() {
  Mortgage *mortgage = new Mortgage();
  mortgage->show();
  close();
}

void S21_SmartCalc::on_pushButton_1_clicked() {
  ui->lineEdit->insert("1");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_2_clicked() {
  ui->lineEdit->insert("2");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_3_clicked() {
  ui->lineEdit->insert("3");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_4_clicked() {
  ui->lineEdit->insert("4");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_5_clicked() {
  ui->lineEdit->insert("5");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_6_clicked() {
  ui->lineEdit->insert("6");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_7_clicked() {
  ui->lineEdit->insert("7");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_8_clicked() {
  ui->lineEdit->insert("8");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_9_clicked() {
  ui->lineEdit->insert("9");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_0_clicked() {
  ui->lineEdit->insert("0");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_dot_clicked() {
  ui->lineEdit->insert(".");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_plus_clicked() {
  ui->lineEdit->insert("+");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_minus_clicked() {
  ui->lineEdit->insert("-");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_mul_clicked() {
  ui->lineEdit->insert("*");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_div_clicked() {
  ui->lineEdit->insert("/");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_ce_clicked() {
  ui->lineEdit->clear();
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_bsp_clicked() {
  ui->lineEdit->backspace();
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_root_clicked() {
  ui->lineEdit->insert("sqrt(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_pow_clicked() {
  ui->lineEdit->insert("^");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_mod_clicked() {
  ui->lineEdit->insert("mod");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_lbracket_clicked() {
  ui->lineEdit->insert("(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_rbracket_clicked() {
  ui->lineEdit->insert(")");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_log_clicked() {
  ui->lineEdit->insert("log(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_ln_clicked() {
  ui->lineEdit->insert("ln(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_atan_clicked() {
  ui->lineEdit->insert("atan(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_asin_clicked() {
  ui->lineEdit->insert("asin(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_acos_clicked() {
  ui->lineEdit->insert("acos(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_tan_clicked() {
  ui->lineEdit->insert("tan(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_sin_clicked() {
  ui->lineEdit->insert("sin(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_cos_clicked() {
  ui->lineEdit->insert("cos(");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_pushButton_x_clicked() {
  ui->lineEdit->insert("x");
  ui->lineEdit->setFocus();
}

void S21_SmartCalc::on_actionQuit_triggered() { QApplication::quit(); }
