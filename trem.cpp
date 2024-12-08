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
            if (intersecaoOcupadaPeloT2 && x >= 330 && x <= 340 && y < 150) {
                mutexIntersecao0.lock();
            }

            if (y < 150 && x >= 350 && x < 360) {
                if (!intersecaoOcupadaPeloT2) {
                    intersecaoOcupadaPeloT1 = true;
                }
            }

            if (y == 30 && x < 360) {
                x+=10;
            }
            else if (x == 360 && y < 150) {
                y+=10;
            }
            else if (x > 90 && y == 150) {
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
            if (intersecaoOcupadaPeloT1 && x <= 390 && y == 150) {
                mutexIntersecao0.lock();
            }
            if (x >= 360 && x <= 370 && y > 30) {
                if (!intersecaoOcupadaPeloT1) {
                    intersecaoOcupadaPeloT2 = true;
                }
            }


            if (y == 30 && x <630) {
                intersecaoOcupadaPeloT2 = false;
                mutexIntersecao0.unlock();
                x+=10;
            }
            else if (x == 630 && y < 150) {
                y+=10;
            }
            else if (x > 360 && y == 150) {
                x-=10;
            }
            else {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 3: //Trem 3
            if (y < 270 && x == 720) {
                y+=10;
            }
            else if (x > 500 && y == 270) {
                x-=10;
            }
            else if (x == 500 && y <= 270 && y > 150) {
                y-=10;
            }
            else {
                x+=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}
