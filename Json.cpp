#include "Json.h"
#include <QDir>
#include <QDebug>
#include <QFileInfoList>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#pragma execution_character_set("utf-8")

Currency Json::currency;
Json::Json()
{
    filename = "货币列表.json";
    openJson();
}

Json::~Json() {}

const QString &Json::getUrlStr() const
{
    return urlStr;
}

void Json::setUrlStr(const QString &newUrlStr)
{
    if (urlStr == newUrlStr) return;
    urlStr = newUrlStr;
}

/**
 * @brief Json::fileExist 查看是否存在货币列表文件
 * @return true 有 false 无
 */
bool Json::fileExist()
{
    if (!isFileInDir(QDir::currentPath(), filename, this->filepath))
    {
        qDebug() << "没有在该目录:" << QDir::currentPath() << "找到货币列表";
        return false;
    }
    return true;
}

const QString &Json::getFilename() const
{
    return filename;
}

void Json::setFilename(const QString &newFilename)
{
    filename = newFilename;
}

/**
 * @brief Json::openJson 打开Json文件夹，并解析
 */
void Json::openJson()
{
    //没找到Json文件
    if (!fileExist())
    {
        qDebug() << "没有找到JSON" << __FILE__ << __LINE__;
        isFileExist = false;
        //创建一个json文件
        qDebug() << "创建一个JSON文件" << __FILE__ << __LINE__;
        qDebug() << "没有搜索到路径，使用当前路径作为json创建路径";
        QString defaultPath = QDir::currentPath() + "/货币列表.json";
        filepath            = defaultPath;
        qDebug() << "打开的json地址为 " << filepath;
        newJson(); //创建文件
    }
    qDebug() << "打开的json地址为 " << filepath;
    /*--文件被占用--*/
    QFile aFile(filepath);
    /*--打开文件--*/
    if (!aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //文件可读写
    {
        qDebug() << "打开货币列表失败";
        return;
    }
    /*--数据全部读取--*/
    QString data = aFile.readAll();

    /*--文件关闭--*/
    aFile.close();
    /*--解析json--*/
    if (!ParseJsonData(data))
    {
        return;
    }
    true;
}

/**
 * @brief Json::newJson 没有找到json，就创建一个默认的json文件
 */
void Json::newJson()
{
    qDebug() << "创建列表";
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
    json.insert("name", "在线货币");
    json.insert("url", "https://cn.exchange-rates.org/converter/CNY/");
    json.insert("Currency", nameArray);
    json.insert("CurrencySymbol", symbolArray);
    json.insert("Rate", rateArray);
    QJsonDocument document;
    document.setObject(json);

    //创建文件
    QString fileDir  = QDir::currentPath(); //以当前路径为文件路径
    QString filePath = fileDir + "/" + filename;
    if (fileDir.isEmpty()) return;

    QFile aFile(filePath);
    if (!aFile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate))
    {
        qDebug() << "打不开文件";
        return;
    }
    aFile.write(document.toJson());
    aFile.close();
    isFileExist = true;

    qDebug() << "创建成功";
}

/**
 * @brief Json::isFileInDir 搜目录下面搜索文件
 * @param dir 要搜索的目录
 * @param filename 要搜索的文件名称
 * @param filepath [out] 输出搜索到的文件路径
 * @return true 该目录下有该文件 false 无
 */
bool Json::isFileInDir(const QString dir, const QString filename, QString &filepath)
{
    QDir aDir(dir);
    if (!aDir.exists())
    {
        qDebug() << "Invalid dir";
        return false;
    }

    QString prefix = dir + "/";
    //设置文件名称
    QStringList pattern;
    pattern << filename;
    //匹配文件
    foreach (const QString &fileName, aDir.entryList(pattern, QDir::Files | QDir::NoSymLinks))
    {
        qDebug() << fileName;
        if (fileName == filename)
        {
            filepath = prefix + fileName;
            return true;
        }
    }

    //匹配文件夹
    foreach (const QString &dirName, aDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        isFileInDir(prefix + dirName, filename, filepath);
    }
    return false;
}

/**
 * @brief Json::ParseJsonArray 将一个json数组，按照键来解析
 * @param key
 * @param mObj json主体
 * @param mList 修改的列表
 * @return
 */
bool Json::ParseJsonArray(QString key, QJsonObject &mObj, QStringList &mList)
{
    QJsonValue jsonValue = mObj.value(key);
    if (jsonValue.isArray())
    {
        QJsonArray mArray = jsonValue.toArray(); // json数组
        for (int i = 0; i < mArray.size(); i++)
        {
            //获取货币名称
            //依次将值存储进图
            if (mArray.at(i).isString() || mArray.at(i).isDouble())
            {
                mList.append(mArray.at(i).toString()); //把货币名称存储进列表里
            }
            // else if(mArray.at(i).isDouble())
            // {

            //     mList.append(mArray.at(i).toString());  //把货币名称存储进列表里
            // }
            else
            {
                qDebug() << "没有这样的类型";
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief 解析数据至json文件，解析json文件进数据看ParseJson()
 */
void Json::flushToJson()
{
    qDebug() << "开始刷新数据到json文件";
    int count = currency.getNameList().count(); //数据量
    //开始构建json结构
    QJsonArray nameArray;
    QJsonArray symbolArray;
    QJsonArray rateArray;
    //循环将数据读取到json里
    for (int i = 0; i < count; i++)
    {
        nameArray.append(currency.getNameList().at(i));
        symbolArray.append(currency.getSymbolList().at(i));
        rateArray.append(currency.getRateList().at(i));
    }

    //总体
    QJsonObject json;
    json.insert("name", "在线货币");
    json.insert("url", "https://cn.exchange-rates.org/converter/CNY/");
    json.insert("Currency", nameArray);
    json.insert("CurrencySymbol", symbolArray);
    json.insert("Rate", rateArray);
    QJsonDocument document;
    document.setObject(json);

    //创建文件
    if (filepath.isEmpty()) return;

    QFile aFile(filepath);
    if (!aFile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate))
    {
        qDebug() << "打不开文件";
        return;
    }
    aFile.write(document.toJson());
    aFile.close();

    qDebug() << "创建成功";
    return;
}
/**
 * @brief Json::ParseJson 将json原始数据信息提取出来
 * @param data
 * @return
 */
bool Json::ParseJsonData(QString &data)
{
    // qDebug() << data;
    currency.clear();
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
    if (jsonDoc.isObject()) //如果json主体是object
    {
        QJsonObject object = jsonDoc.object();
        if (object.contains("name"))
            if (object.value("name").toString() != "在线货币")
            {
                return false;
            }
        if (object.contains("url"))
        { //获取网络地址
            QJsonValue jsonValue = object.value("url");
            if (jsonValue.isString())
            {
                urlStr = jsonValue.toString();
            }
        }
        /*--开始解析货币名称--*/
        if (object.contains("Currency"))
        {
            ParseJsonArray("Currency", object, currency.getNameList());
        }
        /*--开始解析货币符号--*/
        if (object.contains("CurrencySymbol"))
        {
            ParseJsonArray("CurrencySymbol", object, currency.getSymbolList());
        }
        //开始解析汇率值
        if (object.contains("Rate"))
        {
            ParseJsonArray("Rate", object, currency.getRateList());
        }
    }
    return true;
}
