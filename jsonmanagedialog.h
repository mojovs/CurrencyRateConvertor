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
    QStringList  strList;	//名称列表
    QStringList symbolList;	//符号列表
    QStringList rateList;	//汇率

public:
    explicit JsonManageDialog(QWidget *parent = nullptr);
    ~JsonManageDialog();

    bool UpdateToUi();
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




private slots:

    //添加一行
    void on_btnAdd_clicked();

private:
    Ui::JsonManageDialog *ui;
};

#endif // JSONMANAGEDIALOG_H
