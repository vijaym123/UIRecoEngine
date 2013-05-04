#ifndef WHYTHISWINDOW_H
#define WHYTHISWINDOW_H

#include <QMainWindow>
#include "movielisty1.h"
#include "userproflisty2.h"
#include "displayy3.h"

namespace Ui {
class whythiswindow;
}

class whythiswindow : public QMainWindow
{
    Q_OBJECT
    
public:
    movielisty1 *ml;
    userproflisty2 *upl;
    displayy3 *dis;
    explicit whythiswindow(QWidget *parent = 0);
    ~whythiswindow();
    
private:
    Ui::whythiswindow *ui;
};

#endif // WHYTHISWINDOW_H
