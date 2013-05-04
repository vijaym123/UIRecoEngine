#include "computesimilarity.h"
#include "ui_computesimilarity.h"
#include <QDebug>

computesimilarity::computesimilarity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::computesimilarity)
{
    ui->setupUi(this);
    connect(ui->back,SIGNAL(clicked()),this,SLOT(moveback()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(movenext()));
}

computesimilarity::~computesimilarity()
{
    delete ui;
}

void computesimilarity::movenext()
{
    qDebug()<<"click";
    emit movetoclusterusers();
}

void computesimilarity::moveback()
{
    emit movebacktoreducedimension();
}
