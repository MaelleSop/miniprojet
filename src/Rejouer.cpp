#include "Rejouer.h"

Rejouer::Rejouer(QObject* parent) : QGraphicsScene(parent){
    this->setSceneRect(0, 0, 500, 800);

    QVBoxLayout* layoutV = new QVBoxLayout();

    QGraphicsTextItem* perdu = new QGraphicsTextItem("VOUS AVEZ PERDU !");
    this->addItem(perdu);

    this->rejouer = new QPushButton(QString("Rejouer"));
    QPixmap pixmap("../img/rejouer.png"); // Chemin vers l'image
    QIcon icon(pixmap);
    rejouer->setIcon(icon);
    rejouer->setIconSize(pixmap.size());
    connect(rejouer, SIGNAL(clicked()), this, SLOT(relancer()));
    layoutV->addWidget(rejouer);

}

void Rejouer::relancer(){

}

void Rejouer::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    QPixmap pixBackground("../img/jungle2.jpg");
    painter->drawPixmap(QPointF(0,0), pixBackground, sceneRect());
}