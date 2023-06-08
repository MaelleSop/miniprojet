#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->mainScene = new MyScene;

    this->mainView = new QGraphicsView;
    this->mainView->setScene(mainScene);

    this->setCentralWidget(mainView);
    this->setWindowTitle("My main window");
    this->setFixedSize(500, 800);

    regleMenu = menuBar()->addMenu(tr("&egle"));
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

void MainWindow::slot_aboutMenu(){
    QMessageBox msgBox;
    msgBox.setText("A small QT/C++ projet...");
    msgBox.setModal(true); // on souhaite que la fenetre soit modale i.e qu'on ne puisse plus cliquer ailleurs
    msgBox.exec();
}

void MainWindow::slot_aboutRegle(){
    QMessageBox regles;
    regles.setText("Voici les règles du jeu :");
    regles.setModal(true);
    regles.exec();
}