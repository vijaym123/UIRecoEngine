#ifndef USERPROFLISTY2_H
#define USERPROFLISTY2_H

#include <QWidget>

namespace Ui {
class userproflisty2;
}

class userproflisty2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit userproflisty2(QWidget *parent = 0);
    ~userproflisty2();
    
private:
    Ui::userproflisty2 *ui;
};

#endif // USERPROFLISTY2_H
