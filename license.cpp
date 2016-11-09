#include "license.h"
#include "ui_license.h"
license::license(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::license)
{
    ui->setupUi(this);
}

license::~license()
{
    delete ui;
}


void license::on_buttonBox_accepted()
{

}
