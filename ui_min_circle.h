/********************************************************************************
** Form generated from reading UI file 'min_circle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIN_CIRCLE_H
#define UI_MIN_CIRCLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MinCircle
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QLabel *responseLabel;
    QLabel *cursorPositionLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *calculateButton;
    QPushButton *clearButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MinCircle)
    {
        if (MinCircle->objectName().isEmpty())
            MinCircle->setObjectName(QString::fromUtf8("MinCircle"));
        MinCircle->resize(535, 632);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MinCircle->sizePolicy().hasHeightForWidth());
        MinCircle->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MinCircle);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(graphicsView);

        responseLabel = new QLabel(centralWidget);
        responseLabel->setObjectName(QString::fromUtf8("responseLabel"));

        verticalLayout->addWidget(responseLabel);

        cursorPositionLabel = new QLabel(centralWidget);
        cursorPositionLabel->setObjectName(QString::fromUtf8("cursorPositionLabel"));

        verticalLayout->addWidget(cursorPositionLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        calculateButton = new QPushButton(centralWidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));

        horizontalLayout->addWidget(calculateButton);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout->addWidget(clearButton);


        verticalLayout->addLayout(horizontalLayout);

        MinCircle->setCentralWidget(centralWidget);
        menubar = new QMenuBar(MinCircle);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 535, 22));
        MinCircle->setMenuBar(menubar);
        statusbar = new QStatusBar(MinCircle);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MinCircle->setStatusBar(statusbar);

        retranslateUi(MinCircle);

        QMetaObject::connectSlotsByName(MinCircle);
    } // setupUi

    void retranslateUi(QMainWindow *MinCircle)
    {
        MinCircle->setWindowTitle(QCoreApplication::translate("MinCircle", "MinCircle", nullptr));
        responseLabel->setText(QCoreApplication::translate("MinCircle", "TextLabel", nullptr));
        cursorPositionLabel->setText(QCoreApplication::translate("MinCircle", "Mouse position: x, y", nullptr));
        calculateButton->setText(QCoreApplication::translate("MinCircle", "Calc", nullptr));
        clearButton->setText(QCoreApplication::translate("MinCircle", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MinCircle: public Ui_MinCircle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIN_CIRCLE_H
