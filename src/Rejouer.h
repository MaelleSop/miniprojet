#ifndef MINIPROJET_REJOUER_H
#define MINIPROJET_REJOUER_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPainter>


using namespace std;

class Rejouer : public QGraphicsScene {
    Q_OBJECT
private :

public :
    Rejouer(QObject* parent = nullptr);
    void drawBackground(QPainter* painter, const QRectF &rect);
};


#endif //MINIPROJET_REJOUER_H
