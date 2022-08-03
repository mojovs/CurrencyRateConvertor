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
    Json *json;
    //转换类型
    enum ConvertType
    {
        YuanToOther,
        OtherToYuan
    };

    void ConvertMoney(int type); //转换货币

  public:
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
    void updateRate(QString symbol, qreal rate); //更新汇率到界面
    void setUrlByCurrency();                     //根据当前货币设置网址
    QString getCurrencySymbol();                 //获取当前货币的符号
    QString getUrlStr();                         //根据界面的货币获取搜索网址
  public slots:
    void on_btnGetRate_clicked();
    void on_btnDefaultUrl_clicked();
    void on_btnTrans_clicked();
    void on_btnTest_clicked();
  signals:
    void getRate();
};

#endif // MAINUI_H
