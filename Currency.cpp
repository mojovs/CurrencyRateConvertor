#include "Currency.h"

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

Currency::Currency() {}
Currency::~Currency() {}
