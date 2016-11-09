#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_thread_start_clicked();

    void on_thread_stop_clicked();

    void on_Pre_Setting_currentIndexChanged(int index);

    void on_off_student_clicked();

private:
    Ui::MainWindow *ui;
    void start(QString dll_name,const char* function_name);
};

#endif // MAINWINDOW_H
