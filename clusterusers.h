#ifndef CLUSTERUSERS_H
#define CLUSTERUSERS_H

#include <QWidget>

namespace Ui {
class clusterusers;
}

class clusterusers : public QWidget
{
    Q_OBJECT
    
public:
    explicit clusterusers(QWidget *parent = 0);
    ~clusterusers();
    
private:
    Ui::clusterusers *ui;

public slots:
    void movenext();
    void moveback();
signals:
    void movetorecommend();
    void movebacktocommputesimilarity();

};

#endif // CLUSTERUSERS_H
