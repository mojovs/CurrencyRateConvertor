#ifndef JSON_H
#define JSON_H

#include <QObject>
#include "Currency.h"
class Json
{
  public:
    Json();
    ~Json();

  private:
    QString filename;
    QString filepath;
    bool isFileExist;
    QString urlStr; //网址地址

  public:
    static Currency currency; //货币
    static bool isFileInDir(const QString dir, const QString filename, QString &filepath);
    bool fileExist(); //判断json文件是否存在

    const QString &getFilename() const;           //获取文件名
    void setFilename(const QString &newFilename); //设置文件名

    void openJson(); //打开json文件，并刷新界面
    void newJson();  //创建一个json文件

    bool ParseJsonData(QString &data); //解析json文件原始数据，到currency本地
    bool ParseJsonArray(QString key, QJsonObject &mObj, QStringList &mList);
    void flushToJson(); //将currency数据更新至json文件

    const QString &getUrlStr() const;
    void setUrlStr(const QString &newUrlStr);
};

#endif // JSON_H
