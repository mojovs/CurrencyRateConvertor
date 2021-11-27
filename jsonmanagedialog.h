#ifndef JSONMANAGEDIALOG_H
#define JSONMANAGEDIALOG_H

#include <QDialog>
#include "myjson.h"
#include <QTableWidget>
#define COLS 3

namespace Ui {
class JsonManageDialog;
}

class JsonManageDialog : public QDialog
{
    Q_OBJECT

private:
    enum ColumnType
    {
        Name,
        Symol,
        Rate

    };
    QStringList  strList;	//名称列表
    QStringList symbolList;	//符号列表
    QStringList rateList;	//汇率
    QString fileName;	//文件名

public:
    explicit JsonManageDialog(QWidget *parent = nullptr);
    ~JsonManageDialog();

private:
    /* 添加一行内容的界面
     * @row  要添加的row
     * @col 添加的列
     * @list 该行每个单元的名称
     * @table 要添加的表格界面
     * @align 对齐方式
     */
    void AddRowItemToTable(int row,int col,QStringList list,QTableWidget *table,int align=Qt::AlignCenter);
    void AddRowItemToTable(int row,int col,QString name,QTableWidget *table,int align=Qt::AlignCenter);

    bool UpdateToUi();		//更新数据到UI
    bool UpdateUiToJson();	//更新UI的json数据
    /* 添加数据到对象的List里
     * @type 是哪种类型的数据
     * @str 要添加的数据
     */
    bool AddDataToList(ColumnType type,QString &str);
    /* 根据哪一列，匹配相应的类型
     * @type 类型
     * @return 返回该类型对应的列表
     */
    QStringList* FindDataType(ColumnType type);




private slots:

    //添加一行
    void on_btnAdd_clicked();

    void on_btnUpdate_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::JsonManageDialog *ui;
};

#endif // JSONMANAGEDIALOG_H
