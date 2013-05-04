#include "movielisty1.h"
#include "ui_movielisty1.h"

movielisty1::movielisty1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::movielisty1)
{
    ui->setupUi(this);
}

movielisty1::~movielisty1()
{
    delete ui;
}
