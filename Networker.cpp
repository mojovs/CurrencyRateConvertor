#include "Networker.h"
#pragma execution_character_set("utf-8")
/**
 * @brief 构造
 */

Networker::Networker(QObject *parent) : QObject{parent}
{
    //创建函数
    mainUI = new MainUI();

    //绑定信号
    connect(mainUI, &MainUI::getRate, this, &Networker::getRate); //获取汇率
}

/**
 * @brief 析构
 */
Networker::~Networker()
{
    // delete reply;
    delete mainUI;
}
void Networker::on_readyRead()
{
    symbol = mainUI->getCurrencySymbol();
    /*-- 读取内容到数据里面 --*/
    QString data = reply->readAll();
    /*-- 显示文本框 --*/
    /*--正则处理文本，截取汇率--*/
    int pos     = 0;
    QString reg = "\\d\\sCNY\\s=\\s(\\d+\\.\\d+)\\s" + symbol;
    QRegExp rx(reg);
    pos = rx.indexIn(data, 0);
    //    if (pos < 0) {
    //        QMessageBox::information(this, "错误", "正则没有查找到");
    //        return;
    //    }
    qDebug() << pos << ":" << rx.cap(0);
    if (!rx.cap(1).isEmpty())
    {
        rate = rx.cap(1).toDouble(); //捕获到汇率
        //更新ui
        mainUI->updateRate(symbol, rate);
        emit rateGot(symbol, rate); //发送捕捉完成信号
        return;
    }
    else
    {
        qDebug() << "继续获取";
        mainUI->txtShow->appendPlainText("------获取中-----");
        emit getRateFailed();
    }
}
/**
 * @brief 从reply里，获取汇率
 */
void Networker::getRate()
{
    urlStr = mainUI->txtUrl->text();
    /*--设置界面url--*/
    qDebug() << urlStr;
    /*--获取地址--*/
    if (urlStr.isEmpty())
    {
        qDebug() << "Error:urlStr Empty";
        return;
    }
    QUrl urlSpec = QUrl::fromUserInput(urlStr);
    if (!urlSpec.isValid())
    {
        qDebug() << "Error:urlSpec is invalid";
        return;
    }

    /*--获取reply--*/
    reply = networkManager.get(QNetworkRequest(urlSpec));

    /*--函数绑定--*/
    connect(reply, &QNetworkReply::readyRead, this, &Networker::on_readyRead);
    qDebug() << "Get";
}
