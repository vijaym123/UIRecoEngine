#include "displayy3.h"
#include "ui_displayy3.h"

displayy3::displayy3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayy3)
{
    ui->setupUi(this);
}

displayy3::~displayy3()
{
    delete ui;
}
