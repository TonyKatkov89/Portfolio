/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>

#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graph {
 public:
  QGridLayout *gridLayout;
  QCustomPlot *widget;

  void setupUi(QDialog *Graph) {
    if (Graph->objectName().isEmpty())
      Graph->setObjectName(QString::fromUtf8("Graph"));
    Graph->resize(640, 480);
    gridLayout = new QGridLayout(Graph);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    widget = new QCustomPlot(Graph);
    widget->setObjectName(QString::fromUtf8("widget"));

    gridLayout->addWidget(widget, 0, 0, 1, 1);

    retranslateUi(Graph);

    QMetaObject::connectSlotsByName(Graph);
  }  // setupUi

  void retranslateUi(QDialog *Graph) {
    Graph->setWindowTitle(
        QCoreApplication::translate("Graph", "Dialog", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Graph : public Ui_Graph {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_GRAPH_H
