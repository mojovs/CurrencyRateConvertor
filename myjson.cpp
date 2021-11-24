#include "myjson.h"
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#pragma execution_character_set("utf-8")
MyJson::MyJson()
{
    //打开json文件
    if( !OpenJson())
    {
        qDebug()<<"创建MyJson失败:OpenJson";
        return;
    }
    isJsonFind = true;
}

bool MyJson::OpenJson()
{
    strList.clear();
    symbolList.clear();
    //找到Json文件
    if(!FindJson())
    {
        qDebug()<<"没有找到JSON"<<__FILE__<<__LINE__;
        isJsonFind = false;
        //创建一个json文件
        CreateJsonFile();
    }
    QString fileName;
    if(fileNameList.count()>0)
    {
        fileName = fileNameList.at(0);
        qDebug() << "打开的json地址为 " << fileName;
    }else
    {

        fileName=QDir::currentPath()+"/货币列表.json";
        qDebug()<<"没有搜索到路径，使用当前路径作为json创建路径";

    }
    /*--文件被占用--*/
    QFile aFile(fileName);
    /*--打开文件--*/
    if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text))  //文件可读写
    {
        qDebug()<<"打开货币列表失败";
        return false;
    }
    /*--数据全部读取--*/
    QString data = aFile.readAll();

    /*--文件关闭--*/
    aFile.close();
    /*--解析json--*/
    ParseJson(data);
}

bool MyJson::CreateJsonFile()
{
    qDebug()<<"创建列表";
    //开始构建json结构
    QJsonArray nameArray;
    nameArray.append("阿根廷比索");
    nameArray.append("俄罗斯卢布");

    QJsonArray symbolArray;
    symbolArray.append("ARS");
    symbolArray.append("RUB");

    QJsonArray rateArray;
    rateArray.append("1.0");
    rateArray.append("1.0");

    //总体
    QJsonObject json;
    json.insert("name","在线货币");
    json.insert("url","https://cn.exchange-rates.org/converter/CNY/");
    json.insert("Currency",nameArray);
    json.insert("CurrencySymbol",symbolArray);
    json.insert("Rate",rateArray);
    QJsonDocument document;
    document.setObject(json);


    //创建文件
    QString filePath = QDir::currentPath();	//以当前路径为文件路径
    QString fileName = filePath+"/货币列表.json";
    if(filePath.isEmpty())
        return false;

    QFile aFile(fileName);
    if(!aFile.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        qDebug()<<"打不开文件";
        return false;
    }
    aFile.write(document.toJson());
    aFile.close();
    isJsonFind=true;

    qDebug()<<"创建成功";
}

bool MyJson::FindJson()
{

    if(!FindFileInDir(QDir::currentPath(),"货币列表") || strList.count()<1)
    {
        qDebug()<<"没有在该目录:"<<QDir::currentPath()<<"找到货币列表";
        return false;
    }
    return true;
}

bool MyJson::FindFileInDir(QString curDirPath, QString filename)
{
    //创建一个目录类
       QDir curDir(curDirPath);
       if(!curDir.exists())
       {
           qDebug()<<"目录不存在";
           return false;
       }
       //寻找子文件夹
       //设置过滤的格式
       QStringList filterList;
       filterList<<"*"+filename+"*";	//按照名称匹配

       //建立文件信息列表
       QFileInfoList dirInfoList = curDir.entryInfoList(QDir::Dirs|QDir::NoDotAndDotDot);	//只过滤文件夹
       QFileInfoList fileInfoList = curDir.entryInfoList(filterList);	//过滤文件

       //递归查找文件夹
       for(int i=0;i<dirInfoList.count();i++)
       {
          QString dirTmp = dirInfoList.at(i).filePath();

          FindFileInDir(dirTmp,filename);
       }



      //如果只有文件,把文件导入到列表
      for(int i=0; i<fileInfoList.count();i++)
      {
          fileNameList<<fileInfoList.at(i).filePath();
      }

      dirInfoList.clear();
      fileInfoList.clear();

      return true;
}

bool MyJson::ParseJson(QString &data)
{
    //qDebug() << data;
    /*--转换到流--*/
    QByteArray byteArray = data.toUtf8();

    /*--创建json文档--*/
    QJsonParseError jsonErr;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray, &jsonErr);
    if (jsonDoc.isNull() || jsonErr.error != QJsonParseError::NoError)
    {
        return false;
    }
    /*--开始解析文档--*/
    if (jsonDoc.isObject())  //如果json主体是object
    {
        QJsonObject object = jsonDoc.object();
        if (object.contains("name"))
            if (object.value("name").toString() != "在线货币")
            {
                return false;
            }
        if (object.contains("url"))
        {  //获取网络地址
            QJsonValue jsonValue = object.value("url");
            if (jsonValue.isString())
            {
                urlStr = jsonValue.toString();
            }
        }
        /*--开始解析货币名称--*/
        if (object.contains("Currency"))
        {
            ParseJsonArray("Currency",object,strList);
         }
        /*--开始解析货币符号--*/
        if (object.contains("CurrencySymbol"))
        {
            ParseJsonArray("CurrencySymbol",object,symbolList);
        }
        //开始解析汇率值
         if (object.contains("Rate"))
        {
            ParseJsonArray("Rate",object,rateList);
        }

    }
}

bool MyJson::ParseJsonArray(QString key,QJsonObject &mObj,QStringList &mList)
{
    QJsonValue jsonValue = mObj.value(key);
    if (jsonValue.isArray())
    {
                QJsonArray mArray= jsonValue.toArray();  // json数组
                for (int i = 0; i < mArray.size(); i++)
                {
                    //获取货币名称
                    //依次将值存储进图
                    if(mArray.at(i).isString() ||mArray.at(i).isDouble())
                    {
                        mList.append(mArray.at(i).toString());  //把货币名称存储进列表里
                    }
                   // else if(mArray.at(i).isDouble())
                   // {

                   //     mList.append(mArray.at(i).toString());  //把货币名称存储进列表里
                   // }
                    else
                    {
                        qDebug()<<"没有这样的类型";
                        return false;
                    }
                }
     }
    return true;

}
