#include "Rejouer.h"
#include "MainWindow.h"


bool Rejouer::rejouerGame = false;

Rejouer::Rejouer(QString newPseudo, QWidget* parent) : QMainWindow(parent), pseudo(newPseudo){
    //this->setSceneRect(0, 0, 500, 800);
    //this->resize(500,840);

    QWidget* widget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout();
    widget->setLayout(layout);

    this->txt = new QLabel("Vous avez perdu !");
    QFont font("Arial", 32);
    this->txt->setFont(font);
    this->txt->setStyleSheet("color: red");
    layout->addWidget(txt);

    //faire un QLabel qui affiche le score

    this->rejouer = new QPushButton();
    QPixmap pixmap("../img/rejouer.png"); // Chemin vers l'image
    QIcon icon(pixmap);
    this->rejouer->setIcon(icon);
    this->rejouer->setIconSize(pixmap.size());
    connect(rejouer, SIGNAL(clicked()), this, SLOT(relancer()));
    layout->addWidget(rejouer);

    widget->setLayout(layout);
    this->setCentralWidget(widget);

    /*QSize widgetSize = widget->size();
    int xBtn = (this->width() - widgetSize.width()) / 2;
    int yBtn = ((this->height() - widgetSize.height()) / 2);
    layout->setPos(xBtn, yBtn);

    addItem(proxyWidget);*/
}

void Rejouer::relancer(){
    close();
    MainWindow* mainWindow = new MainWindow(pseudo, this);
    mainWindow->show();
}

/*void Rejouer::drawBackground(QPainter* painter, const QRectF &rect) {
    Q_UNUSED(rect);
    QPixmap pixBackground("../img/jungle2");
    painter->drawPixmap(QPointF(0,0), pixBackground, sceneRect());
}*/