#include <QApplication>
#include <QSettings>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setOrganizationDomain("s21");
  QCoreApplication::setOrganizationName(QLatin1String("school21"));
  QCoreApplication::setApplicationName(QLatin1String("3DViewer20"));

  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
