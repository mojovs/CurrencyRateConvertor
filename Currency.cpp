#include "Currency.h"
#include <QDebug>
Currency::Currency() {}
Currency::~Currency() {}
int Currency::getCurIndex() const
{
    return curIndex;
}

void Currency::setCurIndex(int newCurIndex)
{
    curIndex = newCurIndex;
}

QStringList &Currency::getNameList()
{
    return nameList;
}

void Currency::setNameList(const QStringList &newNameList)
{
    nameList = newNameList;
}

QStringList &Currency::getSymbolList()
{
    return symbolList;
}

void Currency::setSymbolList(const QStringList &newSymbolList)
{
    symbolList = newSymbolList;
}

QStringList &Currency::getRateList()
{
    return rateList;
}

void Currency::setRateList(const QStringList &newRateList)
{
    rateList = newRateList;
}

void Currency::reset()
{
    clear();

    //设置默认值
}

void Currency::clear()
{
    this->nameList.clear();
    this->rateList.clear();
    this->symbolList.clear();
}

void Currency::updateRateBySymbol(QString symbol, qreal rate)
{
    if (!symbolList.contains(symbol))
    {
        qDebug() << "This Symbol isnt contained by list ";
        return;
    }
    int index = symbolList.indexOf(symbol);
    rateList.replace(index, QString::number(rate)); //替换该位置数据
}
