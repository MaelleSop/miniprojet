#ifndef MINIPROJET_REJOUER_H
#define MINIPROJET_REJOUER_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>


using namespace std;

class Rejouer : public QGraphicsScene {
    Q_OBJECT
private :

public :
    Rejouer(QObject* parent = nullptr);
    QPushButton* rejouer;
    void drawBackground(QPainter* painter, const QRectF &rect);
public slots:
    void relancer();
};


#endif //MINIPROJET_REJOUER_H
