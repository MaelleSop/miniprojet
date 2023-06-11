#ifndef MINIPROJET_LANCEMENT_H
#define MINIPROJET_LANCEMENT_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPainter>
#include <QBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QSize>
#include <QLabel>


#include "MyScene.h"


using namespace std;

class Lancement : public QGraphicsScene {
    Q_OBJECT
private :
    QGraphicsProxyWidget* mainWidget;
    QLineEdit* inputPseudo;

public :
    Lancement(QObject* parent = nullptr);
    void drawBackground(QPainter* painter, const QRectF &rect);
    static bool play;

public slots :
    void recupPseudoPlay();
};


#endif //MINIPROJET_LANCEMENT_H
