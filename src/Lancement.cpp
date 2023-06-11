#include <QBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QTextEdit>
#include "Lancement.h"
#include "MainWindow.h"


Lancement::Lancement(QWidget* parent) : QMainWindow(parent){
    this->resize(500,840);
    this->setWindowTitle("Bienvenue !");
    
    QWidget* mainWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();

    this->bouton = new QPushButton("Play");
    QLabel* pseudo = new QLabel("Entrer un pseudo :");
    this->lineEdit = new QLineEdit();

    layout->addWidget(pseudo);
    layout->addWidget(lineEdit);
    layout->addWidget(bouton);

    connect(bouton, SIGNAL(clicked()), this, SLOT(recupPseudoPlay()));

    mainWidget->setLayout(layout);
    this->setCentralWidget(mainWidget);

}

void Lancement::recupPseudoPlay() {
    QString Qpseudo = lineEdit->text();

    close();

    MainWindow* mainWindow = new MainWindow(Qpseudo, this);
    mainWindow->show();

}
