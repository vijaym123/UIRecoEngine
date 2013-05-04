#include "recommend.h"
#include "ui_recommend.h"

recommend::recommend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recommend)
{
    ui->setupUi(this);

    whythiswin=new whythiswindow();
    connect(ui->back,SIGNAL(clicked()),this,SLOT(moveback()));
    connect(ui->whythis,SIGNAL(clicked()),this,SLOT(openwindow()));
}

recommend::~recommend()
{
    delete ui;
}

void recommend::moveback()
{
    emit movebacktoclusterusers();
}


void recommend::openwindow()
{
    whythiswin->show();
}
