#include <QApplication>

#include "s21_smartcalc.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  S21_SmartCalc w;
  w.show();
  return a.exec();
}
