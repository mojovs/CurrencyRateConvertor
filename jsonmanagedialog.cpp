#include "jsonmanagedialog.h"
#include "ui_jsonmanagedialog.h"
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#pragma execution_character_set("utf-8")
JsonManageDialog::JsonManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JsonManageDialog)
{

    ui->setupUi(this);
    setWindowTitle("汇率管理器");
    //寻找json文件
    qDebug()<<"打开json管理窗口";
    MyJson mJson;
    strList= mJson.strList;
    symbolList = mJson.symbolList;
    rateList = mJson.rateList;
    fileName =mJson.fileName;

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

    //添加一行
    AddRowItemToTable(0,ColumnType::Name,strList,table);
    AddRowItemToTable(0,ColumnType::Symol,symbolList,table);
    AddRowItemToTable(0,ColumnType::Rate,rateList,table);

    table->update();




    return true;
}

/*-------------------------更新UI界面数据到json文件--------------------------*/
bool JsonManageDialog::UpdateUiToJson()
{
    //先打开文件
    if(!fileName.isEmpty())
    {
        qDebug()<<"打开文件失败，无法同步到json";
        return false;
    }
    QFile aFile(fileName);
    if(!aFile.open(QIODevice::WriteOnly))
    {

        qDebug()<<"打开文件失败，无法同步到json";
        return false;
    }



}

/*-------------------------根据列数分配类型--------------------------*/
bool JsonManageDialog::AddDataToList(ColumnType type, QString &str)
{

    switch (type) {
        case Name:
            strList<<str;
            break;

        case Symol:
            symbolList<<str;
            break;

        case Rate:
            rateList<<str;
            break;
        default:
            break;

    }
    return true;
}

QStringList *JsonManageDialog::FindDataType(ColumnType type)
{
     switch (type) {
        case Name:
         return &strList;
        case Symol:
          return &symbolList;
        case Rate:
            return &rateList;
            break;
        default:
            break;

    }
}

/*-------------------------添加一个item到列表--------------------------*/
void JsonManageDialog::AddRowItemToTable(int row,int col, QStringList list, QTableWidget *table, int align)
{
    for(int i=0;i<list.size();i++)
    {
        if(table->rowCount() < list.count())	//如果当前的UI行数小于当前列表的数量,添加一行
        {
            table->insertRow(table->rowCount());

        }
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

        //把数据添加到List列表里
        AddDataToList((ColumnType)col,name);

}



/*-------------------------添加一行数据--------------------------*/
void JsonManageDialog::on_btnAdd_clicked()
{
    QString name=ui->lineEditAddName->text();	//货币名称
    QString symbol=ui->lineEditAddSymbol->text();	//货币符号

    //符号列表
    QTableWidget *table = ui->tableWidget;

    table->insertRow(table->rowCount());	//添加一行
    //创建单元
    AddRowItemToTable(table->rowCount()-1,ColumnType::Name,name,table);
    AddRowItemToTable(table->rowCount()-1,ColumnType::Symol,symbol,table);
    AddRowItemToTable(table->rowCount()-1,ColumnType::Rate,"1.0",table);

    table->update();


}



/*-------------------------槽 更新数据到本地--------------------------*/
void JsonManageDialog::on_btnUpdate_clicked()
{
    MyJson::CreateJsonFromLists(strList,symbolList,rateList);
    QMessageBox::information(this,"提示","更新文件成功");

}


void JsonManageDialog::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    int row =item->row();
    int col = item->column();	//当前列
    QString str = item->text();	//当前字符串
    qDebug()<<"当前item内容改变";

    QStringList *list = FindDataType((ColumnType)col);
    //更改自符串
    list->replace(row,str);
    //更新到文件
    MyJson::CreateJsonFromLists(strList,symbolList,rateList);
}

