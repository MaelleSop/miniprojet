#ifndef CPP_QT_TPMINIPROJET_MAINWINDOW_H
#define CPP_QT_TPMINIPROJET_MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QTextEdit>

#include "MyScene.h"
#include "Lancement.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private :
    MyScene* mainScene;
    //Lancement* lancementScene;
    QGraphicsView* mainView;
    QMenu* regleMenu;
    QMenu* helpMenu;

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

public slots:
    void slot_aboutMenu();
    void slot_aboutRegle();
};


#endif //CPP_QT_TPMINIPROJET_MAINWINDOW_H
