/*
 * 用于从网络获取信息 ，并更新到UI界面
 *
 */

#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QLCDNumber>
#include <QPlainTextEdit>
#include "Json.h"
#include "UI/MainUI.h"

class Networker : public QObject
{
    Q_OBJECT
  private:
    QNetworkAccessManager networkManager;
    QNetworkReply *reply;
    MainUI *mainUI; //主UI更新

    QString urlStr; //网址
    QString symbol; //当前货币 英文缩写
    qreal rate;     //当前汇率

  public:
    explicit Networker(QObject *parent = nullptr);
    ~Networker();

    const QString &getUrlStr() const;
    void setUrlStr(const QString &newUrlStr);

    const QString &getSymbol() const;
    void setSymbol(const QString &newSymbol);

  private slots:
    void on_readyRead(); //开始读取网络回复
    QString getRate();   //获取rate
  signals:
    void rateGot(QString symbol, qreal rate);
    void getRateFailed(); //获取汇率失败
};

#endif // NETWORKER_H
