#ifndef MINIPROJET_LANCEMENT_H
#define MINIPROJET_LANCEMENT_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QTimer>
#include <QPainter>
#include <QPushButton>
#include <QSize>
#include <QLabel>
#include <QLineEdit>


using namespace std;

class Lancement : public QGraphicsScene {
    Q_OBJECT
private :
    QGraphicsProxyWidget* mainWidget;
    QLineEdit* inputPseudo;

public :
    Lancement(QObject* parent = nullptr);
    void drawBackground(QPainter* painter, const QRectF &rect);

public slots :
    void recupPseudoPlay();
};


#endif //MINIPROJET_LANCEMENT_H
