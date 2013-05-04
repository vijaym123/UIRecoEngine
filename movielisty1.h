#ifndef MOVIELISTY1_H
#define MOVIELISTY1_H

#include <QWidget>

namespace Ui {
class movielisty1;
}

class movielisty1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit movielisty1(QWidget *parent = 0);
    ~movielisty1();
    
private:
    Ui::movielisty1 *ui;
};

#endif // MOVIELISTY1_H
