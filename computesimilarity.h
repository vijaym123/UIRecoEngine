#ifndef COMPUTESIMILARITY_H
#define COMPUTESIMILARITY_H

#include <QWidget>

namespace Ui {
class computesimilarity;
}

class computesimilarity : public QWidget
{
    Q_OBJECT
    
public:
    explicit computesimilarity(QWidget *parent = 0);
    ~computesimilarity();
    
private:
    Ui::computesimilarity *ui;

public slots:
    void movenext();
    void moveback();

signals:
    void movetoclusterusers();
    void movebacktoreducedimension();

};

#endif // COMPUTESIMILARITY_H
