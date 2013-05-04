#include "whythiswindow.h"
#include "ui_whythiswindow.h"

whythiswindow::whythiswindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::whythiswindow)
{
    ui->setupUi(this);
    ml=new movielisty1();
    upl=new userproflisty2();
    dis=new displayy3();

    ui->stackedWidget->addWidget(ml);
    ui->stackedWidget->addWidget(upl);
    ui->stackedWidget->addWidget(dis);
    ui->stackedWidget->setCurrentIndex(0);


}

whythiswindow::~whythiswindow()
{
    delete ui;
}
