#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H

#include "qvalidator.h"
#include "scale.h"
#include <QKeyEvent>
#include <QMainWindow>
#include <string.h>

#include "mortgage.h"

extern "C" {
#include "calculation.h"
#include "parcing.h"
#include "structs.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class S21_SmartCalc;
}
QT_END_NAMESPACE

class S21_SmartCalc : public QMainWindow {
  Q_OBJECT

public:
  void keyPressEvent(QKeyEvent *event);
  S21_SmartCalc(QWidget *parent = nullptr);
  ~S21_SmartCalc();

private slots:

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_0_clicked();

  void on_pushButton_dot_clicked();

  void on_pushButton_plus_clicked();

  void on_pushButton_minus_clicked();

  void on_pushButton_mul_clicked();

  void on_pushButton_div_clicked();

  void on_pushButton_bsp_clicked();

  void on_pushButton_1_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_root_clicked();

  void on_pushButton_pow_clicked();

  void on_pushButton_mod_clicked();

  void on_pushButton_ce_clicked();

  void on_pushButton_lbracket_clicked();

  void on_pushButton_rbracket_clicked();

  void on_pushButton_log_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_atan_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_exe_clicked();

  void on_pushButton_graph_clicked();

  void on_pushButton_asin_clicked();

  void on_actionQuit_triggered();

  void on_actionMortgage_triggered();

  void on_pushButton_x_clicked();

private:
  Ui::S21_SmartCalc *ui;
  QString field;
  Scale *window;

signals:
  void sendFormulaToScale(QString formula);
};
#endif // S21_SMARTCALC_H
