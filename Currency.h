#ifndef CURRENCY_H
#define CURRENCY_H

#include <QObject>
#include <QStringList>

class Currency
{
  private:
    int curIndex;
    QStringList nameList;
    QStringList symbolList;
    QStringList rateList;

  public:
    Currency();
    ~Currency();

    void reset();                                        //重置
    void clear();                                        //清空
    void updateRateBySymbol(QString symbol, qreal rate); //根据货币简写更新符号
    void appendEmpty();                                  //添加一行空数据

    int getCurIndex() const;
    void setCurIndex(int newCurIndex);
    QStringList &getNameList();
    void setNameList(const QStringList &newNameList);
    QStringList &getSymbolList();
    void setSymbolList(const QStringList &newSymbolList);
    QStringList &getRateList();
    void setRateList(const QStringList &newRateList);
};

#endif // CURRENCY_H
