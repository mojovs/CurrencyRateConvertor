#ifndef MYJSON_H
#define MYJSON_H

#include <QObject>
#include <QMap>

class MyJson
{
public:
    QStringList strList;	//货币名称列表
    QStringList symbolList;	//货币符号列表
    QStringList rateList;	//汇率列表
    QString urlStr;			//默认网址名称

    QStringList fileNameList;	//找到的文件列表
    bool isJsonFind=false;	//找到json文件没

    MyJson();
    bool OpenJson();	//打开json文件
    bool CreateJsonFile();	//创建一个json文件
    bool FindJson();	//找到json文件
    bool FindFileInDir(QString curDirPath, QString filename);	//在路径中找到文件
    bool ParseJson(QString &data);	//解析json文件，导出符号和名称
    bool ParseJsonArray(QString key,QJsonObject &mObj,QStringList &mList);	//解析一串json数组

};

#endif // MYJSON_H
