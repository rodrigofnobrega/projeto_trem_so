#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,330,20);
    trem2 = new Trem(2,730,80);
    trem3 = new Trem(3,330,210);
    trem4 = new Trem(4,460,270);
    trem5 = new Trem(5,870,210);

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
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();

}

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
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

QString MainWindow::atualizarTexto(int value){
    return QString::number(200-value);
}

void MainWindow::on_horizontalSlider_1_valueChanged(int value){
    trem1->setVelocidade(value);
    ui->vT1->setText(atualizarTexto(value));
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value){
    trem2->setVelocidade(value);
    ui->vT2->setText(atualizarTexto(value));
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value){
    trem3->setVelocidade(value);
    ui->vT3->setText(atualizarTexto(value));
}

void MainWindow::on_horizontalSlider_4_valueChanged(int value){
    trem4->setVelocidade(value);
    ui->vT4->setText(atualizarTexto(value));
}

void MainWindow::on_horizontalSlider_5_valueChanged(int value){
    trem5->setVelocidade(value);
    ui->vT5->setText(atualizarTexto(value));
}

MainWindow::~MainWindow()
{
    delete ui;
}
