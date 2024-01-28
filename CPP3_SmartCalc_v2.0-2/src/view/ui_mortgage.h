/********************************************************************************
** Form generated from reading UI file 'mortgage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORTGAGE_H
#define UI_MORTGAGE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mortgage {
 public:
  QAction *actionQuit;
  QAction *actionStandard;
  QAction *actionMortgage;
  QAction *actionDeposit;
  QWidget *centralwidget;
  QGridLayout *gridLayout;
  QDateEdit *dateEdit;
  QSpacerItem *verticalSpacer_3;
  QSpacerItem *verticalSpacer_2;
  QLabel *label_9;
  QLabel *label_7;
  QLabel *label_10;
  QLabel *label_6;
  QLineEdit *lineEdit_interest;
  QLabel *label;
  QLabel *label_8;
  QLabel *label_2;
  QLabel *label_3;
  QComboBox *comboBox_type;
  QLineEdit *lineEdit_term;
  QSpacerItem *verticalSpacer_5;
  QSpacerItem *verticalSpacer_4;
  QSpacerItem *verticalSpacer;
  QPushButton *pushButton;
  QLabel *label_5;
  QLabel *label_4;
  QLabel *label_overay;
  QLabel *label_monFee;
  QLabel *label_loanSum;
  QLineEdit *lineEdit_loanValue;
  QSpacerItem *verticalSpacer_6;
  QLabel *label_11;
  QMenuBar *menubar;
  QMenu *menuFile;
  QMenu *menuView;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *Mortgage) {
    if (Mortgage->objectName().isEmpty())
      Mortgage->setObjectName(QString::fromUtf8("Mortgage"));
    Mortgage->resize(640, 464);
    QPalette palette;
    QBrush brush(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(255, 255, 255, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    QBrush brush2(QColor(127, 127, 127, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
    QBrush brush3(QColor(170, 170, 170, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    QBrush brush4(QColor(255, 255, 220, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
    QBrush brush5(QColor(0, 0, 0, 127));
    brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
    QBrush brush6(QColor(127, 127, 127, 127));
    brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    Mortgage->setPalette(palette);
    actionQuit = new QAction(Mortgage);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionStandard = new QAction(Mortgage);
    actionStandard->setObjectName(QString::fromUtf8("actionStandard"));
    actionMortgage = new QAction(Mortgage);
    actionMortgage->setObjectName(QString::fromUtf8("actionMortgage"));
    actionDeposit = new QAction(Mortgage);
    actionDeposit->setObjectName(QString::fromUtf8("actionDeposit"));
    centralwidget = new QWidget(Mortgage);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    QPalette palette1;
    palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette1.setBrush(QPalette::Active, QPalette::Text, brush);
    palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    centralwidget->setPalette(palette1);
    centralwidget->setStyleSheet(QString::fromUtf8(""));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    dateEdit = new QDateEdit(centralwidget);
    dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
    dateEdit->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(dateEdit, 2, 1, 1, 1);

    verticalSpacer_3 =
        new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_3, 7, 0, 1, 1);

    verticalSpacer_2 =
        new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

    label_9 = new QLabel(centralwidget);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    QPalette palette2;
    palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette2.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette2.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette2.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette2.setBrush(QPalette::Active, QPalette::Text, brush);
    palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_9->setPalette(palette2);
    label_9->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_9, 6, 2, 1, 1);

    label_7 = new QLabel(centralwidget);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding,
                           QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
    label_7->setSizePolicy(sizePolicy);
    QPalette palette3;
    palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette3.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette3.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette3.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette3.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette3.setBrush(QPalette::Active, QPalette::Text, brush);
    palette3.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette3.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_7->setPalette(palette3);
    label_7->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_7, 11, 2, 1, 1);

    label_10 = new QLabel(centralwidget);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    QPalette palette4;
    palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette4.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette4.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette4.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette4.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette4.setBrush(QPalette::Active, QPalette::Text, brush);
    palette4.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette4.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_10->setPalette(palette4);
    label_10->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_10, 0, 2, 1, 1);

    label_6 = new QLabel(centralwidget);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
    label_6->setSizePolicy(sizePolicy);
    QPalette palette5;
    palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette5.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette5.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette5.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette5.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette5.setBrush(QPalette::Active, QPalette::Text, brush);
    palette5.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette5.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette5.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_6->setPalette(palette5);
    label_6->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_6, 11, 1, 1, 1);

    lineEdit_interest = new QLineEdit(centralwidget);
    lineEdit_interest->setObjectName(QString::fromUtf8("lineEdit_interest"));
    QPalette palette6;
    palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette6.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette6.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette6.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette6.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette6.setBrush(QPalette::Active, QPalette::Text, brush);
    palette6.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette6.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette6.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    lineEdit_interest->setPalette(palette6);
    lineEdit_interest->setAutoFillBackground(false);
    lineEdit_interest->setStyleSheet(QString::fromUtf8(""));
    lineEdit_interest->setLocale(
        QLocale(QLocale::English, QLocale::UnitedStates));

    gridLayout->addWidget(lineEdit_interest, 6, 1, 1, 1);

    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
    label->setSizePolicy(sizePolicy);
    QPalette palette7;
    palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette7.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette7.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette7.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette7.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette7.setBrush(QPalette::Active, QPalette::Text, brush);
    palette7.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette7.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette7.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette7.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label->setPalette(palette7);
    label->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    label_8 = new QLabel(centralwidget);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    QPalette palette8;
    palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette8.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette8.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette8.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette8.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette8.setBrush(QPalette::Active, QPalette::Text, brush);
    palette8.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette8.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette8.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette8.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette8.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_8->setPalette(palette8);
    label_8->setAutoFillBackground(false);
    label_8->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_8, 4, 2, 1, 1);

    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
    label_2->setSizePolicy(sizePolicy);
    QPalette palette9;
    palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette9.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette9.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette9.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette9.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette9.setBrush(QPalette::Active, QPalette::Text, brush);
    palette9.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette9.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette9.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette9.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette9.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_2->setPalette(palette9);
    label_2->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_2, 4, 0, 1, 1);

    label_3 = new QLabel(centralwidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
    label_3->setSizePolicy(sizePolicy);
    QPalette palette10;
    palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette10.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette10.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette10.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette10.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette10.setBrush(QPalette::Active, QPalette::Text, brush);
    palette10.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette10.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette10.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette10.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette10.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_3->setPalette(palette10);
    label_3->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_3, 6, 0, 1, 1);

    comboBox_type = new QComboBox(centralwidget);
    comboBox_type->addItem(QString());
    comboBox_type->addItem(QString());
    comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));
    comboBox_type->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(comboBox_type, 8, 1, 1, 1);

    lineEdit_term = new QLineEdit(centralwidget);
    lineEdit_term->setObjectName(QString::fromUtf8("lineEdit_term"));
    QPalette palette11;
    palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette11.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette11.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette11.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette11.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette11.setBrush(QPalette::Active, QPalette::Text, brush);
    palette11.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette11.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette11.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette11.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette11.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette11.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette11.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette11.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette11.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette11.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette11.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette11.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette11.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette11.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette11.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette11.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    lineEdit_term->setPalette(palette11);
    lineEdit_term->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(lineEdit_term, 4, 1, 1, 1);

    verticalSpacer_5 =
        new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_5, 14, 1, 1, 1);

    verticalSpacer_4 =
        new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_4, 9, 1, 1, 1);

    verticalSpacer =
        new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    QPalette palette12;
    palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette12.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette12.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette12.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette12.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette12.setBrush(QPalette::Active, QPalette::Text, brush);
    palette12.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette12.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette12.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette12.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette12.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette12.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette12.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette12.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton->setPalette(palette12);
    pushButton->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton, 10, 0, 1, 3);

    label_5 = new QLabel(centralwidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
    label_5->setSizePolicy(sizePolicy);
    QPalette palette13;
    palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette13.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette13.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette13.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette13.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette13.setBrush(QPalette::Active, QPalette::Text, brush);
    palette13.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette13.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette13.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette13.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette13.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_5->setPalette(palette13);
    label_5->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_5, 11, 0, 1, 1);

    label_4 = new QLabel(centralwidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
    label_4->setSizePolicy(sizePolicy);
    QPalette palette14;
    palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette14.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette14.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette14.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette14.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette14.setBrush(QPalette::Active, QPalette::Text, brush);
    palette14.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette14.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette14.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette14.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette14.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette14.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette14.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette14.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette14.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette14.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette14.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette14.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette14.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette14.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette14.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_4->setPalette(palette14);
    label_4->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_4, 8, 0, 1, 1);

    label_overay = new QLabel(centralwidget);
    label_overay->setObjectName(QString::fromUtf8("label_overay"));
    sizePolicy.setHeightForWidth(
        label_overay->sizePolicy().hasHeightForWidth());
    label_overay->setSizePolicy(sizePolicy);
    QPalette palette15;
    palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette15.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette15.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette15.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette15.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette15.setBrush(QPalette::Active, QPalette::Text, brush);
    palette15.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette15.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette15.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette15.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette15.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette15.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette15.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette15.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette15.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette15.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette15.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette15.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette15.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette15.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette15.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette15.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette15.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette15.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette15.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette15.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette15.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_overay->setPalette(palette15);
    label_overay->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_overay, 13, 1, 1, 1);

    label_monFee = new QLabel(centralwidget);
    label_monFee->setObjectName(QString::fromUtf8("label_monFee"));
    sizePolicy.setHeightForWidth(
        label_monFee->sizePolicy().hasHeightForWidth());
    label_monFee->setSizePolicy(sizePolicy);
    QPalette palette16;
    palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette16.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette16.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette16.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette16.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette16.setBrush(QPalette::Active, QPalette::Text, brush);
    palette16.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette16.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette16.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette16.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette16.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette16.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette16.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette16.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette16.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette16.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette16.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette16.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette16.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette16.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette16.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_monFee->setPalette(palette16);
    label_monFee->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_monFee, 13, 0, 1, 1);

    label_loanSum = new QLabel(centralwidget);
    label_loanSum->setObjectName(QString::fromUtf8("label_loanSum"));
    sizePolicy.setHeightForWidth(
        label_loanSum->sizePolicy().hasHeightForWidth());
    label_loanSum->setSizePolicy(sizePolicy);
    QPalette palette17;
    palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette17.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette17.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette17.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette17.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette17.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette17.setBrush(QPalette::Active, QPalette::Text, brush);
    palette17.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette17.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette17.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette17.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette17.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette17.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette17.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette17.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette17.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette17.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette17.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette17.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette17.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette17.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette17.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette17.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette17.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette17.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette17.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette17.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette17.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette17.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette17.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette17.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette17.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette17.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette17.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette17.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette17.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette17.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette17.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette17.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_loanSum->setPalette(palette17);
    label_loanSum->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_loanSum, 13, 2, 1, 1);

    lineEdit_loanValue = new QLineEdit(centralwidget);
    lineEdit_loanValue->setObjectName(QString::fromUtf8("lineEdit_loanValue"));
    QPalette palette18;
    palette18.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette18.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette18.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette18.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette18.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette18.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette18.setBrush(QPalette::Active, QPalette::Text, brush);
    palette18.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette18.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette18.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette18.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette18.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette18.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette18.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette18.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette18.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette18.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette18.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette18.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette18.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette18.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette18.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette18.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette18.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette18.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette18.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette18.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette18.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette18.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette18.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette18.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette18.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette18.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette18.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette18.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette18.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette18.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette18.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette18.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette18.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    lineEdit_loanValue->setPalette(palette18);
    lineEdit_loanValue->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(lineEdit_loanValue, 0, 1, 1, 1);

    verticalSpacer_6 =
        new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_6, 3, 1, 1, 1);

    label_11 = new QLabel(centralwidget);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    QPalette palette19;
    palette19.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette19.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette19.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette19.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette19.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette19.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette19.setBrush(QPalette::Active, QPalette::Text, brush);
    palette19.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette19.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette19.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette19.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette19.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette19.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette19.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette19.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette19.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette19.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette19.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette19.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette19.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette19.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette19.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette19.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette19.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette19.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette19.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette19.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette19.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette19.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette19.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette19.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette19.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette19.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette19.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette19.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette19.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette19.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette19.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette19.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette19.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette19.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette19.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette19.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    label_11->setPalette(palette19);
    label_11->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(label_11, 2, 0, 1, 1);

    Mortgage->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Mortgage);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 640, 25));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuView = new QMenu(menubar);
    menuView->setObjectName(QString::fromUtf8("menuView"));
    Mortgage->setMenuBar(menubar);
    statusbar = new QStatusBar(Mortgage);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    Mortgage->setStatusBar(statusbar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuView->menuAction());
    menuFile->addAction(actionQuit);
    menuView->addAction(actionStandard);
    menuView->addAction(actionMortgage);
    menuView->addAction(actionDeposit);

    retranslateUi(Mortgage);

    QMetaObject::connectSlotsByName(Mortgage);
  }  // setupUi

  void retranslateUi(QMainWindow *Mortgage) {
    Mortgage->setWindowTitle(
        QCoreApplication::translate("Mortgage", "MainWindow", nullptr));
    actionQuit->setText(
        QCoreApplication::translate("Mortgage", "Quit", nullptr));
    actionStandard->setText(
        QCoreApplication::translate("Mortgage", "Standard", nullptr));
    actionMortgage->setText(
        QCoreApplication::translate("Mortgage", "Mortgage", nullptr));
    actionDeposit->setText(
        QCoreApplication::translate("Mortgage", "Deposit", nullptr));
    label_9->setText(QCoreApplication::translate("Mortgage", "%", nullptr));
    label_7->setText(
        QCoreApplication::translate("Mortgage", "Total loan sum", nullptr));
    label_10->setText(QCoreApplication::translate("Mortgage", "RUR", nullptr));
    label_6->setText(
        QCoreApplication::translate("Mortgage", "Total overpayment", nullptr));
    label->setText(
        QCoreApplication::translate("Mortgage", "Loan value", nullptr));
    label_8->setText(
        QCoreApplication::translate("Mortgage", "months", nullptr));
    label_2->setText(QCoreApplication::translate("Mortgage", "Term", nullptr));
    label_3->setText(
        QCoreApplication::translate("Mortgage", "Interest rate", nullptr));
    comboBox_type->setItemText(
        0, QCoreApplication::translate("Mortgage", "annuity", nullptr));
    comboBox_type->setItemText(
        1, QCoreApplication::translate("Mortgage", "differential", nullptr));

    pushButton->setText(
        QCoreApplication::translate("Mortgage", "Calculate", nullptr));
    label_5->setText(
        QCoreApplication::translate("Mortgage", "Monthly payment", nullptr));
    label_4->setText(
        QCoreApplication::translate("Mortgage", "Payment type", nullptr));
    label_overay->setText(QString());
    label_monFee->setText(QString());
    label_loanSum->setText(QString());
    label_11->setText(
        QCoreApplication::translate("Mortgage", "Start date", nullptr));
    menuFile->setTitle(
        QCoreApplication::translate("Mortgage", "File", nullptr));
    menuView->setTitle(
        QCoreApplication::translate("Mortgage", "View", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Mortgage : public Ui_Mortgage {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MORTGAGE_H
