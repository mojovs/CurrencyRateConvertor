#ifndef MAINUI_H
#define MAINUI_H

#include <QObject>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QLCDNumber>
#include <QPlainTextEdit>
#include "UI/UIManager.h"
#include "Json.h"
class MainUI : public UIManager
{
    Q_OBJECT
  private:
    //转换类型
    enum ConvertType
    {
        YuanToOther,
        OtherToYuan
    };

    void ConvertMoney(int type); //转换货币

  public:
    Json *json; //管理货币数据与json文件的读取与写入
    bool isUIInit = false;
    void init();
    QDoubleSpinBox *dbSpinBoxTimes;     //人民币为其他货币的倍数
    QDoubleSpinBox *dbSpinBoxYuan;      //人民币金额
    QDoubleSpinBox *dbSpinBoxOther;     //其他货币金额
    QDoubleSpinBox *dbSpinBoxDeduction; // steam抽成

    QPushButton *btnGetRate;
    QPushButton *btnDefaultUrl;
    QPushButton *btnTrans;
    QPushButton *btnTest;

    QLineEdit *txtUrl;
    QLineEdit *txtDeductionRes; //抽成结果
    QLineEdit *txtBoughtMoeny;  //买入金额
    QLineEdit *txtStreamRate;   //买入金额

    QComboBox *combCurrency; //货币类型

    QLCDNumber *lcdNumber; // lcd显示

    QPlainTextEdit *txtShow; //显示

    explicit MainUI(QObject *parent = nullptr);
    ~MainUI();

    virtual void update2UI();
    virtual void attatchUIComponent(QList<QObject *> &uiList); //将界面组件添加至UI管理类
    void updateRate(QString symbol, qreal rate);               //更新汇率到界面
    void setUrlByCurrency();                                   //根据当前货币设置网址
    QString getCurrencySymbol();                               //获取当前货币的符号
    QString getUrlStr();                                       //根据界面的货币获取搜索网址

  public slots:
    void on_btnDefaultUrl_clicked(); //获取默认网址
    void on_btnTrans_clicked();      //开始转换
    void on_btnTest_clicked();       //测试按钮

    void on_dbSpinBoxYuan_editfinished();
    void on_dbSpinBoxOther_editfinished();

    void on_combCurrency_index_changed(int index); //当前货币combobox改变，

  signals:
    void getRate();
};

#endif // MAINUI_H
