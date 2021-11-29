#include "mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>
#include <aboutdialog.h>
#include "myjson.h"
#include "jsonmanagedialog.h"

#include "ui_mainwindow.h"
#pragma execution_character_set("utf-8")
/*-----------------------------------------------私有 根据货币种类设置相应的网址----------------------------------*/
void MainWindow::setUrlByCurrency()
{
    int index = ui->comboBoxCurrent->currentIndex();                 //	获取当前的货币index
    ui->lineEditUrl->setText(urlStr + symbolList.at(index) + "/1");  //获取
}
/*-----------------------------------------------获取当前货币符号----------------------------------*/
QString MainWindow::getCurrencySymbol()
{
    int index = ui->comboBoxCurrent->currentIndex();
    return symbolList.at(index);
}

/*-----------------------------------------------货币转换----------------------------------*/
void MainWindow::ConvertMoney(int type)
{
    otherCurrency = ui->doubleSpinBoxOtherCurrency->value();
    yuan = ui->doubleSpinBoxYuan->value();
    times = ui->doubleSpinBoxTimes->value();
    deductionRate = ui->doubleSpinBoxDeduction->value();  //获取抽成税率
    if (otherCurrency != 0 || yuan != 0)                  //如果这俩货币不为0
    {
        if(type==OtherToYuan)
        {
            yuan = otherCurrency / times;
            ui->doubleSpinBoxYuan->setValue(yuan);
        }else if(type==YuanToOther)
        {

            otherCurrency= yuan* times;
            ui->doubleSpinBoxOtherCurrency->setValue(otherCurrency);
        }

        deductionRes = yuan * (1 - deductionRate);
        //获取原始金额
        originMoney = ui->lineEditOriginMoney->text().toDouble();
        //获取最终比率
        finalRate= originMoney/deductionRes;
        //设置界面
        ui->doubleSpinBoxOtherCurrency->setValue(otherCurrency);
        ui->lineEditDeductionResult->setText(QString::number(deductionRes));
        ui->lineEditRate->setText(QString::number(finalRate));
    }
    else
    {
        QMessageBox::information(this, "错误", "请输入货币数额");
        return;
    }
}

/*-----------------------------------------------构造----------------------------------*/
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*--设置窗口标题--*/
    this->setWindowTitle("汇率计算器-mojovs");
    /*--打开json并解析--*/
    MyJson myjson;
    if(!myjson.isJsonFind)
    {
        QMessageBox::critical(this,"致命","打开json文件失败");
        return;
    }
    symbolList=myjson.symbolList;	//获取货币符号列表
    strList = myjson.strList;	//获取符号名称列表
    rateList = myjson.rateList;
    urlStr = myjson.urlStr;		//获取json中的网址
    ui->lineEditUrl->setText(urlStr);
    /*--添加货币到组件--*/
    ui->comboBoxCurrent->clear();
    for (const QString& str : strList)
    {
        ui->comboBoxCurrent->addItem(str);
    }
    ui->comboBoxCurrent->setCurrentIndex(0);
    /*--设置汇率--*/
    if (ui->doubleSpinBoxTimes->value() == 0)  //如果界面汇率没有设置，把汇率变为阿根廷汇率13
    {
        times = rateList.at(0).toDouble();
        ui->doubleSpinBoxTimes->setValue(times);
    }
    else
        times = ui->doubleSpinBoxTimes->value();

    //设置默认抽成
    ui->doubleSpinBoxDeduction->setValue(deductionRate);

    /*--设置默认网址--*/
    // ui->lineEditUrl->setText(QString("https://cn.exchange-rates.org/Rate/CNY/ARS/1").trimmed());
    /*--设置LCD样式--*/
    ui->lcdNumber->setStyleSheet("border: 1px solid green;color:green;background:silver");
}

/*-----------------------------------------------析构----------------------------------*/
MainWindow::~MainWindow() { delete ui; }

/*-----------------------------------------------槽 回复----------------------------------*/
void MainWindow::on_readyRead()
{
    QString strRate;
    /*-- 读取内容到数据里面 --*/
    QString data = reply->readAll();
    /*-- 显示文本框 --*/
    /*--正则处理文本，截取汇率--*/
    int pos = 0;
    QString symbol = getCurrencySymbol();
    QString reg = "\\d\\sCNY\\s=\\s(\\d+\\.\\d+)\\s"+symbol;
    QRegExp rx(reg);
    pos = rx.indexIn(data, 0);
    //    if (pos < 0) {
    //        QMessageBox::information(this, "错误", "正则没有查找到");
    //        return;
    //    }
    ui->plainTextEdit->appendPlainText(rx.cap(0));
    if(!rx.cap(1).isEmpty())
    {
        strRate = rx.cap(1);
        //获取当前货币的index
        int index = ui->comboBoxCurrent->currentIndex();
        rateList.replace(index,strRate);
        //同步到json文件
        MyJson::CreateJsonFromLists(strList,symbolList,rateList);
        /*--设置lcd屏幕--*/
        ui->lcdNumber->display(strRate);
        /*--发送汇率--*/
        ui->doubleSpinBoxTimes->setValue(strRate.toDouble());
        ui->plainTextEdit->appendPlainText("---读取完毕---");
        return;
    }else
    {
        ui->plainTextEdit->appendPlainText("---获取汇率中---");
    }


}

/*-----------------------------------------------槽 开始转换----------------------------------*/
void MainWindow::on_pushButtonTrans_clicked()
{
    ConvertMoney(OtherToYuan);
}

/*-----------------------------------------------槽 按键 获取在线汇率----------------------------------*/
void MainWindow::on_btnGetRate_clicked()
{
    /*--设置界面url--*/
    setUrlByCurrency();
    qDebug() << urlStr;
    /*--获取地址--*/
    if (urlStr.isEmpty())
    {
        QMessageBox::information(this, "错误", "输入为空");
        return;
    }
    QUrl urlSpec = QUrl::fromUserInput(ui->lineEditUrl->text().trimmed());
    if (!urlSpec.isValid())
    {
        QMessageBox::information(this, "错误", QString("无效URL:%1,错误信息 %2").arg(urlStr, urlSpec.errorString()));
        return;
    }

    ui->plainTextEdit->appendPlainText("---开始获取网络信息，请等待---");
    ui->plainTextEdit->appendPlainText("---开始读取---");
    /*--获取reply--*/
    reply = networkManager.get(QNetworkRequest(urlSpec));

    /*--函数绑定--*/
    connect(reply, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
}

/*-----------------------------------------------槽 其他货币输入数额后,执行转换----------------------------------*/
void MainWindow::on_doubleSpinBoxYuan_editingFinished()
{
    ConvertMoney(YuanToOther);
}

/*-----------------------------------------------槽 其他货币输入数额后，执行转换----------------------------------*/
void MainWindow::on_doubleSpinBoxOtherCurrency_editingFinished()
{
    ConvertMoney(OtherToYuan);
}

/*-----------------------------------------------槽 设置缺省地址----------------------------------*/
void MainWindow::on_btnDefaultUrl_clicked() {}

/*-----------------------------------------------槽 打开json管理对话框----------------------------------*/
void MainWindow::on_act_setJson_triggered()
{
    JsonManageDialog *jsonDialog = new JsonManageDialog(this);
    //执行对话框
   if(QDialog::Accepted == jsonDialog->exec())
   {

   }
   jsonDialog->close();
   jsonDialog->deleteLater();
   //更新主界面的数据
   qDebug()<<"更新主界面";
   MyJson json;
   strList=json.strList;
   symbolList = json.symbolList;
   rateList = json.rateList;
   ui->comboBoxCurrent->clear();
   ui->comboBoxCurrent->addItems(strList);


}


/*----------------------切换货币，则切换汇率---------------------------*/
void MainWindow::on_comboBoxCurrent_currentIndexChanged(int index)
{
    ui->doubleSpinBoxTimes->setValue(rateList.at(index).toDouble());

}


/*----------------------关于对话框---------------------------*/
void MainWindow::on_action_about_triggered()
{
    AboutDialog *dialog = new AboutDialog(this);
    if(QDialog::Accepted == dialog->exec())
    {

    }
    dialog->close();
    dialog->deleteLater();

}


void MainWindow::on_action_simpleView_triggered(bool checked)
{
    //如果不是精简模式就显示界面
    if(false == checked)
    {
        ui->lineEditUrl->show();
        ui->btnOk->show();
        ui->btnDefaultUrl->show();
        ui->label_url->show();
        ui->groupBox_show->show();
        ui->groupBox_steamRate->show();

    }else
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

