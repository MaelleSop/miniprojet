#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    this->mainScene = new MyScene;

    this->mainView = new QGraphicsView;
    this->mainView->setScene(mainScene);

    this->setCentralWidget(mainView);
    this->setWindowTitle("My main window");
    this->setFixedSize(500, 840);

    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(update()));
    timer1->start(30);

    regleMenu = menuBar()->addMenu(tr("&Regle"));
    QAction* actionRegle = new QAction(tr("&About"), this);
    connect(actionRegle, SIGNAL(triggered()), this, SLOT(slot_aboutRegle()));
    regleMenu->addAction(actionRegle);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction* actionHelp = new QAction(tr("&About"), this);
    connect(actionHelp, SIGNAL(triggered()), this, SLOT(slot_aboutMenu()));
    helpMenu->addAction(actionHelp);
}

MainWindow::~MainWindow(){

}

void MainWindow::update(){
    bool valuePerdu = MyScene::gameIsOn;
    bool valueRejouer = Rejouer::rejouerGame;

    if(!valuePerdu){
        mainScene->clear();
        this->lastScene = new Rejouer;
        this->mainView->setScene(lastScene);
    }
    if(valueRejouer){
        lastScene->clear();
        MyScene* newScene = new MyScene;
        this->mainView->setScene(newScene);
    }
}

void MainWindow::slot_aboutMenu(){
    QMessageBox msgBox;
    msgBox.setText("A small QT/C++ projet...");
    msgBox.setModal(true); // on souhaite que la fenetre soit modale i.e qu'on ne puisse plus cliquer ailleurs
    msgBox.exec();
}

void MainWindow::slot_aboutRegle(){
    QMessageBox regles;
    regles.setText("Voici les règles du jeu :\nL'objectif du petit singe est de mangé le plus de bananes possible en esquivant le méchant gorille. S'il vous attrape vous avez perdu.");
    regles.setModal(true);
    regles.exec();
}