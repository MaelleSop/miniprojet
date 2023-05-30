#include "MyScene.h"
#include "MainWindow.h"
#include "Utils.h"

MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {
    /* ***** tests ajout objets à la scène *****
    QGraphicsRectItem* qgri = new QGraphicsRectItem(10, 100, 300, 200, nullptr);
    this->addItem(qgri);
    QGraphicsTextItem* qgti = new QGraphicsTextItem("CIR2 Rennes");
    this->addItem(qgti);
    **********/

    nbrBananesRecup = 0;

    this->setSceneRect(0, 0, 500, 800);

    QPixmap pixmapSinge("../img/singe.png");
    singe = new QGraphicsPixmapItem(pixmapSinge);

    singe->setPos(10, 450);

    this->addItem(singe);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30); //toutes les 30 millisecondes

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(insererBananes()));
    timer2->start(2500);

    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(insererBuissons()));
    timer3->start(3500);
}

MyScene::~MyScene() {

}

void MyScene::insererBananes(){
    QGraphicsPixmapItem* bananes = new QGraphicsPixmapItem(QPixmap("../img/bananes.png"));
    int x = Utils::randInt(0,450);
    bananes->setPos(x, 0);
    bananesList.append(bananes);
    this->addItem(bananes);
}

void MyScene::insererBuissons(){
    QGraphicsPixmapItem* buisson = new QGraphicsPixmapItem(QPixmap("../img/buisson.png"));
    int x = Utils::randInt(0,400);
    buisson->setPos(x,0);
    buissonsList.append(buisson);
    this->addItem(buisson);
}

void MyScene::update() {
    for(int i=0; i<bananesList.size(); i++){
        if(bananesList[i]->y()<750){
            QPointF posBananes = bananesList[i]->pos(); //récupération de la position de l’objet bananes
            bananesList[i]->setPos(posBananes.rx(), posBananes.ry()+5); //incrémentation de la coordonnée y
        }
        if(bananesList[i]->collidesWithItem(singe) || bananesList[i]->y()>740){
            removeItem(bananesList[i]);
            bananesList.remove(i);
            nbrBananesRecup ++;
            qDebug() << nbrBananesRecup;
        }
    }
    for(int j=0; j<buissonsList.size(); j++){
        if(buissonsList[j]->y()<750){
            QPointF posBuisson = buissonsList[j]->pos(); //récupération de la position de l’objet buisson
            buissonsList[j]->setPos(posBuisson.rx(), posBuisson.ry()+5); //incrémentation de la coordonnée y
        }
        if(buissonsList[j]->collidesWithItem(singe) || buissonsList[j]->y()>740){
            removeItem(buissonsList[j]);
            buissonsList.remove(j);
            //MainWindow::mainScene->close();

        }
    }
}

void MyScene::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Q || event->key() == Qt::Key_Left){      //deplacement à gauche
        if(singe->x()>10 && singe->x()<500){
            singe->setPos(singe->x()-10, singe->y());
        }
    }
    if(event->key() == Qt::Key_D || event->key() == Qt::Key_Right){     //deplacement à droite
        if(singe->x()>0 && singe->x()<389){
            singe->setPos(singe->x()+10, singe->y());
        }
    }
    else{
        QGraphicsScene::keyPressEvent(event);
    }
}

void MyScene::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    QPixmap pixBackground("../img/jungle_ok");
    painter->drawPixmap(QPointF(0,0), pixBackground, sceneRect());
}