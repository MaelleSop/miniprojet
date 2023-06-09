#include "MyScene.h"
#include "MainWindow.h"
#include "Utils.h"



MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {

    nbrBananesRecup = 0;

    this->setSceneRect(0, 0, 500, 800);

    QPixmap pixmapSinge("../img/singe.png");
    singe = new QGraphicsPixmapItem(pixmapSinge);

    singe->setPos(10, 450);
    this->addItem(singe);

    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(update()));
    timer1->start(30); //toutes les 30 millisecondes

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(insererBananes()));
    timer2->start(2500);

    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(insererBuissons()));
    timer3->start(3500);

    // Affichage de l'entête et des scores

    QGraphicsRectItem* rectScore = new QGraphicsRectItem(0, 0, 500, 40);

    QBrush whiteBrush(Qt::white);
    rectScore->setBrush(whiteBrush);

    this->addItem(rectScore);

    QImage image("../img/bananes.png");
    QImage resizedImage = image.scaled(30, 30, Qt::KeepAspectRatio);

    QPixmap banane = QPixmap::fromImage(resizedImage);
    QGraphicsPixmapItem* imgBanane = new QGraphicsPixmapItem(banane);
    imgBanane->setPos(10, 5);

    this->addItem(imgBanane);

    this->textScore = new QGraphicsTextItem();
    textScore->setPos(40, 0);

    // Augmentation de la taille du texte
    QFont font;
    font.setPointSize(20);
    textScore->setFont(font);

    this->addItem(textScore);
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
        if(bananesList[i]->collidesWithItem(singe)){
            removeItem(bananesList[i]);
            bananesList.remove(i);
            nbrBananesRecup ++;

            textScore->setPlainText(QString::number(nbrBananesRecup));
            qDebug() << nbrBananesRecup;
        }
        else if(bananesList[i]->y()>740){
            removeItem(bananesList[i]);
            bananesList.remove(i);
        }
    }
    for(int j=0; j<buissonsList.size(); j++){
        if(buissonsList[j]->y()<750){
            QPointF posBuisson = buissonsList[j]->pos(); //récupération de la position de l’objet buisson
            buissonsList[j]->setPos(posBuisson.rx(), posBuisson.ry()+5); //incrémentation de la coordonnée y
        }
        if(buissonsList[j]->collidesWithItem(singe)){
            removeItem(buissonsList[j]);
            buissonsList.remove(j);
            timer1->stop();
            timer2->stop();
            timer3->stop();

            // Recupérer score du joueur pour l'enregistrer dans un fichier exterieur
            bestScore();
        }
        else if(buissonsList[j]->y()>740){
            removeItem(buissonsList[j]);
            buissonsList.remove(j);
        }
    }
}

void MyScene::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Q || event->key() == Qt::Key_Left){      //deplacement à gauche
        if(singe->x()>10 && singe->x()<500){
            singe->setPos(singe->x()-10, singe->y());
        }
    }
    if(event->key() == Qt::Key_D || event->key() == Qt::Key_Right) {     //deplacement à droite
        if (singe->x() > 0 && singe->x() < 389) {
            singe->setPos(singe->x() + 10, singe->y());
        }
    }
}

void MyScene::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    QPixmap pixBackground("../img/jungle_ok");
    painter->drawPixmap(QPointF(0,0), pixBackground, sceneRect());
}

void MyScene::bestScore() {

    pseudo = "pseudo";

    string const nomFichier("../fichier/scores.txt");
    // Ouverture du fichier => ios::app : permet d'écrire à la fin du fichier
    ofstream fichierW(nomFichier.c_str());

    // Ouverture du fichier en mode lecture
    ifstream fichierR(nomFichier.c_str());

    if (fichierR) {

        string testFichier;

        if(getline(fichierR, testFichier)){
            string line;
            getline(fichierR, line);

            string score;
            getline(fichierR, score);

            int bestScore = stoi(score);

            if (bestScore < nbrBananesRecup) {
                fichierW << pseudo << endl;
                fichierW << nbrBananesRecup << endl;
            }
        } else{
            fichierW << pseudo << endl;
            fichierW << nbrBananesRecup << endl;
        }
    }
}