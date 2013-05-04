#ifndef REDUCEDIMENSION_H
#define REDUCEDIMENSION_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class reduceDimension;
}

class reduceDimension : public QWidget
{
    Q_OBJECT
    
public:

    QProcess *proc;
    explicit reduceDimension(QWidget *parent = 0);
    ~reduceDimension();
    
private:
    Ui::reduceDimension *ui;

public slots:
    void reducedimension();
    void moveback();
    void movenext();

signals:
    void movebacktouserprofile();
    void movetocomputesimilarity();

};

#endif // REDUCEDIMENSION_H
