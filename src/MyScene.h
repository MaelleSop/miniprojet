#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QLabel>

using namespace std;

class MyScene : public QGraphicsScene {
    Q_OBJECT
private :
    QGraphicsPixmapItem* singe;
    QLabel* compteur;
    QTimer* timer1;
    QTimer* timer2;
    QTimer* timer3;
    QList<QGraphicsPixmapItem*> bananesList;
    QList<QGraphicsPixmapItem*> buissonsList;
    int nbrBananesRecup;

public:
    MyScene(QObject* parent = nullptr);
    virtual ~MyScene();
    void keyPressEvent(QKeyEvent* event);
    void drawBackground(QPainter* painter, const QRectF &rect);

public slots :
    void update();
    void insererBananes();
    void insererBuissons();
};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
