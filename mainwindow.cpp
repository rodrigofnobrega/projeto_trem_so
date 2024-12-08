#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Configurar o range dos sliders
    ui->slider_trem_1->setRange(0, 200);
    ui->slider_trem_2->setRange(0, 200);
    ui->slider_trem_3->setRange(0, 200);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,90,30);
    trem2 = new Trem(2,360,30);
    trem3 = new Trem(3,720,150);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem1->start();
    trem2->start();
    trem3->start();
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Mudar velocidade dos trens arrastando o slider
*/
void MainWindow::on_slider_trem_1_valueChanged(int value) {
    trem1->setVelocidade(value);
}

void MainWindow::on_slider_trem_2_valueChanged(int value) {
    trem2->setVelocidade(value);
}

void MainWindow::on_slider_trem_3_valueChanged(int value) {
    trem3->setVelocidade(value);
}
