#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QLabel>

// Import des bibliothèques c++
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyScene : public QGraphicsScene {
    Q_OBJECT
private :
    QGraphicsPixmapItem* singe;
    QTimer* timer1;
    QTimer* timer2;
    QTimer* timer3;
    QList<QGraphicsPixmapItem*> bananesList;
    QList<QGraphicsPixmapItem*> buissonsList;
    QGraphicsTextItem* textScore;

    string pseudo;
public:
    int nbrBananesRecup;
    static bool gameIsOn;
    MyScene(QObject* parent = nullptr);
    virtual ~MyScene();
    void keyPressEvent(QKeyEvent* event);
    void drawBackground(QPainter* painter, const QRectF &rect);
    void bestScore();

public slots :
    void update();
    void insererBananes();
    void insererBuissons();
};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
