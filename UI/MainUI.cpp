#include "MainUI.h"
#include <QDebug>
#pragma execution_character_set("utf-8")

MainUI::MainUI(QObject *parent) : UIManager{parent}
{
    json = new Json();
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
    txtUrl->setText(json->getUrlStr()+"cny-" + json->currency.getSymbolList().at(0));
    //设置货币类型
    combCurrency->addItems(json->currency.getNameList());
    //设置lcd
    lcdNumber->display(times);
}

/**
 * @brief 将界面ui导入管理类
 * @param QList<QObject *> 组件列表
 */
void MainUI::attatchUIComponent(QList<QObject *> &uiList)
{
    dbSpinBoxTimes     = (QDoubleSpinBox *)uiList.at(0); //人民币为其他货币的倍数
    dbSpinBoxYuan      = (QDoubleSpinBox *)uiList.at(1); //人民币金额
    dbSpinBoxOther     = (QDoubleSpinBox *)uiList.at(2); //其他货币金额
    dbSpinBoxDeduction = (QDoubleSpinBox *)uiList.at(3); // steam抽成

    btnGetRate    = (QPushButton *)uiList.at(4);
    btnDefaultUrl = (QPushButton *)uiList.at(5);
    btnTrans      = (QPushButton *)uiList.at(6);
    btnTest       = (QPushButton *)uiList.at(7);

    txtUrl          = (QLineEdit *)uiList.at(8);
    txtDeductionRes = (QLineEdit *)uiList.at(9);  //抽成结果
    txtBoughtMoeny  = (QLineEdit *)uiList.at(10); //买入金额
    txtStreamRate   = (QLineEdit *)uiList.at(11); //买入金额

    combCurrency = (QComboBox *)uiList.at(12); //货币类型

    lcdNumber = (QLCDNumber *)uiList.at(13); // lcd显示

    txtShow = (QPlainTextEdit *)uiList.at(14); //显示
}

/**
 * @brief 更新汇率数据到ui和文件
 * @param symbol 货币缩写
 * @param rate 汇率
 */
void MainUI::updateRate(QString symbol, qreal rate)
{
    dbSpinBoxTimes->setValue(rate); //更新UI
    lcdNumber->display(rate);       //更新lcd
    txtShow->appendPlainText("更新汇率成功");

    //更新到json
    json->currency.updateRateBySymbol(symbol, rate); //更新货币数据
    json->flushToJson();                             //刷新文件
}
/**
 * @brief 根据type，确定是人民币转其他货币，还是其他货币转人民币
 * @param type 类型
 */
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

void MainUI::init()
{
    /*--设置LCD样式--*/
    lcdNumber->setStyleSheet("border: 1px solid green;color:green;background:silver");
    //更新ui
    update2UI();
    //槽绑定
    connect(btnGetRate, &QPushButton::clicked, this, &MainUI::getRate); //继续发送信号
    connect(btnDefaultUrl, &QPushButton::clicked, this, &MainUI::on_btnDefaultUrl_clicked);
    connect(btnTrans, &QPushButton::clicked, this, &MainUI::on_btnTrans_clicked);
    connect(btnTest, &QPushButton::clicked, this, &MainUI::on_btnTest_clicked);
    connect(dbSpinBoxYuan, &QDoubleSpinBox::editingFinished, this, &MainUI::on_dbSpinBoxYuan_editfinished);
    connect(dbSpinBoxOther, &QDoubleSpinBox::editingFinished, this, &MainUI::on_dbSpinBoxOther_editfinished);
    connect(combCurrency, SIGNAL(currentIndexChanged(int)), this, SLOT(on_combCurrency_index_changed(int)));

    isUIInit = true;
}
/**
 * @brief 切换货币，则切换搜索网址
 */
void MainUI::setUrlByCurrency()
{
    int index = combCurrency->currentIndex();                                             //	获取当前的货币index
    txtUrl->setText(json->getUrlStr()+"cny-"+getCurrencySymbol() ); //获取
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

/**
 * @brief 点击默认的按钮
 */
void MainUI::on_btnDefaultUrl_clicked() {}

/**
 * @brief 其他货币转换成人民币
 */
void MainUI::on_btnTrans_clicked()
{
    ConvertMoney(OtherToYuan); //转换
}
/**
 * @brief 测试按钮
 */
void MainUI::on_btnTest_clicked() {}
/**
 * @brief 人民币信息框填写完毕时触发，进行转换
 */
void MainUI::on_dbSpinBoxYuan_editfinished()
{
    ConvertMoney(YuanToOther);
}

void MainUI::on_dbSpinBoxOther_editfinished()
{
    ConvertMoney(OtherToYuan);
}

/**
 * @brief 切换货币，更新网址，汇率，lcd显示
 * @param index
 */
void MainUI::on_combCurrency_index_changed(int index)
{
    if (index >= 0)
    {
        dbSpinBoxTimes->setValue(json->currency.getRateList().at(index).toDouble());
        lcdNumber->display(json->currency.getRateList().at(index).toDouble());
        //设置当前货币对应的搜索网址
        setUrlByCurrency();
    }
}
