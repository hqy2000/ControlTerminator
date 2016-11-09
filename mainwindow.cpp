#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"
#include <iostream>
#include <QApplication>
#include <QLibrary>
#include <QMessageBox>
#include <QDebug>
#include <QDesktopWidget>
#include <QProcess>
#include <QThread>
#include <QResource>
QRect screen_pos;
typedef int (*Fun)();
void start(QString dll_name,const char* function_name);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    QMessageBox::information(NULL,"使用条款","一切责任由使用者自行承担！");
    ui->setupUi(this);
    ui->thread_stop->setEnabled(false);
    ui->status->setText("准备就绪");
    QDesktopWidget* desktopWidget=QApplication::desktop();
    screen_pos=desktopWidget->screenGeometry();
    screen_pos.setHeight(screen_pos.height()-1);
    screen_pos.setWidth(screen_pos.width()-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_thread_start_clicked()
{
    ui->thread_start->setEnabled(false);
    ui->thread_stop->setEnabled(true);
    ui->by_network->setEnabled(false);
    ui->by_process->setEnabled(false);
    ui->by_thread->setEnabled(false);
    if (ui->by_thread->isChecked())//通过线程
    {
        start("/dll/Thread.dll","allHook");
    }
    if (ui->by_process->isChecked())//通过进程
    {
        start(":/dll/Process.dll","StartHook");
    }
}

void MainWindow::on_thread_stop_clicked()
{
    ui->thread_stop->setEnabled(false);
    ui->thread_start->setEnabled(true);
    ui->by_network->setEnabled(true);
    ui->by_process->setEnabled(true);
    ui->by_thread->setEnabled(true);
    if (ui->by_thread->isChecked())//通过线程
    {
        start(":/dll/Thread.dll","UnHookAPI");
    }
    if (ui->by_process->isChecked())//通过进程
    {
        start(":/dll/Process.dll","UnLoadHook");
    }


}

void MainWindow::start(QString dll_name,const char* function_name)
{
    ui->status->setText("正在加载资源文件");
    ui->progressBar->setValue(25);
    qDebug()<<dll_name;
    QLibrary mylib(dll_name);
    if (mylib.load())
         {
            ui->status->setText("正在读取资源文件");
            ui->progressBar->setValue(50);
             //QMessageBox::information(NULL,"OK","DLL load is OK!");
             Fun open=(Fun)mylib.resolve(function_name);
             if (open)
             {
                 ui->status->setText("读取资源文件成功，正在执行命令");
                 ui->progressBar->setValue(75);
                 //QMessageBox::information(NULL,"OK","Link to Function is OK!");
                 open();
             }
             else
             {
                 ui->status->setText("<html><head/><body><p><span style=' color:#ff0000;'>错误：无法读取资源文件！</span></p></body></html>");
                 return;
             }
         }
         else
        {
            ui->status->setText("<html><head/><body><p><span style=' color:#ff0000;'>错误：无法加载资源文件！</span></p></body></html>");
            return;
        }
    ui->status->setText("执行成功");
    ui->progressBar->setValue(99);
}
void MainWindow::on_Pre_Setting_currentIndexChanged(int index)
{
    QString str;
    switch(index)
    {
        case 0:
            str="";
            break;
        case 1:
            str="x=0";
            break;
        case 2:
            str.setNum(screen_pos.width());
            str="x="+str;
            break;
        case 3:
            str="y=0";
            break;
        case 4:
            str.setNum(screen_pos.height());
            str="y="+str;
            break;
        case 5:
            str="y=-x";
            break;
        case 6:
            str.setNum(screen_pos.height());
            str="y=x-"+str;
            break;
        case 7:
            str.setNum(screen_pos.width());
            str="y=x-"+str;
            break;
        case 8:
            str.setNum(screen_pos.width()+screen_pos.height());
            str="y=-x+"+str;
            break;
        default:
            break;
    }
    ui->Function_Edit->setText(str);
}

void MainWindow::on_off_student_clicked()
{
    QProcess myprocess;
    myprocess.start(":/exe/ntsd.exe");
}
