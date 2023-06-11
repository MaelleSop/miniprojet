#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QLabel>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyScene : public QGraphicsScene {
    Q_OBJECT
private :
    QString pseudo;
    double vitesse;
    QGraphicsPixmapItem* singe;
    QGraphicsTextItem* textScore;
    QTimer* timer1;
    QTimer* timer2;
    QTimer* timer3;
    QList<QGraphicsPixmapItem*> bananesList;
    QList<QGraphicsPixmapItem*> gorillesList;

public:
    int nbrBananesRecup;
    static bool gameIsOn;
    MyScene(QString newPseudo = "pseudo", QObject* parent = nullptr);
    virtual ~MyScene();
    void keyPressEvent(QKeyEvent* event);
    void drawBackground(QPainter* painter, const QRectF &rect);
    void bestScore();

public slots :
    void update();
    void insererBananes();
    void insererGorilles();
};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
