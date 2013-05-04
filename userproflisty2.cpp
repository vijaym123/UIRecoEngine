#include "userproflisty2.h"
#include "ui_userproflisty2.h"

userproflisty2::userproflisty2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userproflisty2)
{
    ui->setupUi(this);
}

userproflisty2::~userproflisty2()
{
    delete ui;
}
