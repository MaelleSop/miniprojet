#include "Rejouer.h"
#include "MyScene.h"

bool Rejouer::rejouerGame = false;

Rejouer::Rejouer(QObject* parent) : QGraphicsScene(parent){
    this->setSceneRect(0, 0, 500, 800);

    QVBoxLayout* layout = new QVBoxLayout();
    QWidget* widget = new QWidget;
    //widget->setStyleSheet("background-color: transparent;");
    widget->setLayout(layout);

    QLabel* txt = new QLabel("Vous avez perdu !");
    QFont font("Arial", 32);
    txt->setFont(font);
    txt->setStyleSheet("color: red");
    layout->addWidget(txt);

    //faire un QLabel qui affiche le score

    QPushButton* rejouer = new QPushButton();
    QPixmap pixmap("../img/rejouer.png"); // Chemin vers l'image
    QIcon icon(pixmap);
    rejouer->setIcon(icon);
    rejouer->setIconSize(pixmap.size());
    connect(rejouer, SIGNAL(clicked()), this, SLOT(relancer()));
    layout->addWidget(rejouer);

    proxyWidget = new QGraphicsProxyWidget();
    proxyWidget->setWidget(widget);

    QSize widgetSize = widget->size();
    int xBtn = (this->width() - widgetSize.width()) / 2;
    int yBtn = ((this->height() - widgetSize.height()) / 2);
    proxyWidget->setPos(xBtn, yBtn);

    addItem(proxyWidget);
}

void Rejouer::relancer(){
    Rejouer::rejouerGame = true;
}

void Rejouer::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    QPixmap pixBackground("../img/jungle2");
    painter->drawPixmap(QPointF(0,0), pixBackground, sceneRect());
}