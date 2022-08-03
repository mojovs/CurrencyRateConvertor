#include "MainUI.h"
#include <QDebug>
#pragma execution_character_set("utf-8")

MainUI::MainUI(QObject *parent) : UIManager{parent}
{
    json = new Json();

    //槽绑定
    connect(btnGetRate, &QPushButton::clicked, this, &MainUI::getRate); //继续发送信号
    connect(btnDefaultUrl, &QPushButton::clicked, this, &MainUI::on_btnDefaultUrl_clicked);
    connect(btnTrans, &QPushButton::clicked, this, &MainUI::on_btnTrans_clicked);
    connect(btnTest, &QPushButton::clicked, this, &MainUI::on_btnTest_clicked);
}

MainUI::~MainUI()
{
    delete json;
}

/**
 * @brief 更新数据到ui
 */
void MainUI::update2UI()
{
    this->dbSpinBoxYuan->setValue(this->yuan);
    this->dbSpinBoxOther->setValue(this->otherCurrency);
    this->dbSpinBoxTimes->setValue(this->times);
    this->dbSpinBoxDeduction->setValue(this->deductionRate);

    //
    txtUrl->setText(json->getUrlStr());
    //设置货币类型
    combCurrency->addItems(json->currency.getNameList());
}

void MainUI::updateRate(QString symbol, qreal rate)
{
    dbSpinBoxTimes->setValue(rate); //更新UI
    lcdNumber->display(rate);       //更新lcd
    txtShow->appendPlainText("更新汇率成功");

    //更新到json
    json->currency.updateRateBySymbol(symbol, rate); //更新货币数据
    json->flushToJson();                             //刷新文件
}

void MainUI::ConvertMoney(int type)
{
    otherCurrency = dbSpinBoxOther->value();
    yuan          = dbSpinBoxYuan->value();
    times         = dbSpinBoxTimes->value();
    deductionRate = dbSpinBoxDeduction->value(); //获取抽成税率
    if (otherCurrency != 0 || yuan != 0)         //如果这俩货币不为0
    {
        if (type == OtherToYuan)
        {
            yuan = otherCurrency / times;
            dbSpinBoxYuan->setValue(yuan);
        }
        else if (type == YuanToOther)
        {
            otherCurrency = yuan * times;
            dbSpinBoxOther->setValue(otherCurrency);
        }

        deductionRes = yuan * (1 - deductionRate);
        //获取原始金额
        originMoney = txtBoughtMoeny->text().toDouble();
        //获取最终比率
        finalRate = originMoney / deductionRes;
        //设置界面
        dbSpinBoxOther->setValue(otherCurrency);
        txtDeductionRes->setText(QString::number(deductionRes));
        txtStreamRate->setText(QString::number(finalRate));
    }
    else
    {
        qDebug() << "请输入一个金额";
        return;
    }
}
/**
 * @brief 切换货币，则切换搜索网址
 */
void MainUI::setUrlByCurrency()
{
    int index = combCurrency->currentIndex();                                             //	获取当前的货币index
    txtUrl->setText(json->getUrlStr() + json->currency.getSymbolList().at(index) + "/1"); //获取
}
/**
 * @brief 根据界面的货币疾患，获取当前的货币缩写
 * @return 当前的货币符号
 */
QString MainUI::getCurrencySymbol()
{
    int index = combCurrency->currentIndex(); //	获取当前的货币index
    return json->currency.getSymbolList().at(index);
}

/**
 * @brief 根据界面的货币comboBox，得到对应的搜索网址
 * @return 搜索网址
 */
QString MainUI::getUrlStr()
{
    return txtUrl->text();
}

void MainUI::on_btnDefaultUrl_clicked() {}

void MainUI::on_btnTrans_clicked() {}

void MainUI::on_btnTest_clicked() {}
