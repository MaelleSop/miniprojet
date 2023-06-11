#ifndef MINIPROJET_REJOUER_H
#define MINIPROJET_REJOUER_H

#include <iostream>
#include <QtWidgets>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsView>
#include <QMainWindow>
#include <QWidget>


using namespace std;

class Rejouer : public QMainWindow{
Q_OBJECT
private :
    QLabel* txt;
    QPushButton* rejouer;

    QString pseudo;

public :
    Rejouer(QString newPseudo = "pseudo", QWidget* parent = nullptr);
    void drawBackground(QPainter* painter, const QRectF &rect);
    static bool rejouerGame;

public slots:
    void relancer();
};


#endif //MINIPROJET_REJOUER_H
