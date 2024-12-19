/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox_10;
    QSpinBox *spinBox_2;
    QLabel *label_14;
    QComboBox *comboBox_2;
    QSpinBox *spinBox;
    QLabel *label_8;
    QSpinBox *spinBox_6;
    QComboBox *comboBox_3;
    QSpinBox *spinBox_9;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QLabel *label_15;
    QPushButton *pushButton;
    QLabel *label_9;
    QLabel *label_11;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_11;
    QSpinBox *spinBox_5;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer;
    QLabel *image;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 192, 203, 255));\n"
""));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout_2->addWidget(widget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(12);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        spinBox_10 = new QSpinBox(centralwidget);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(spinBox_10, 7, 1, 1, 3);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(spinBox_2, 1, 2, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_14, 10, 0, 1, 1);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(comboBox_2, 5, 1, 1, 3);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(spinBox, 1, 1, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_8, 4, 0, 1, 1);

        spinBox_6 = new QSpinBox(centralwidget);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(spinBox_6, 2, 2, 1, 1);

        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(comboBox_3, 8, 1, 1, 3);

        spinBox_9 = new QSpinBox(centralwidget);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(spinBox_9, 3, 1, 1, 3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(pushButton_2, 9, 1, 1, 3);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(pushButton_3, 11, 1, 1, 3);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(comboBox, 4, 1, 1, 3);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_15, 11, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(pushButton, 6, 1, 1, 3);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_9, 5, 0, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_11, 7, 0, 1, 1);

        spinBox_4 = new QSpinBox(centralwidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(spinBox_4, 1, 3, 1, 1);

        spinBox_7 = new QSpinBox(centralwidget);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(spinBox_7, 2, 3, 1, 1);

        spinBox_11 = new QSpinBox(centralwidget);
        spinBox_11->setObjectName(QString::fromUtf8("spinBox_11"));
        spinBox_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(spinBox_11, 10, 1, 1, 3);

        spinBox_5 = new QSpinBox(centralwidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(spinBox_5, 2, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_12->setWordWrap(true);

        gridLayout_3->addWidget(label_12, 8, 0, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_13, 9, 0, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(label_10, 6, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setUnderline(false);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_4, 0, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_5, 0, 2, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(255, 255, 255);"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(label_7, 0, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_5);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer);

        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setStyleSheet(QString::fromUtf8("background: transparent;"));
        image->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(image);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 3);

        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menubar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setStyleSheet(QString::fromUtf8("background-color: rgb(118, 89, 230);\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setAutoFillBackground(false);
        statusbar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\320\241\320\277\320\273\320\276\321\210\320\275\320\260\321\217", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\320\260\321\217", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\320\270:", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));

        label_15->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\200\320\265\320\261\320\265\321\200:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \321\200\320\265\320\261\320\265\321\200:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\276\321\201\320\276\320\261 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\200\320\265\320\261\320\265\321\200:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\321\200\320\270\320\275\321\210\320\276\321\202", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        image->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
