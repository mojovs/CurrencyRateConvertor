#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QObject>

class UIManager : public QObject
{
    Q_OBJECT
  public:
    explicit UIManager(QObject *parent = nullptr);
    ~UIManager();

    virtual void update2UI() = 0;

  protected:
    qreal times         = 0;    //人民币为其他货币的多少倍
    qreal yuan          = 0;    //人民币数额
    qreal originMoney   = 0;    // steam买入金额
    qreal otherCurrency = 0;    //其他货币的数额
    qreal deductionRes  = 0;    // steam抽成结果
    qreal deductionRate = 0.15; // steam抽成税率
    qreal finalRate     = 0.0;  //倒余额比率
    QString currencyName;       //货币名称

  signals:
};

#endif // UIMANAGER_H
