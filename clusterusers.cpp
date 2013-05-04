#include "clusterusers.h"
#include "ui_clusterusers.h"
#include <QDebug>
clusterusers::clusterusers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clusterusers)
{
    ui->setupUi(this);
    connect(ui->next,SIGNAL(clicked()),this,SLOT(movenext()));
    connect(ui->back,SIGNAL(clicked()),this,SLOT(moveback()));
}

clusterusers::~clusterusers()
{
    delete ui;
}

void clusterusers::movenext()
{

    emit movetorecommend();
}

void clusterusers::moveback()
{
    emit movebacktocommputesimilarity();
}
