/********************************************************************************
** Form generated from reading UI file 'scale.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALE_H
#define UI_SCALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Scale
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_xMax;
    QLabel *label_3;
    QLineEdit *lineEdit_yMin;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_yMax;
    QLineEdit *lineEdit_xMin;
    QLabel *label;
    QPushButton *pushButton_drawGraph;

    void setupUi(QDialog *Scale)
    {
        if (Scale->objectName().isEmpty())
            Scale->setObjectName("Scale");
        Scale->resize(320, 240);
        gridLayout = new QGridLayout(Scale);
        gridLayout->setObjectName("gridLayout");
        lineEdit_xMax = new QLineEdit(Scale);
        lineEdit_xMax->setObjectName("lineEdit_xMax");
        lineEdit_xMax->setMaxLength(8);

        gridLayout->addWidget(lineEdit_xMax, 3, 5, 1, 1);

        label_3 = new QLabel(Scale);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_yMin = new QLineEdit(Scale);
        lineEdit_yMin->setObjectName("lineEdit_yMin");
        lineEdit_yMin->setMaxLength(8);

        gridLayout->addWidget(lineEdit_yMin, 1, 1, 1, 1);

        label_2 = new QLabel(Scale);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(Scale);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 3, 1, 2);

        lineEdit_yMax = new QLineEdit(Scale);
        lineEdit_yMax->setObjectName("lineEdit_yMax");
        lineEdit_yMax->setMaxLength(8);

        gridLayout->addWidget(lineEdit_yMax, 0, 1, 1, 1);

        lineEdit_xMin = new QLineEdit(Scale);
        lineEdit_xMin->setObjectName("lineEdit_xMin");
        lineEdit_xMin->setMaxLength(8);

        gridLayout->addWidget(lineEdit_xMin, 3, 1, 1, 1);

        label = new QLabel(Scale);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_drawGraph = new QPushButton(Scale);
        pushButton_drawGraph->setObjectName("pushButton_drawGraph");

        gridLayout->addWidget(pushButton_drawGraph, 4, 0, 1, 6);


        retranslateUi(Scale);

        QMetaObject::connectSlotsByName(Scale);
    } // setupUi

    void retranslateUi(QDialog *Scale)
    {
        Scale->setWindowTitle(QCoreApplication::translate("Scale", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Scale", "min x", nullptr));
        label_2->setText(QCoreApplication::translate("Scale", "min y", nullptr));
        label_4->setText(QCoreApplication::translate("Scale", "max x", nullptr));
        label->setText(QCoreApplication::translate("Scale", "max y", nullptr));
        pushButton_drawGraph->setText(QCoreApplication::translate("Scale", "Draw Graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scale: public Ui_Scale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALE_H
