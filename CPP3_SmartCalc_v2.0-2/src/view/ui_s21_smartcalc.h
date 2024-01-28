/********************************************************************************
** Form generated from reading UI file 's21_smartcalc.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S21_SMARTCALC_H
#define UI_S21_SMARTCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_S21_SmartCalc {
 public:
  QAction *actionQuit;
  QAction *actionStandard;
  QAction *actionMortgage;
  QAction *actionDeposit;
  QAction *actionThere_is_no_help;
  QWidget *centralwidget;
  QGridLayout *gridLayout;
  QPushButton *pushButton_dot;
  QPushButton *pushButton_9;
  QPushButton *pushButton_3;
  QPushButton *pushButton_tan;
  QPushButton *pushButton_8;
  QPushButton *pushButton_2;
  QPushButton *pushButton_5;
  QPushButton *pushButton_4;
  QPushButton *pushButton_ce;
  QPushButton *pushButton_0;
  QPushButton *pushButton_6;
  QPushButton *pushButton_7;
  QPushButton *pushButton_1;
  QPushButton *pushButton_bsp;
  QPushButton *pushButton_div;
  QPushButton *pushButton_mul;
  QPushButton *pushButton_minus;
  QPushButton *pushButton_plus;
  QPushButton *pushButton_pow;
  QPushButton *pushButton_mod;
  QPushButton *pushButton_root;
  QPushButton *pushButton_lbracket;
  QPushButton *pushButton_rbracket;
  QPushButton *pushButton_cos;
  QPushButton *pushButton_sin;
  QPushButton *pushButton_atan;
  QPushButton *pushButton_asin;
  QLineEdit *lineEdit_x;
  QPushButton *pushButton_log;
  QPushButton *pushButton_ln;
  QPushButton *pushButton_x;
  QPushButton *pushButton_graph;
  QPushButton *pushButton_exe;
  QPushButton *pushButton_acos;
  QLineEdit *lineEdit;
  QMenuBar *menubar;
  QMenu *menuFile;
  QMenu *menuView;
  QMenu *menuHelp;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *S21_SmartCalc) {
    if (S21_SmartCalc->objectName().isEmpty())
      S21_SmartCalc->setObjectName(QString::fromUtf8("S21_SmartCalc"));
    S21_SmartCalc->resize(839, 563);
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
    S21_SmartCalc->setPalette(palette);
    S21_SmartCalc->setAutoFillBackground(false);
    actionQuit = new QAction(S21_SmartCalc);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionStandard = new QAction(S21_SmartCalc);
    actionStandard->setObjectName(QString::fromUtf8("actionStandard"));
    actionMortgage = new QAction(S21_SmartCalc);
    actionMortgage->setObjectName(QString::fromUtf8("actionMortgage"));
    actionDeposit = new QAction(S21_SmartCalc);
    actionDeposit->setObjectName(QString::fromUtf8("actionDeposit"));
    actionThere_is_no_help = new QAction(S21_SmartCalc);
    actionThere_is_no_help->setObjectName(
        QString::fromUtf8("actionThere_is_no_help"));
    centralwidget = new QWidget(S21_SmartCalc);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    pushButton_dot = new QPushButton(centralwidget);
    pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding,
                           QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(
        pushButton_dot->sizePolicy().hasHeightForWidth());
    pushButton_dot->setSizePolicy(sizePolicy);
    pushButton_dot->setMinimumSize(QSize(20, 15));
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
    pushButton_dot->setPalette(palette1);
    QFont font;
    font.setFamilies({QString::fromUtf8("Arial")});
    font.setPointSize(14);
    pushButton_dot->setFont(font);
    pushButton_dot->setLayoutDirection(Qt::LeftToRight);
    pushButton_dot->setAutoFillBackground(false);
    pushButton_dot->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_dot, 7, 0, 1, 1);

    pushButton_9 = new QPushButton(centralwidget);
    pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
    sizePolicy.setHeightForWidth(
        pushButton_9->sizePolicy().hasHeightForWidth());
    pushButton_9->setSizePolicy(sizePolicy);
    pushButton_9->setMinimumSize(QSize(20, 15));
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
    pushButton_9->setPalette(palette2);
    pushButton_9->setFont(font);
    pushButton_9->setLayoutDirection(Qt::LeftToRight);
    pushButton_9->setAutoFillBackground(false);
    pushButton_9->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_9, 4, 2, 1, 1);

    pushButton_3 = new QPushButton(centralwidget);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    sizePolicy.setHeightForWidth(
        pushButton_3->sizePolicy().hasHeightForWidth());
    pushButton_3->setSizePolicy(sizePolicy);
    pushButton_3->setMinimumSize(QSize(20, 15));
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
    pushButton_3->setPalette(palette3);
    pushButton_3->setFont(font);
    pushButton_3->setLayoutDirection(Qt::LeftToRight);
    pushButton_3->setAutoFillBackground(false);
    pushButton_3->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_3, 6, 2, 1, 1);

    pushButton_tan = new QPushButton(centralwidget);
    pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
    sizePolicy.setHeightForWidth(
        pushButton_tan->sizePolicy().hasHeightForWidth());
    pushButton_tan->setSizePolicy(sizePolicy);
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
    pushButton_tan->setPalette(palette4);
    pushButton_tan->setFont(font);
    pushButton_tan->setAutoFillBackground(false);
    pushButton_tan->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_tan, 4, 4, 1, 1);

    pushButton_8 = new QPushButton(centralwidget);
    pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
    sizePolicy.setHeightForWidth(
        pushButton_8->sizePolicy().hasHeightForWidth());
    pushButton_8->setSizePolicy(sizePolicy);
    pushButton_8->setMinimumSize(QSize(20, 15));
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
    pushButton_8->setPalette(palette5);
    pushButton_8->setFont(font);
    pushButton_8->setLayoutDirection(Qt::LeftToRight);
    pushButton_8->setAutoFillBackground(false);
    pushButton_8->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_8, 4, 1, 1, 1);

    pushButton_2 = new QPushButton(centralwidget);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    sizePolicy.setHeightForWidth(
        pushButton_2->sizePolicy().hasHeightForWidth());
    pushButton_2->setSizePolicy(sizePolicy);
    pushButton_2->setMinimumSize(QSize(20, 15));
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
    pushButton_2->setPalette(palette6);
    pushButton_2->setFont(font);
    pushButton_2->setLayoutDirection(Qt::LeftToRight);
    pushButton_2->setAutoFillBackground(false);
    pushButton_2->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_2, 6, 1, 1, 1);

    pushButton_5 = new QPushButton(centralwidget);
    pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
    sizePolicy.setHeightForWidth(
        pushButton_5->sizePolicy().hasHeightForWidth());
    pushButton_5->setSizePolicy(sizePolicy);
    pushButton_5->setMinimumSize(QSize(20, 15));
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
    pushButton_5->setPalette(palette7);
    pushButton_5->setFont(font);
    pushButton_5->setLayoutDirection(Qt::LeftToRight);
    pushButton_5->setAutoFillBackground(false);
    pushButton_5->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_5, 5, 1, 1, 1);

    pushButton_4 = new QPushButton(centralwidget);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
    sizePolicy.setHeightForWidth(
        pushButton_4->sizePolicy().hasHeightForWidth());
    pushButton_4->setSizePolicy(sizePolicy);
    pushButton_4->setMinimumSize(QSize(20, 15));
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
    pushButton_4->setPalette(palette8);
    pushButton_4->setFont(font);
    pushButton_4->setLayoutDirection(Qt::LeftToRight);
    pushButton_4->setAutoFillBackground(false);
    pushButton_4->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_4, 5, 0, 1, 1);

    pushButton_ce = new QPushButton(centralwidget);
    pushButton_ce->setObjectName(QString::fromUtf8("pushButton_ce"));
    sizePolicy.setHeightForWidth(
        pushButton_ce->sizePolicy().hasHeightForWidth());
    pushButton_ce->setSizePolicy(sizePolicy);
    pushButton_ce->setMinimumSize(QSize(20, 15));
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
    pushButton_ce->setPalette(palette9);
    pushButton_ce->setFont(font);
    pushButton_ce->setLayoutDirection(Qt::LeftToRight);
    pushButton_ce->setAutoFillBackground(false);
    pushButton_ce->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_ce, 1, 0, 1, 1);

    pushButton_0 = new QPushButton(centralwidget);
    pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
    sizePolicy.setHeightForWidth(
        pushButton_0->sizePolicy().hasHeightForWidth());
    pushButton_0->setSizePolicy(sizePolicy);
    pushButton_0->setMinimumSize(QSize(20, 15));
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
    pushButton_0->setPalette(palette10);
    pushButton_0->setFont(font);
    pushButton_0->setLayoutDirection(Qt::LeftToRight);
    pushButton_0->setAutoFillBackground(false);
    pushButton_0->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_0, 7, 1, 1, 1);

    pushButton_6 = new QPushButton(centralwidget);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
    sizePolicy.setHeightForWidth(
        pushButton_6->sizePolicy().hasHeightForWidth());
    pushButton_6->setSizePolicy(sizePolicy);
    pushButton_6->setMinimumSize(QSize(20, 15));
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
    pushButton_6->setPalette(palette11);
    pushButton_6->setFont(font);
    pushButton_6->setLayoutDirection(Qt::LeftToRight);
    pushButton_6->setAutoFillBackground(false);
    pushButton_6->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_6, 5, 2, 1, 1);

    pushButton_7 = new QPushButton(centralwidget);
    pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
    sizePolicy.setHeightForWidth(
        pushButton_7->sizePolicy().hasHeightForWidth());
    pushButton_7->setSizePolicy(sizePolicy);
    pushButton_7->setMinimumSize(QSize(20, 15));
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
    pushButton_7->setPalette(palette12);
    pushButton_7->setFont(font);
    pushButton_7->setLayoutDirection(Qt::LeftToRight);
    pushButton_7->setAutoFillBackground(false);
    pushButton_7->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_7, 4, 0, 1, 1);

    pushButton_1 = new QPushButton(centralwidget);
    pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
    sizePolicy.setHeightForWidth(
        pushButton_1->sizePolicy().hasHeightForWidth());
    pushButton_1->setSizePolicy(sizePolicy);
    pushButton_1->setMinimumSize(QSize(20, 15));
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
    pushButton_1->setPalette(palette13);
    pushButton_1->setFont(font);
    pushButton_1->setLayoutDirection(Qt::LeftToRight);
    pushButton_1->setAutoFillBackground(false);
    pushButton_1->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_1, 6, 0, 1, 1);

    pushButton_bsp = new QPushButton(centralwidget);
    pushButton_bsp->setObjectName(QString::fromUtf8("pushButton_bsp"));
    sizePolicy.setHeightForWidth(
        pushButton_bsp->sizePolicy().hasHeightForWidth());
    pushButton_bsp->setSizePolicy(sizePolicy);
    pushButton_bsp->setMinimumSize(QSize(20, 15));
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
    pushButton_bsp->setPalette(palette14);
    pushButton_bsp->setFont(font);
    pushButton_bsp->setLayoutDirection(Qt::LeftToRight);
    pushButton_bsp->setAutoFillBackground(false);
    pushButton_bsp->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_bsp, 7, 2, 1, 1);

    pushButton_div = new QPushButton(centralwidget);
    pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
    sizePolicy.setHeightForWidth(
        pushButton_div->sizePolicy().hasHeightForWidth());
    pushButton_div->setSizePolicy(sizePolicy);
    pushButton_div->setMinimumSize(QSize(20, 15));
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
    pushButton_div->setPalette(palette15);
    pushButton_div->setFont(font);
    pushButton_div->setLayoutDirection(Qt::LeftToRight);
    pushButton_div->setAutoFillBackground(false);
    pushButton_div->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_div, 2, 1, 1, 1);

    pushButton_mul = new QPushButton(centralwidget);
    pushButton_mul->setObjectName(QString::fromUtf8("pushButton_mul"));
    sizePolicy.setHeightForWidth(
        pushButton_mul->sizePolicy().hasHeightForWidth());
    pushButton_mul->setSizePolicy(sizePolicy);
    pushButton_mul->setMinimumSize(QSize(20, 15));
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
    pushButton_mul->setPalette(palette16);
    pushButton_mul->setFont(font);
    pushButton_mul->setLayoutDirection(Qt::LeftToRight);
    pushButton_mul->setAutoFillBackground(false);
    pushButton_mul->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_mul, 2, 2, 1, 1);

    pushButton_minus = new QPushButton(centralwidget);
    pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
    sizePolicy.setHeightForWidth(
        pushButton_minus->sizePolicy().hasHeightForWidth());
    pushButton_minus->setSizePolicy(sizePolicy);
    pushButton_minus->setMinimumSize(QSize(20, 15));
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
    pushButton_minus->setPalette(palette17);
    pushButton_minus->setFont(font);
    pushButton_minus->setLayoutDirection(Qt::LeftToRight);
    pushButton_minus->setAutoFillBackground(false);
    pushButton_minus->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_minus, 2, 3, 1, 1);

    pushButton_plus = new QPushButton(centralwidget);
    pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
    sizePolicy.setHeightForWidth(
        pushButton_plus->sizePolicy().hasHeightForWidth());
    pushButton_plus->setSizePolicy(sizePolicy);
    pushButton_plus->setMinimumSize(QSize(20, 15));
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
    pushButton_plus->setPalette(palette18);
    pushButton_plus->setFont(font);
    pushButton_plus->setLayoutDirection(Qt::LeftToRight);
    pushButton_plus->setAutoFillBackground(false);
    pushButton_plus->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_plus, 4, 3, 1, 1);

    pushButton_pow = new QPushButton(centralwidget);
    pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
    sizePolicy.setHeightForWidth(
        pushButton_pow->sizePolicy().hasHeightForWidth());
    pushButton_pow->setSizePolicy(sizePolicy);
    pushButton_pow->setMinimumSize(QSize(20, 15));
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
    pushButton_pow->setPalette(palette19);
    pushButton_pow->setFont(font);
    pushButton_pow->setLayoutDirection(Qt::LeftToRight);
    pushButton_pow->setAutoFillBackground(false);
    pushButton_pow->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_pow, 5, 3, 1, 1);

    pushButton_mod = new QPushButton(centralwidget);
    pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
    sizePolicy.setHeightForWidth(
        pushButton_mod->sizePolicy().hasHeightForWidth());
    pushButton_mod->setSizePolicy(sizePolicy);
    QPalette palette20;
    palette20.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette20.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette20.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette20.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette20.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette20.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette20.setBrush(QPalette::Active, QPalette::Text, brush);
    palette20.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette20.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette20.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette20.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette20.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette20.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette20.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette20.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette20.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette20.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette20.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette20.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette20.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette20.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette20.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette20.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette20.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette20.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette20.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette20.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette20.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette20.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette20.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette20.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette20.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette20.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette20.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette20.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette20.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette20.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette20.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette20.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette20.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette20.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette20.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette20.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_mod->setPalette(palette20);
    pushButton_mod->setFont(font);
    pushButton_mod->setAutoFillBackground(false);
    pushButton_mod->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_mod, 1, 1, 1, 1);

    pushButton_root = new QPushButton(centralwidget);
    pushButton_root->setObjectName(QString::fromUtf8("pushButton_root"));
    sizePolicy.setHeightForWidth(
        pushButton_root->sizePolicy().hasHeightForWidth());
    pushButton_root->setSizePolicy(sizePolicy);
    pushButton_root->setMinimumSize(QSize(20, 15));
    QPalette palette21;
    palette21.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette21.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette21.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette21.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette21.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette21.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette21.setBrush(QPalette::Active, QPalette::Text, brush);
    palette21.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette21.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette21.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette21.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette21.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette21.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette21.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette21.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette21.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette21.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette21.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette21.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette21.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette21.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette21.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette21.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette21.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette21.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette21.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette21.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette21.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette21.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette21.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette21.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette21.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette21.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette21.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette21.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette21.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette21.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette21.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette21.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette21.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette21.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette21.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette21.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_root->setPalette(palette21);
    pushButton_root->setFont(font);
    pushButton_root->setLayoutDirection(Qt::LeftToRight);
    pushButton_root->setAutoFillBackground(false);
    pushButton_root->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_root, 2, 0, 1, 1);

    pushButton_lbracket = new QPushButton(centralwidget);
    pushButton_lbracket->setObjectName(
        QString::fromUtf8("pushButton_lbracket"));
    sizePolicy.setHeightForWidth(
        pushButton_lbracket->sizePolicy().hasHeightForWidth());
    pushButton_lbracket->setSizePolicy(sizePolicy);
    QPalette palette22;
    palette22.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette22.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette22.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette22.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette22.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette22.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette22.setBrush(QPalette::Active, QPalette::Text, brush);
    palette22.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette22.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette22.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette22.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette22.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette22.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette22.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette22.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette22.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette22.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette22.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette22.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette22.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette22.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette22.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette22.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette22.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette22.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette22.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette22.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette22.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette22.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette22.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette22.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette22.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette22.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette22.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette22.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette22.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette22.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette22.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette22.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette22.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette22.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette22.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette22.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_lbracket->setPalette(palette22);
    pushButton_lbracket->setFont(font);
    pushButton_lbracket->setAutoFillBackground(false);
    pushButton_lbracket->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_lbracket, 1, 2, 1, 1);

    pushButton_rbracket = new QPushButton(centralwidget);
    pushButton_rbracket->setObjectName(
        QString::fromUtf8("pushButton_rbracket"));
    sizePolicy.setHeightForWidth(
        pushButton_rbracket->sizePolicy().hasHeightForWidth());
    pushButton_rbracket->setSizePolicy(sizePolicy);
    QPalette palette23;
    palette23.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette23.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette23.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette23.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette23.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette23.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette23.setBrush(QPalette::Active, QPalette::Text, brush);
    palette23.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette23.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette23.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette23.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette23.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette23.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette23.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette23.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette23.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette23.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette23.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette23.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette23.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette23.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette23.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette23.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette23.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette23.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette23.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette23.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette23.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette23.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette23.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette23.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette23.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette23.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette23.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette23.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette23.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette23.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette23.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette23.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette23.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette23.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette23.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette23.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_rbracket->setPalette(palette23);
    pushButton_rbracket->setFont(font);
    pushButton_rbracket->setAutoFillBackground(false);
    pushButton_rbracket->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_rbracket, 1, 3, 1, 1);

    pushButton_cos = new QPushButton(centralwidget);
    pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
    sizePolicy.setHeightForWidth(
        pushButton_cos->sizePolicy().hasHeightForWidth());
    pushButton_cos->setSizePolicy(sizePolicy);
    QPalette palette24;
    palette24.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette24.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette24.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette24.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette24.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette24.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette24.setBrush(QPalette::Active, QPalette::Text, brush);
    palette24.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette24.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette24.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette24.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette24.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette24.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette24.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette24.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette24.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette24.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette24.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette24.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette24.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette24.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette24.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette24.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette24.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette24.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette24.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette24.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette24.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette24.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette24.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette24.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette24.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette24.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette24.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette24.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette24.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette24.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette24.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette24.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette24.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette24.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette24.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette24.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_cos->setPalette(palette24);
    pushButton_cos->setFont(font);
    pushButton_cos->setAutoFillBackground(false);
    pushButton_cos->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_cos, 2, 4, 1, 1);

    pushButton_sin = new QPushButton(centralwidget);
    pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
    sizePolicy.setHeightForWidth(
        pushButton_sin->sizePolicy().hasHeightForWidth());
    pushButton_sin->setSizePolicy(sizePolicy);
    QPalette palette25;
    palette25.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette25.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette25.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette25.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette25.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette25.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette25.setBrush(QPalette::Active, QPalette::Text, brush);
    palette25.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette25.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette25.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette25.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette25.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette25.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette25.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette25.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette25.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette25.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette25.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette25.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette25.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette25.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette25.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette25.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette25.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette25.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette25.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette25.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette25.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette25.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette25.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette25.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette25.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette25.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette25.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette25.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette25.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette25.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette25.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette25.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette25.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette25.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette25.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette25.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette25.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette25.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette25.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_sin->setPalette(palette25);
    pushButton_sin->setFont(font);
    pushButton_sin->setAutoFillBackground(false);
    pushButton_sin->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_sin, 1, 4, 1, 1);

    pushButton_atan = new QPushButton(centralwidget);
    pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
    sizePolicy.setHeightForWidth(
        pushButton_atan->sizePolicy().hasHeightForWidth());
    pushButton_atan->setSizePolicy(sizePolicy);
    QPalette palette26;
    palette26.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette26.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette26.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette26.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette26.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette26.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette26.setBrush(QPalette::Active, QPalette::Text, brush);
    palette26.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette26.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette26.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette26.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette26.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette26.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette26.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette26.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette26.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette26.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette26.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette26.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette26.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette26.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette26.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette26.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette26.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette26.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette26.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette26.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette26.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette26.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette26.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette26.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette26.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette26.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette26.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette26.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette26.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette26.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette26.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette26.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette26.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette26.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette26.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette26.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette26.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette26.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette26.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette26.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette26.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_atan->setPalette(palette26);
    pushButton_atan->setFont(font);
    pushButton_atan->setAutoFillBackground(false);
    pushButton_atan->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_atan, 7, 4, 1, 1);

    pushButton_asin = new QPushButton(centralwidget);
    pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
    sizePolicy.setHeightForWidth(
        pushButton_asin->sizePolicy().hasHeightForWidth());
    pushButton_asin->setSizePolicy(sizePolicy);
    QPalette palette27;
    palette27.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette27.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette27.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette27.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette27.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette27.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette27.setBrush(QPalette::Active, QPalette::Text, brush);
    palette27.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette27.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette27.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette27.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette27.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette27.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette27.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette27.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette27.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette27.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette27.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette27.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette27.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette27.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette27.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette27.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette27.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette27.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette27.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette27.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette27.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette27.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette27.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette27.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette27.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette27.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette27.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette27.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette27.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette27.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette27.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette27.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette27.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette27.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette27.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette27.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette27.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette27.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette27.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_asin->setPalette(palette27);
    pushButton_asin->setFont(font);
    pushButton_asin->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_asin, 5, 4, 1, 1);

    lineEdit_x = new QLineEdit(centralwidget);
    lineEdit_x->setObjectName(QString::fromUtf8("lineEdit_x"));

    gridLayout->addWidget(lineEdit_x, 5, 5, 1, 1);

    pushButton_log = new QPushButton(centralwidget);
    pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
    sizePolicy.setHeightForWidth(
        pushButton_log->sizePolicy().hasHeightForWidth());
    pushButton_log->setSizePolicy(sizePolicy);
    QPalette palette28;
    palette28.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette28.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette28.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette28.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette28.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette28.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette28.setBrush(QPalette::Active, QPalette::Text, brush);
    palette28.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette28.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette28.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette28.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette28.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette28.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette28.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette28.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette28.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette28.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette28.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette28.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette28.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette28.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette28.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette28.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette28.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette28.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette28.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette28.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette28.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette28.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette28.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette28.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette28.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette28.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette28.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette28.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette28.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette28.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette28.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette28.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette28.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette28.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette28.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette28.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette28.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette28.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette28.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette28.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette28.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_log->setPalette(palette28);
    pushButton_log->setFont(font);
    pushButton_log->setAutoFillBackground(false);
    pushButton_log->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_log, 1, 5, 1, 1);

    pushButton_ln = new QPushButton(centralwidget);
    pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
    sizePolicy.setHeightForWidth(
        pushButton_ln->sizePolicy().hasHeightForWidth());
    pushButton_ln->setSizePolicy(sizePolicy);
    QPalette palette29;
    palette29.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette29.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette29.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette29.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette29.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette29.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette29.setBrush(QPalette::Active, QPalette::Text, brush);
    palette29.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette29.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette29.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette29.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette29.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette29.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette29.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette29.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette29.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette29.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette29.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette29.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette29.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette29.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette29.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette29.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette29.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette29.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette29.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette29.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette29.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette29.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette29.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette29.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette29.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette29.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette29.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette29.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette29.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette29.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette29.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette29.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette29.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette29.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette29.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette29.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette29.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette29.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette29.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette29.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette29.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_ln->setPalette(palette29);
    pushButton_ln->setFont(font);
    pushButton_ln->setAutoFillBackground(false);
    pushButton_ln->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_ln, 2, 5, 1, 1);

    pushButton_x = new QPushButton(centralwidget);
    pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
    sizePolicy.setHeightForWidth(
        pushButton_x->sizePolicy().hasHeightForWidth());
    pushButton_x->setSizePolicy(sizePolicy);
    QPalette palette30;
    palette30.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette30.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette30.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette30.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette30.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette30.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette30.setBrush(QPalette::Active, QPalette::Text, brush);
    palette30.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette30.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette30.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette30.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette30.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette30.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette30.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette30.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette30.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette30.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette30.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette30.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette30.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette30.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette30.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette30.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette30.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette30.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette30.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette30.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette30.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette30.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette30.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette30.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette30.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette30.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette30.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette30.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette30.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette30.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette30.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette30.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette30.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette30.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette30.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette30.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette30.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette30.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette30.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette30.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette30.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_x->setPalette(palette30);
    pushButton_x->setFont(font);
    pushButton_x->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_x, 4, 5, 1, 1);

    pushButton_graph = new QPushButton(centralwidget);
    pushButton_graph->setObjectName(QString::fromUtf8("pushButton_graph"));
    sizePolicy.setHeightForWidth(
        pushButton_graph->sizePolicy().hasHeightForWidth());
    pushButton_graph->setSizePolicy(sizePolicy);
    pushButton_graph->setMinimumSize(QSize(20, 15));
    QPalette palette31;
    palette31.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette31.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette31.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette31.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette31.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette31.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette31.setBrush(QPalette::Active, QPalette::Text, brush);
    palette31.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette31.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette31.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette31.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette31.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette31.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette31.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette31.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette31.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette31.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette31.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette31.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette31.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette31.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette31.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette31.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette31.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette31.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette31.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette31.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette31.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette31.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette31.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette31.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette31.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette31.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette31.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette31.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette31.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette31.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette31.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette31.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette31.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette31.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette31.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette31.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette31.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette31.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette31.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette31.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette31.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_graph->setPalette(palette31);
    pushButton_graph->setFont(font);
    pushButton_graph->setLayoutDirection(Qt::LeftToRight);
    pushButton_graph->setAutoFillBackground(false);
    pushButton_graph->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_graph, 6, 5, 2, 1);

    pushButton_exe = new QPushButton(centralwidget);
    pushButton_exe->setObjectName(QString::fromUtf8("pushButton_exe"));
    sizePolicy.setHeightForWidth(
        pushButton_exe->sizePolicy().hasHeightForWidth());
    pushButton_exe->setSizePolicy(sizePolicy);
    pushButton_exe->setMinimumSize(QSize(20, 15));
    QPalette palette32;
    palette32.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette32.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette32.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette32.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette32.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette32.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette32.setBrush(QPalette::Active, QPalette::Text, brush);
    palette32.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette32.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette32.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette32.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette32.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette32.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette32.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette32.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette32.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette32.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette32.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette32.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette32.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette32.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette32.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette32.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette32.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette32.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette32.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette32.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette32.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette32.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette32.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette32.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette32.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette32.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette32.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette32.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette32.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette32.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette32.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette32.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette32.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette32.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette32.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette32.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette32.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette32.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette32.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette32.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette32.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_exe->setPalette(palette32);
    pushButton_exe->setFont(font);
    pushButton_exe->setLayoutDirection(Qt::LeftToRight);
    pushButton_exe->setAutoFillBackground(false);
    pushButton_exe->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_exe, 6, 3, 2, 1);

    pushButton_acos = new QPushButton(centralwidget);
    pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
    sizePolicy.setHeightForWidth(
        pushButton_acos->sizePolicy().hasHeightForWidth());
    pushButton_acos->setSizePolicy(sizePolicy);
    QPalette palette33;
    palette33.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette33.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette33.setBrush(QPalette::Active, QPalette::Light, brush1);
    palette33.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    palette33.setBrush(QPalette::Active, QPalette::Dark, brush2);
    palette33.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette33.setBrush(QPalette::Active, QPalette::Text, brush);
    palette33.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    palette33.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette33.setBrush(QPalette::Active, QPalette::Base, brush1);
    palette33.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette33.setBrush(QPalette::Active, QPalette::Shadow, brush);
    palette33.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    palette33.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    palette33.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette33.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    palette33.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette33.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette33.setBrush(QPalette::Inactive, QPalette::Light, brush1);
    palette33.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
    palette33.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
    palette33.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
    palette33.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette33.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette33.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette33.setBrush(QPalette::Inactive, QPalette::Base, brush1);
    palette33.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette33.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette33.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
    palette33.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
    palette33.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette33.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
    palette33.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette33.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette33.setBrush(QPalette::Disabled, QPalette::Light, brush1);
    palette33.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette33.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette33.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette33.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette33.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    palette33.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette33.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette33.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette33.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette33.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette33.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
    palette33.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette33.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
    pushButton_acos->setPalette(palette33);
    pushButton_acos->setFont(font);
    pushButton_acos->setAutoFillBackground(false);
    pushButton_acos->setStyleSheet(QString::fromUtf8(""));

    gridLayout->addWidget(pushButton_acos, 6, 4, 1, 1);

    lineEdit = new QLineEdit(centralwidget);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setMinimumSize(QSize(100, 80));
    QFont font1;
    font1.setFamilies({QString::fromUtf8("Kristen ITC")});
    font1.setPointSize(16);
    lineEdit->setFont(font1);
    lineEdit->setLayoutDirection(Qt::RightToLeft);
    lineEdit->setMaxLength(255);
    lineEdit->setClearButtonEnabled(false);

    gridLayout->addWidget(lineEdit, 0, 0, 1, 6);

    S21_SmartCalc->setCentralWidget(centralwidget);
    menubar = new QMenuBar(S21_SmartCalc);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 839, 25));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuView = new QMenu(menubar);
    menuView->setObjectName(QString::fromUtf8("menuView"));
    menuHelp = new QMenu(menubar);
    menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
    S21_SmartCalc->setMenuBar(menubar);
    statusbar = new QStatusBar(S21_SmartCalc);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    S21_SmartCalc->setStatusBar(statusbar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuView->menuAction());
    menubar->addAction(menuHelp->menuAction());
    menuFile->addAction(actionQuit);
    menuView->addAction(actionStandard);
    menuView->addAction(actionMortgage);
    menuView->addAction(actionDeposit);
    menuHelp->addAction(actionThere_is_no_help);

    retranslateUi(S21_SmartCalc);

    QMetaObject::connectSlotsByName(S21_SmartCalc);
  }  // setupUi

  void retranslateUi(QMainWindow *S21_SmartCalc) {
    S21_SmartCalc->setWindowTitle(
        QCoreApplication::translate("S21_SmartCalc", "S21_SmartCalc", nullptr));
    actionQuit->setText(
        QCoreApplication::translate("S21_SmartCalc", "Quit", nullptr));
    actionStandard->setText(
        QCoreApplication::translate("S21_SmartCalc", "Standard", nullptr));
    actionMortgage->setText(
        QCoreApplication::translate("S21_SmartCalc", "Mortgage", nullptr));
    actionDeposit->setText(
        QCoreApplication::translate("S21_SmartCalc", "Deposit", nullptr));
    actionThere_is_no_help->setText(QCoreApplication::translate(
        "S21_SmartCalc", "There is no help :(", nullptr));
    pushButton_dot->setText(
        QCoreApplication::translate("S21_SmartCalc", ".", nullptr));
    pushButton_9->setText(
        QCoreApplication::translate("S21_SmartCalc", "9", nullptr));
    pushButton_3->setText(
        QCoreApplication::translate("S21_SmartCalc", "3", nullptr));
    pushButton_tan->setText(
        QCoreApplication::translate("S21_SmartCalc", "tan", nullptr));
    pushButton_8->setText(
        QCoreApplication::translate("S21_SmartCalc", "8", nullptr));
    pushButton_2->setText(
        QCoreApplication::translate("S21_SmartCalc", "2", nullptr));
    pushButton_5->setText(
        QCoreApplication::translate("S21_SmartCalc", "5", nullptr));
    pushButton_4->setText(
        QCoreApplication::translate("S21_SmartCalc", "4", nullptr));
    pushButton_ce->setText(
        QCoreApplication::translate("S21_SmartCalc", "CE", nullptr));
    pushButton_0->setText(
        QCoreApplication::translate("S21_SmartCalc", "0", nullptr));
    pushButton_6->setText(
        QCoreApplication::translate("S21_SmartCalc", "6", nullptr));
    pushButton_7->setText(
        QCoreApplication::translate("S21_SmartCalc", "7", nullptr));
    pushButton_1->setText(
        QCoreApplication::translate("S21_SmartCalc", "1", nullptr));
    pushButton_bsp->setText(
        QCoreApplication::translate("S21_SmartCalc", "<", nullptr));
    pushButton_div->setText(
        QCoreApplication::translate("S21_SmartCalc", "/", nullptr));
    pushButton_mul->setText(
        QCoreApplication::translate("S21_SmartCalc", "*", nullptr));
    pushButton_minus->setText(
        QCoreApplication::translate("S21_SmartCalc", "-", nullptr));
    pushButton_plus->setText(
        QCoreApplication::translate("S21_SmartCalc", "+", nullptr));
    pushButton_pow->setText(
        QCoreApplication::translate("S21_SmartCalc", "^", nullptr));
    pushButton_mod->setText(
        QCoreApplication::translate("S21_SmartCalc", "mod", nullptr));
    pushButton_root->setText(
        QCoreApplication::translate("S21_SmartCalc", "sqrt", nullptr));
    pushButton_lbracket->setText(
        QCoreApplication::translate("S21_SmartCalc", "(", nullptr));
    pushButton_rbracket->setText(
        QCoreApplication::translate("S21_SmartCalc", ")", nullptr));
    pushButton_cos->setText(
        QCoreApplication::translate("S21_SmartCalc", "cos", nullptr));
    pushButton_sin->setText(
        QCoreApplication::translate("S21_SmartCalc", "sin", nullptr));
    pushButton_atan->setText(
        QCoreApplication::translate("S21_SmartCalc", "atan", nullptr));
    pushButton_asin->setText(
        QCoreApplication::translate("S21_SmartCalc", "asin", nullptr));
    pushButton_log->setText(
        QCoreApplication::translate("S21_SmartCalc", "log", nullptr));
    pushButton_ln->setText(
        QCoreApplication::translate("S21_SmartCalc", "ln", nullptr));
    pushButton_x->setText(
        QCoreApplication::translate("S21_SmartCalc", "x", nullptr));
    pushButton_graph->setText(
        QCoreApplication::translate("S21_SmartCalc", "draw graph", nullptr));
    pushButton_exe->setText(
        QCoreApplication::translate("S21_SmartCalc", "=", nullptr));
    pushButton_acos->setText(
        QCoreApplication::translate("S21_SmartCalc", "acos", nullptr));
    menuFile->setTitle(
        QCoreApplication::translate("S21_SmartCalc", "File", nullptr));
    menuView->setTitle(
        QCoreApplication::translate("S21_SmartCalc", "View", nullptr));
    menuHelp->setTitle(
        QCoreApplication::translate("S21_SmartCalc", "Help", nullptr));
  }  // retranslateUi
};

namespace Ui {
class S21_SmartCalc : public Ui_S21_SmartCalc {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_S21_SMARTCALC_H
