#include "reducedimension.h"
#include "ui_reducedimension.h"
#include <QFileDialog>
#include <QPalette>
#include <QDebug>

reduceDimension::reduceDimension(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reduceDimension)
{
    ui->setupUi(this);
    proc=new QProcess();
    connect(ui->Reducedimension,SIGNAL(clicked()),this,SLOT(reducedimension()));
    connect(ui->back,SIGNAL(clicked()),this,SLOT(moveback()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(movenext()));


}

reduceDimension::~reduceDimension()
{
    delete ui;
}

void reduceDimension::reducedimension()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/");



        QPalette p = palette();


           QPixmap pixmap1((fileNames[0]));



           QSize size(ui->image->width(), ui->image->height());
           //resize as per your requirement..
           pixmap1=(pixmap1.scaled(size));
           ui->image->setPixmap(pixmap1);
}

void reduceDimension::moveback()
{
    qDebug()<<"came";
    emit movebacktouserprofile();
}

void reduceDimension::movenext()
{
    emit movetocomputesimilarity();
}

