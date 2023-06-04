/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *act_setJson;
    QAction *action_about;
    QAction *action_simpleView;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QDoubleSpinBox *doubleSpinBoxTimes;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxYuan;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnTrans;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *doubleSpinBoxOtherCurrency;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *comboBoxCurrent;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_url;
    QLineEdit *lineEditUrl;
    QPushButton *btnGetRate;
    QPushButton *btnDefaultUrl;
    QPushButton *btnOk;
    QGroupBox *groupBox_steamRate;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_steamRate;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxDeduction;
    QLabel *label_6;
    QLineEdit *lineEditDeductionResult;
    QLabel *label_7;
    QLineEdit *lineEditOriginMoney;
    QLabel *label_8;
    QLineEdit *lineEditRate;
    QGroupBox *groupBox_show;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(727, 605);
        act_setJson = new QAction(MainWindow);
        act_setJson->setObjectName(QString::fromUtf8("act_setJson"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        action_simpleView = new QAction(MainWindow);
        action_simpleView->setObjectName(QString::fromUtf8("action_simpleView"));
        action_simpleView->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("\n"
"font: 9pt \"Sarasa UI SC\";"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        doubleSpinBoxTimes = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxTimes->setObjectName(QString::fromUtf8("doubleSpinBoxTimes"));
        sizePolicy.setHeightForWidth(doubleSpinBoxTimes->sizePolicy().hasHeightForWidth());
        doubleSpinBoxTimes->setSizePolicy(sizePolicy);
        doubleSpinBoxTimes->setMaximum(1000000.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBoxTimes);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        doubleSpinBoxYuan = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxYuan->setObjectName(QString::fromUtf8("doubleSpinBoxYuan"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(doubleSpinBoxYuan->sizePolicy().hasHeightForWidth());
        doubleSpinBoxYuan->setSizePolicy(sizePolicy2);
        doubleSpinBoxYuan->setMaximum(1000000.000000000000000);

        horizontalLayout->addWidget(doubleSpinBoxYuan);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnTrans = new QPushButton(centralWidget);
        btnTrans->setObjectName(QString::fromUtf8("btnTrans"));
        sizePolicy2.setHeightForWidth(btnTrans->sizePolicy().hasHeightForWidth());
        btnTrans->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(btnTrans);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        doubleSpinBoxOtherCurrency = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxOtherCurrency->setObjectName(QString::fromUtf8("doubleSpinBoxOtherCurrency"));
        sizePolicy2.setHeightForWidth(doubleSpinBoxOtherCurrency->sizePolicy().hasHeightForWidth());
        doubleSpinBoxOtherCurrency->setSizePolicy(sizePolicy2);
        doubleSpinBoxOtherCurrency->setMaximum(10000000.000000000000000);

        horizontalLayout->addWidget(doubleSpinBoxOtherCurrency);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        comboBoxCurrent = new QComboBox(centralWidget);
        comboBoxCurrent->setObjectName(QString::fromUtf8("comboBoxCurrent"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBoxCurrent->sizePolicy().hasHeightForWidth());
        comboBoxCurrent->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(comboBoxCurrent);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_url = new QLabel(centralWidget);
        label_url->setObjectName(QString::fromUtf8("label_url"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_url->sizePolicy().hasHeightForWidth());
        label_url->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(label_url);

        lineEditUrl = new QLineEdit(centralWidget);
        lineEditUrl->setObjectName(QString::fromUtf8("lineEditUrl"));
        sizePolicy3.setHeightForWidth(lineEditUrl->sizePolicy().hasHeightForWidth());
        lineEditUrl->setSizePolicy(sizePolicy3);
        lineEditUrl->setClearButtonEnabled(true);

        horizontalLayout_4->addWidget(lineEditUrl);

        btnGetRate = new QPushButton(centralWidget);
        btnGetRate->setObjectName(QString::fromUtf8("btnGetRate"));
        sizePolicy2.setHeightForWidth(btnGetRate->sizePolicy().hasHeightForWidth());
        btnGetRate->setSizePolicy(sizePolicy2);
        btnGetRate->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"background-color: rgb(153,229,80,180);\n"
"padding:1px;\n"
"border-radius:4px;\n"
"selection-background-color: rgb(203,219,252,180);\n"
""));

        horizontalLayout_4->addWidget(btnGetRate);

        btnDefaultUrl = new QPushButton(centralWidget);
        btnDefaultUrl->setObjectName(QString::fromUtf8("btnDefaultUrl"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnDefaultUrl->sizePolicy().hasHeightForWidth());
        btnDefaultUrl->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(btnDefaultUrl);

        btnOk = new QPushButton(centralWidget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        sizePolicy5.setHeightForWidth(btnOk->sizePolicy().hasHeightForWidth());
        btnOk->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(btnOk);


        verticalLayout_3->addLayout(horizontalLayout_4);

        groupBox_steamRate = new QGroupBox(centralWidget);
        groupBox_steamRate->setObjectName(QString::fromUtf8("groupBox_steamRate"));
        verticalLayout_4 = new QVBoxLayout(groupBox_steamRate);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_steamRate = new QHBoxLayout();
        horizontalLayout_steamRate->setSpacing(6);
        horizontalLayout_steamRate->setObjectName(QString::fromUtf8("horizontalLayout_steamRate"));
        label_5 = new QLabel(groupBox_steamRate);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_steamRate->addWidget(label_5);

        doubleSpinBoxDeduction = new QDoubleSpinBox(groupBox_steamRate);
        doubleSpinBoxDeduction->setObjectName(QString::fromUtf8("doubleSpinBoxDeduction"));

        horizontalLayout_steamRate->addWidget(doubleSpinBoxDeduction);

        label_6 = new QLabel(groupBox_steamRate);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_steamRate->addWidget(label_6);

        lineEditDeductionResult = new QLineEdit(groupBox_steamRate);
        lineEditDeductionResult->setObjectName(QString::fromUtf8("lineEditDeductionResult"));
        lineEditDeductionResult->setClearButtonEnabled(true);

        horizontalLayout_steamRate->addWidget(lineEditDeductionResult);

        label_7 = new QLabel(groupBox_steamRate);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_steamRate->addWidget(label_7);

        lineEditOriginMoney = new QLineEdit(groupBox_steamRate);
        lineEditOriginMoney->setObjectName(QString::fromUtf8("lineEditOriginMoney"));
        lineEditOriginMoney->setClearButtonEnabled(true);

        horizontalLayout_steamRate->addWidget(lineEditOriginMoney);

        label_8 = new QLabel(groupBox_steamRate);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_steamRate->addWidget(label_8);

        lineEditRate = new QLineEdit(groupBox_steamRate);
        lineEditRate->setObjectName(QString::fromUtf8("lineEditRate"));
        lineEditRate->setClearButtonEnabled(true);

        horizontalLayout_steamRate->addWidget(lineEditRate);


        verticalLayout_4->addLayout(horizontalLayout_steamRate);


        verticalLayout_3->addWidget(groupBox_steamRate);

        groupBox_show = new QGroupBox(centralWidget);
        groupBox_show->setObjectName(QString::fromUtf8("groupBox_show"));
        sizePolicy1.setHeightForWidth(groupBox_show->sizePolicy().hasHeightForWidth());
        groupBox_show->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_show);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_show);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy6);

        horizontalLayout_3->addWidget(label_2);

        lcdNumber = new QLCDNumber(groupBox_show);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        sizePolicy2.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy2);
        lcdNumber->setMinimumSize(QSize(0, 50));
        lcdNumber->setAutoFillBackground(false);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setLineWidth(0);
        lcdNumber->setMidLineWidth(0);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setProperty("value", QVariant(0.000000000000000));

        horizontalLayout_3->addWidget(lcdNumber);


        verticalLayout_2->addLayout(horizontalLayout_3);

        plainTextEdit = new QPlainTextEdit(groupBox_show);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        sizePolicy3.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy3);
        plainTextEdit->setMinimumSize(QSize(0, 200));
        plainTextEdit->setMaximumSize(QSize(16777215, 300));
        plainTextEdit->setBaseSize(QSize(0, 100));

        verticalLayout_2->addWidget(plainTextEdit);


        verticalLayout_3->addWidget(groupBox_show);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 727, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(act_setJson);
        menu_2->addAction(action_about);
        menu_3->addAction(action_simpleView);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        act_setJson->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256json\346\226\207\344\273\266", nullptr));
        action_about->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        action_simpleView->setText(QCoreApplication::translate("MainWindow", "\347\262\276\347\256\200\346\250\241\345\274\217", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\344\272\272\346\260\221\345\270\201\344\273\267\345\200\274\344\270\272\350\257\245\350\264\247\345\270\201\347\232\204\345\244\232\345\260\221\345\200\215", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\272\272\346\260\221\345\270\201", nullptr));
        btnTrans->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242", nullptr));
        label_url->setText(QCoreApplication::translate("MainWindow", "url\345\234\260\345\235\200", nullptr));
        btnGetRate->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\216\267\345\217\226\346\261\207\347\216\207", nullptr));
        btnDefaultUrl->setText(QCoreApplication::translate("MainWindow", "\347\274\272\347\234\201URL\345\234\260\345\235\200", nullptr));
        btnOk->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        groupBox_steamRate->setTitle(QCoreApplication::translate("MainWindow", "steam\346\257\224\347\216\207", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\212\275\346\210\220\346\257\224\347\216\207", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\212\275\346\210\220\347\273\223\346\236\234(rmb)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\264\255\344\271\260\351\207\221\351\242\235(rmb)", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\234\200\347\273\210\346\257\224\347\216\207", nullptr));
        groupBox_show->setTitle(QCoreApplication::translate("MainWindow", "url\347\224\263\350\257\267\350\277\224\345\233\236\345\206\205\345\256\271", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\261\207\347\216\207", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
