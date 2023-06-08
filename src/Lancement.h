#ifndef MINIPROJET_LANCEMENT_H
#define MINIPROJET_LANCEMENT_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPainter>


using namespace std;

class Lancement : public QGraphicsScene {
    Q_OBJECT
private :

public :
    Lancement(QObject* parent = nullptr);
    void drawBackground(QPainter* painter, const QRectF &rect);
};


#endif //MINIPROJET_LANCEMENT_H
