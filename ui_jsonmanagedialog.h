/********************************************************************************
** Form generated from reading UI file 'jsonmanagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSONMANAGEDIALOG_H
#define UI_JSONMANAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_JsonManageDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditAddName;
    QLabel *label_2;
    QLineEdit *lineEditAddSymbol;
    QPushButton *btnAdd;
    QPushButton *btnUpdate;
    QTableWidget *tableWidget;

    void setupUi(QDialog *JsonManageDialog)
    {
        if (JsonManageDialog->objectName().isEmpty())
            JsonManageDialog->setObjectName(QString::fromUtf8("JsonManageDialog"));
        JsonManageDialog->resize(545, 325);
        JsonManageDialog->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(JsonManageDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(JsonManageDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditAddName = new QLineEdit(JsonManageDialog);
        lineEditAddName->setObjectName(QString::fromUtf8("lineEditAddName"));

        horizontalLayout->addWidget(lineEditAddName);

        label_2 = new QLabel(JsonManageDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditAddSymbol = new QLineEdit(JsonManageDialog);
        lineEditAddSymbol->setObjectName(QString::fromUtf8("lineEditAddSymbol"));

        horizontalLayout->addWidget(lineEditAddSymbol);

        btnAdd = new QPushButton(JsonManageDialog);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        horizontalLayout->addWidget(btnAdd);

        btnUpdate = new QPushButton(JsonManageDialog);
        btnUpdate->setObjectName(QString::fromUtf8("btnUpdate"));
        btnUpdate->setStyleSheet(QString::fromUtf8("background-color: rgb(97, 159, 26);\n"
"border-color: rgb(99, 99, 99);\n"
"color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(126, 126, 126);"));

        horizontalLayout->addWidget(btnUpdate);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(JsonManageDialog);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(JsonManageDialog);

        QMetaObject::connectSlotsByName(JsonManageDialog);
    } // setupUi

    void retranslateUi(QDialog *JsonManageDialog)
    {
        JsonManageDialog->setWindowTitle(QCoreApplication::translate("JsonManageDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("JsonManageDialog", "\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("JsonManageDialog", "\347\254\246\345\217\267", nullptr));
        btnAdd->setText(QCoreApplication::translate("JsonManageDialog", "\346\267\273\345\212\240", nullptr));
        btnUpdate->setText(QCoreApplication::translate("JsonManageDialog", "\346\233\264\346\226\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("JsonManageDialog", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("JsonManageDialog", "\347\254\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("JsonManageDialog", "\346\261\207\347\216\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JsonManageDialog: public Ui_JsonManageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSONMANAGEDIALOG_H
