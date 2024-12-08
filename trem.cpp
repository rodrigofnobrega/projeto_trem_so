#include "trem.h"
#include <QtCore>
#include <iostream>

QMutex Trem::mutexIntersecao0;
bool Trem::intersecaoOcupadaPeloT1 = false;
bool Trem::intersecaoOcupadaPeloT2 = false;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 50;
}

void Trem::setVelocidade(int velocidade) {
    this->velocidade = velocidade;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (intersecaoOcupadaPeloT2 && x >= 300 && x <= 310 && y < 150) {
                mutexIntersecao0.lock();
            }

            if (y == 30 && x <330) {
                if (!intersecaoOcupadaPeloT2) {
                    intersecaoOcupadaPeloT1 = true;
                }
                x+=10;
            }
            else if (x == 330 && y < 150) {
                y+=10;
            }
            else if (x > 60 && y == 150) {
                intersecaoOcupadaPeloT1 = false;
                mutexIntersecao0.unlock();
                x-=10;
            }
            else {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (intersecaoOcupadaPeloT1 && x <= 360 && y == 150) {
                mutexIntersecao0.lock();
            }
            if (x == 350 && y == 150) {
                if (!intersecaoOcupadaPeloT1) {
                    intersecaoOcupadaPeloT2 = true;
                }
            }


            if (y == 30 && x <600) {
                intersecaoOcupadaPeloT2 = false;
                mutexIntersecao0.unlock();
                x+=10;
            }
            else if (x == 600 && y < 150) {
                y+=10;
            }
            else if (x > 330 && y == 150) {
                x-=10;
            }
            else {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}
