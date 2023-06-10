#ifndef MINIPROJET_REJOUER_H
#define MINIPROJET_REJOUER_H

#include <iostream>
#include <QtWidgets>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsView>

using namespace std;

class Rejouer : public QGraphicsScene {
    Q_OBJECT
private :
    QGraphicsProxyWidget* proxyWidget;

public :
    Rejouer(QObject* parent = nullptr);
    void drawBackground(QPainter* painter, const QRectF &rect);
    static bool rejouerGame;

public slots:
    void relancer();
};


#endif //MINIPROJET_REJOUER_H
