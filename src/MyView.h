#ifndef MINIPROJET_MYVIEW_H
#define MINIPROJET_MYVIEW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsView>

class MyView : public QGraphicsView{
protected:
    virtual void resizeEvent (QResizeEvent* event) {
        this->fitInView(sceneRect());
    }
};


#endif //MINIPROJET_MYVIEW_H
