#include <QBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QTextEdit>
#include "Lancement.h"
#include "MainWindow.h"


Lancement::Lancement(QWidget* parent) : QMainWindow(parent){

    QWidget* mainWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();

    this->bouton = new QPushButton("Play");
    //QLabel* pseudo = new QLabel("Entrer un pseudo :");
    this->lineEdit = new QLineEdit();

    layout->addWidget(bouton);
    layout->addWidget(lineEdit);
    //layout->addWidget(play);

    connect(bouton, SIGNAL(clicked()), this, SLOT(recupPseudoPlay()));

    mainWidget->setLayout(layout);
    this->setCentralWidget(mainWidget);

    /*QVBoxLayout* layout = new QVBoxLayout();
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

    connect(play, SIGNAL(clicked()), this, SLOT(recupPseudoPlay()));*/
}

/*void Lancement::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    QPixmap pixBackground("../img/foret_test.jpg");
    painter->drawPixmap(QPointF(0,0), pixBackground, sceneRect());
}*/

void Lancement::recupPseudoPlay() {
    QString Qpseudo = lineEdit->text();
    string pseudo = Qpseudo.toStdString();

    close();

    MainWindow* mainWindow = new MainWindow(this);
    mainWindow->show();

    qDebug() << Qpseudo;
}