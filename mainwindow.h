#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <iostream>
#include <fstream>
#include <Json.h>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
  private:
    enum ConvertType
    {
        YuanToOther,
        OtherToYuan
    };
    Json *json;
    qreal times         = 0;    //人民币为其他货币的多少倍
    qreal yuan          = 0;    //人民币数额
    qreal originMoney   = 0;    // steam买入金额
    qreal otherCurrency = 0;    //其他货币的数额
    qreal deductionRes  = 0;    // steam抽成结果
    qreal deductionRate = 0.15; // steam抽成税率
    qreal finalRate     = 0.0;  //倒余额比率
    QString currencyName;       //货币名称

    /*--列表--*/
    QStringList strList;    //存储货币名称列表
    QStringList symbolList; //货币符号列表
    QStringList rateList;   //汇率列表

    QNetworkAccessManager networkManager;
    QNetworkReply *reply;
    QString urlStr; //网络地址
    /*--私有函数--*/
    void setUrlByCurrency();
    QString getCurrencySymbol(); //获取当前货币符号
    void ConvertMoney(int type); //货币转换
    void ParseJsonToUi();        //解析json中的货币列表到ui界面
    void updateInfo();           //更新本地货币相关信息
  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private slots:
    /*--自定义函数--*/
    void on_readyRead(); //开始读取网络回复
    void on_pushButtonTrans_clicked();

    void on_btnGetRate_clicked();

    void on_doubleSpinBoxYuan_editingFinished();

    void on_act_setJson_triggered();

    void on_comboBoxCurrent_currentIndexChanged(int index);

    void on_doubleSpinBoxOtherCurrency_editingFinished();

    void on_btnDefaultUrl_clicked();

    void on_action_about_triggered();

    void on_action_simpleView_triggered(bool checked);

  private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
