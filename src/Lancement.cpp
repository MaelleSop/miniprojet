#include <QBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QTextEdit>
#include "Lancement.h"
#include "MyScene.h"

Lancement::Lancement(QObject* parent) : QGraphicsScene(parent){
    this->setSceneRect(0, 0, 500, 800);

    QVBoxLayout* layout = new QVBoxLayout();
    QWidget* widget = new QWidget;
    widget->setLayout(layout);

    QGraphicsProxyWidget *proxyWidget = new QGraphicsProxyWidget();

    QPushButton* play = new QPushButton("Play");
    QLabel* pseudo = new QLabel("Entrer un pseudo :");
    this->inputPseudo = new QLineEdit();

    layout->addWidget(pseudo);
    layout->addWidget(inputPseudo);
    layout->addWidget(play);

    proxyWidget->setWidget(widget);

    // Calcul de la position pour centrer le widget
    float centerX = 500 / 2 - proxyWidget->rect().width() / 2;
    float centerY = 800 / 2 - proxyWidget->rect().height() / 2;
    proxyWidget->setPos(centerX, centerY);

    addItem(proxyWidget);

    connect(play, SIGNAL(clicked()), this, SLOT(recupPseudoPlay()));
}

void Lancement::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    QPixmap pixBackground("../img/foret_test.jpg");
    painter->drawPixmap(QPointF(0,0), pixBackground, sceneRect());
}
void Lancement::recupPseudoPlay() {
    QString Qpseudo = inputPseudo->text();
    string pseudo = Qpseudo.toStdString();
    qDebug() << Qpseudo;
}