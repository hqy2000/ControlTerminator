#ifndef THREAD
#define THREAD

#endif // THREAD

#include<QThread>
#include<QString>
#include<windows.h>
#include<QMessageBox>
class WorkerThread : public QThread
{
    Q_OBJECT
    void run() Q_DECL_OVERRIDE {
        QString Function_Name=GetFunction();
        int k,b,k_pos,b_pos;
        QString k_f,b_f;
        if(Function_Name.left(2)=="y=")
        {
            QMessageBox::Warning(NULL,"错误","函数左端不为y=！");
            WorkerThread.quit();
            return;
        }

        b_pos=Function_Name.lastIndexOf("+");
        if(b_pos==-1)
            b_pos=Function_Name.lastIndexOf("-");
        if(b_pos!=-1)
        {
            b_f=Function_Name;
            b_f.remove(b_pos+1);
            b=b_f.toInt();
        }

        k_pos=Function_Name.lastIndexOf("=");
        if(k_pos!=-1)
        {
            k_f=Function_Name;
            k_f.remove(k_pos+1);
            k_f.chop(Function_Name.count()-b_pos+1);
            k=k_f.toInt();
        }
        else
        {
            QMessageBox::Warning(NULL,"错误","函数左端不为y=！");
        }


        /* ... here is the expensive or blocking operation ... */
    }

signals:
    QString GetFunction();
    int GetDelay();
};
