#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <iostream>
#include <fstream>
#include "Json.h"
#include "Networker.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
  private:
    Json *json;
    Networker *networker;
    void init(); //初始化

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private slots:
    /*--自定义函数--*/

    void on_act_setJson_triggered();

    void on_action_about_triggered();

    void on_action_simpleView_triggered(bool checked);

  private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
