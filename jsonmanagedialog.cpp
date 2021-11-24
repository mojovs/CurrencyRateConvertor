#include "jsonmanagedialog.h"
#include "ui_jsonmanagedialog.h"
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QDebug>
#pragma execution_character_set("utf-8")
JsonManageDialog::JsonManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JsonManageDialog)
{

    ui->setupUi(this);
    //寻找json文件
    qDebug()<<"打开json管理窗口";
    MyJson mJson;
    strList= mJson.strList;
    symbolList = mJson.symbolList;
    rateList = mJson.rateList;

    //更新界面
    UpdateToUi();





}

JsonManageDialog::~JsonManageDialog()
{
    delete ui;
}

/*-------------------------更新数据到UI界面--------------------------*/
bool JsonManageDialog::UpdateToUi()
{

    qDebug()<<"更新界面";
    QTableWidget *table=ui->tableWidget;
    table->setColumnCount(3);
    table->setRowCount(1);
    //设置表头居中
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

    table->insertRow(1);
    AddRowItemToTable(0,0,strList,table);
    AddRowItemToTable(0,1,symbolList,table);
    AddRowItemToTable(0,2,rateList,table);

    table->update();


    return true;
}

void JsonManageDialog::AddRowItemToTable(int row,int col, QStringList list, QTableWidget *table, int align)
{
    for(int i=0;i<list.size();i++)
    {
        QTableWidgetItem *tableItem0 = new QTableWidgetItem(list.at(i));
        tableItem0->setTextAlignment(align);
        table->setItem(row+i,col,tableItem0);
    }


}

void JsonManageDialog::AddRowItemToTable(int row, int col, QString name, QTableWidget *table, int align)
{
         QTableWidgetItem *tableItem0 = new QTableWidgetItem(name);
        tableItem0->setTextAlignment(align);
        table->setItem(row,col,tableItem0);	//在末尾添加

}



/*-------------------------添加一行数据--------------------------*/
void JsonManageDialog::on_btnAdd_clicked()
{
    QString name=ui->lineEditAddName->text();	//货币名称
    QString symbol=ui->lineEditAddName->text();	//货币符号

    //符号列表
    QTableWidget *table = ui->tableWidget;

    table->insertRow(table->rowCount());	//添加一行
    //创建单元
    AddRowItemToTable(table->rowCount()-1,0,name,table);
    AddRowItemToTable(table->rowCount()-1,1,symbol,table);
    AddRowItemToTable(table->rowCount()-1,2,"1.0",table);

    table->update();



}

