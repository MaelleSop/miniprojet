#ifndef CPP_QT_TPMINIPROJET_MAINWINDOW_H
#define CPP_QT_TPMINIPROJET_MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QTimer>
#include <QTextEdit>

#include "MyScene.h"
#include "Lancement.h"
#include "Lancement.h"
#include "Rejouer.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

private :
    MyScene* mainScene;
    //Lancement* lancementScene;
    QGraphicsView* mainView;
    Rejouer* lastScene;
    QMenu* regleMenu;
    QMenu* helpMenu;
    QTimer* timer1;

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

public slots:
    void slot_aboutMenu();
    void slot_aboutRegle();
    void update();
};


#endif //CPP_QT_TPMINIPROJET_MAINWINDOW_H
