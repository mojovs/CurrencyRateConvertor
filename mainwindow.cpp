#include "mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>

#include "ui_mainwindow.h"
#pragma execution_character_set("utf-8")
/*-----------------------------------------------私有 根据货币种类设置相应的网址----------------------------------*/
void MainWindow::setUrlByCurrency()
{
    int index = ui->comboBoxCurrent->currentIndex();                 //	获取当前的货币index
    ui->lineEditUrl->setText(urlStr + symbolList.at(index) + "/1");  //获取
}
/*-----------------------------------------------私有 打开一个json文件----------------------------------*/
void MainWindow::openJson()
{
    strList.clear();
    symbolList.clear();
    QString fileName = QDir::currentPath() + "/货币列表.json";
    qDebug() << "打开的json地址为 " << fileName;
    /*--文件被占用--*/
    QFile aFile(fileName);
    /*--打开文件--*/
    if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text))  //文件可读写
    {
        QMessageBox::critical(this, "致命错误",
                              QString("打开货币列表.json失败,行%1,请在同级目录下放[货币列表.json]文件").arg(__LINE__));
        return;
    }
    /*--数据全部读取--*/
    QString data = aFile.readAll();

    /*--文件关闭--*/
    aFile.close();
    /*--解析json--*/
    parseJson(data);
}

/*-----------------------------------------------私有 解析json文件----------------------------------*/
void MainWindow::parseJson(QString& data)
{
    qDebug() << data;
    /*--转换到流--*/
    QByteArray byteArray = data.toUtf8();

    /*--创建json文档--*/
    QJsonParseError jsonErr;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray, &jsonErr);
    if (jsonDoc.isNull() || jsonErr.error != QJsonParseError::NoError)
    {
        QMessageBox::critical(this, "致命错误", QString("jsonDoc创建错误,行%1").arg(__LINE__));
        return;
    }
    /*--开始解析文档--*/
    if (jsonDoc.isObject())  //如果json主体是object
    {
        QJsonObject object = jsonDoc.object();
        if (object.contains("name"))
            if (object.value("name").toString() != "在线货币")
            {
                QMessageBox::critical(this, "致命错误", "json文件类型错误");
                return;
            }
        if (object.contains("url"))
        {  //获取网络地址
            QJsonValue jsonValue = object.value("url");
            if (jsonValue.isString())
            {
                urlStr = jsonValue.toString();
                ui->lineEditUrl->setText(urlStr);
            }
        }
        /*--开始解析货币名称--*/
        if (object.contains("currencyName"))
        {
            QJsonValue jsonValue = object.value("currencyName");
            if (jsonValue.isArray())
            {
                QJsonArray mArray = jsonValue.toArray();  // json数组
                for (int i = 0; i < mArray.size(); i++)
                {
                    strList.append(mArray.at(i).toString());  //把货币名称存储进列表里
                }
            }
        }
        /*--开始解析货币符号--*/
        if (object.contains("currencySymbol"))
        {
            QJsonValue jsonValue = object.value("currencySymbol");
            if (jsonValue.isObject())
            {
                QJsonObject mObject = jsonValue.toObject();  // jsonObject
                for (int i = 0; i < strList.size(); i++)
                {
                    if (mObject.contains(strList.at(i)))
                    {
                        QJsonValue jsonValue = mObject.value(strList.at(i));
                        symbolList.append(jsonValue.toString());
                        qDebug() << jsonValue.toString();
                    }
                }
            }
        }
    }
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
    openJson();
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
        times = 13;
        ui->doubleSpinBoxTimes->setValue(13.0);
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
    ui->plainTextEdit->appendPlainText("---开始获取网络信息，请等待---");
    ui->plainTextEdit->appendPlainText("---开始读取---");
    /*--正则处理文本，截取汇率--*/
    int pos = 0;
    QRegExp rx("\\d\\sCNY\\s=\\s(\\d+\\.\\d+)\\s");
    pos = rx.indexIn(data, 0);
    //    if (pos < 0) {
    //        QMessageBox::information(this, "错误", "正则没有查找到");
    //        return;
    //    }
    ui->plainTextEdit->appendPlainText(QString("---开始获取汇率信息---"));
    ui->plainTextEdit->appendPlainText(rx.cap(0));
    strRate = rx.cap(1);
    /*--设置lcd屏幕--*/
    ui->lcdNumber->display(strRate);
    /*--发送汇率--*/
    ui->doubleSpinBoxTimes->setValue(strRate.toDouble());
    ui->plainTextEdit->appendPlainText("---读取完毕---");
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
