#ifndef LICENSE_H
#define LICENSE_H

#include <QDialog>

namespace Ui {
class license;
}

class license : public QDialog
{
    Q_OBJECT

public:
    explicit license(QWidget *parent = 0);
    ~license();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::license *ui;
};

#endif // LICENSE_H
