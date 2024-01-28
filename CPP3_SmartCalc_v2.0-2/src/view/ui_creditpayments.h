/********************************************************************************
** Form generated from reading UI file 'creditpayments.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITPAYMENTS_H
#define UI_CREDITPAYMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CreditPayments {
 public:
  QHBoxLayout *horizontalLayout;
  QTableWidget *tableWidget;

  void setupUi(QDialog *CreditPayments) {
    if (CreditPayments->objectName().isEmpty())
      CreditPayments->setObjectName("CreditPayments");
    CreditPayments->resize(670, 640);
    horizontalLayout = new QHBoxLayout(CreditPayments);
    horizontalLayout->setObjectName("horizontalLayout");
    tableWidget = new QTableWidget(CreditPayments);
    if (tableWidget->columnCount() < 5) tableWidget->setColumnCount(5);
    QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
    QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
    QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
    QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
    QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
    tableWidget->setObjectName("tableWidget");
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding,
                           QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
    tableWidget->setSizePolicy(sizePolicy);
    tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
    tableWidget->horizontalHeader()->setDefaultSectionSize(120);
    tableWidget->verticalHeader()->setCascadingSectionResizes(true);

    horizontalLayout->addWidget(tableWidget);

    retranslateUi(CreditPayments);

    QMetaObject::connectSlotsByName(CreditPayments);
  }  // setupUi

  void retranslateUi(QDialog *CreditPayments) {
    CreditPayments->setWindowTitle(
        QCoreApplication::translate("CreditPayments", "Dialog", nullptr));
    QTableWidgetItem *___qtablewidgetitem =
        tableWidget->horizontalHeaderItem(0);
    ___qtablewidgetitem->setText(
        QCoreApplication::translate("CreditPayments", "Payment date", nullptr));
    QTableWidgetItem *___qtablewidgetitem1 =
        tableWidget->horizontalHeaderItem(1);
    ___qtablewidgetitem1->setText(
        QCoreApplication::translate("CreditPayments", "Payment Sum", nullptr));
    QTableWidgetItem *___qtablewidgetitem2 =
        tableWidget->horizontalHeaderItem(2);
    ___qtablewidgetitem2->setText(
        QCoreApplication::translate("CreditPayments", "Loan Body", nullptr));
    QTableWidgetItem *___qtablewidgetitem3 =
        tableWidget->horizontalHeaderItem(3);
    ___qtablewidgetitem3->setText(QCoreApplication::translate(
        "CreditPayments", "Interest Coverage", nullptr));
    QTableWidgetItem *___qtablewidgetitem4 =
        tableWidget->horizontalHeaderItem(4);
    ___qtablewidgetitem4->setText(QCoreApplication::translate(
        "CreditPayments", "Reamining Loan", nullptr));
  }  // retranslateUi
};

namespace Ui {
class CreditPayments : public Ui_CreditPayments {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_CREDITPAYMENTS_H
