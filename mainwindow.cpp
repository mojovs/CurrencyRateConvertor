#include "mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>
#include <aboutdialog.h>
#include "jsonmanagedialog.h"

#include "ui_mainwindow.h"
#pragma execution_character_set("utf-8")
/*-----------------------------------------------构造----------------------------------*/
void MainWindow::init()
{
    /*--设置窗口标题--*/
    this->setWindowTitle("汇率计算器-mojovs");
    /*--打开json并解析--*/
    json = new Json();
    if (!json->fileExist())
    {
        QMessageBox::critical(this, "致命", "打开json文件失败");
        return;
    }
    networker = new Networker();
    //初始化ui
    QList<QObject *> uiList;
    uiList << (ui->doubleSpinBoxTimes) << ui->doubleSpinBoxYuan << ui->doubleSpinBoxOtherCurrency << ui->doubleSpinBoxDeduction
           << ui->btnGetRate << ui->btnDefaultUrl << ui->btnTrans << ui->btnOk << ui->lineEditUrl << ui->lineEditDeductionResult
           << ui->lineEditOriginMoney << ui->lineEditRate << ui->comboBoxCurrent << ui->lcdNumber << ui->plainTextEdit;
    networker->mainUI->attatchUIComponent(uiList); //装载ui组件
    networker->mainUI->init();
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

/*-----------------------------------------------析构----------------------------------*/
MainWindow::~MainWindow()
{
    delete networker;
    delete json;
    delete ui;
}

void MainWindow::on_act_setJson_triggered()
{
    JsonManageDialog *jsonDialog = new JsonManageDialog(this);
    //执行对话框
    if (QDialog::Accepted == jsonDialog->exec())
    {
    }
    jsonDialog->close();
    jsonDialog->deleteLater();
    //更新主界面的数据
    qDebug() << "更新主界面";
    ui->comboBoxCurrent->clear();
    ui->comboBoxCurrent->addItems(json->currency.getNameList());
}

/*----------------------关于对话框---------------------------*/
void MainWindow::on_action_about_triggered()
{
    AboutDialog *dialog = new AboutDialog(this);
    if (QDialog::Accepted == dialog->exec())
    {
    }
    dialog->close();
    dialog->deleteLater();
}

void MainWindow::on_action_simpleView_triggered(bool checked)
{
    //如果不是精简模式就显示界面
    if (false == checked)
    {
        ui->lineEditUrl->show();
        ui->btnOk->show();
        ui->btnDefaultUrl->show();
        ui->label_url->show();
        ui->groupBox_show->show();
        ui->groupBox_steamRate->show();
    }
    else
    {
        //设置某些ui隐藏
        ui->lineEditUrl->hide();
        ui->btnOk->hide();
        ui->btnDefaultUrl->hide();
        ui->label_url->hide();
        ui->groupBox_show->hide();
        ui->groupBox_steamRate->hide();
    }
    //设置窗口大小
    this->adjustSize();
}
