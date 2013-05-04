#ifndef RECOMMEND_H
#define RECOMMEND_H

#include <QWidget>
#include "whythiswindow.h"

namespace Ui {
class recommend;
}

class recommend : public QWidget
{
    Q_OBJECT
    
public:
    whythiswindow *whythiswin;
    explicit recommend(QWidget *parent = 0);
    ~recommend();
    
private:
    Ui::recommend *ui;

public slots:
    void moveback();
    void openwindow();

signals:
    void movebacktoclusterusers();


};

#endif // RECOMMEND_H
