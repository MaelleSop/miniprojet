#include "Rejouer.h"

Rejouer::Rejouer(QObject* parent) : QGraphicsScene(parent){
    this->setSceneRect(0, 0, 500, 800);

    QGraphicsTextItem* perdu = new QGraphicsTextItem("PERDU !");
    this->addItem(perdu);
}

void Rejouer::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    QPixmap pixBackground("../img/jungle2.png");
    painter->drawPixmap(QPointF(0,0), pixBackground, sceneRect());
}