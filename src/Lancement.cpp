#include "Lancement.h"

Lancement::Lancement(QObject* parent) : QGraphicsScene(parent){
    this->setSceneRect(0, 0, 500, 800);

}

void Lancement::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    QPixmap pixBackground("../img/jungle_ok");
    painter->drawPixmap(QPointF(0,0), pixBackground, sceneRect());
}