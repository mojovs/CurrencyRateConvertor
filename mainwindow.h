#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    qreal times = 0;	//人民币为其他货币的多少倍
    qreal yuan = 0;	//人民币数额
    qreal otherCurrency = 0;	//其他货币的数额
    QString currencyName;	//货币名称
    /*--列表--*/
    QStringList strList;		//存储货币名称列表
    QStringList symbolList;	//货币符号列表

    QNetworkAccessManager networkManager;
    QNetworkReply *reply;
    QString urlStr;		//网络地址
    /*--私有函数--*/
    void setUrlByCurrency();
    void openJson();		//打开json文件
    void parseJson(QString &data);	//解析json，并将解析后的数据传递出去
    QString getCurrencySymbol();	//获取当前货币符号

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /*--自定义函数--*/
    void on_readyRead();	//开始读取网络回复
    void on_pushButtonTrans_clicked();

    void on_btnGetRate_clicked();

    void on_doubleSpinBoxYuan_editingFinished();

    void on_doubleSpinBoxOtherCurrency_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
