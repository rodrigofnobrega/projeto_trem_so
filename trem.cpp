#include "trem.h"
#include <QtCore>
#include <iostream>

QMutex Trem::mutexIntersecao0;
QMutex Trem::mutexIntersecao4;
QMutex Trem::mutexIntersecao6;
bool Trem::intersecao0ocupadaPeloT1 = false;
bool Trem::intersecao0ocupadaPeloT2 = false;
bool Trem::intersecao4ocupadaPeloT3 = false;
bool Trem::intersecao4ocupadaPeloT2 = false;
bool Trem::intersecao6ocupadaPeloT4 = false;
bool Trem::intersecao6ocupadaPeloT3 = false;

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
            if (intersecao0ocupadaPeloT2 && x >= 330 && x <= 340 && y < 150) {
                mutexIntersecao0.lock();
            }

            if (y < 150 && x >= 350 && x < 360) {
                if (!intersecao0ocupadaPeloT2) {
                    intersecao0ocupadaPeloT1 = true;
                }
            }

            if (y == 30 && x < 360) {
                x+=10;
            }
            else if (x == 360 && y < 150) {
                y+=10;
            }
            else if (x > 90 && y == 150) {
                intersecao0ocupadaPeloT1 = false;
                mutexIntersecao0.unlock();
                x-=10;
            }
            else {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 2: //Trem 2
            if (intersecao0ocupadaPeloT1 && x <= 390 && y == 150) {
                mutexIntersecao0.lock();
            } else if (intersecao4ocupadaPeloT3 && x == 630 && y <= 130 && y >= 110) {
                mutexIntersecao4.lock();
            }

            if (x >= 360 && x <= 370 && y > 30) {
                if (!intersecao0ocupadaPeloT1) {
                    intersecao0ocupadaPeloT2 = true;
                }
            } else if (y >= 130 && y <= 150 && x >= 500) {
                if (!intersecao4ocupadaPeloT3) {
                    intersecao4ocupadaPeloT2 = true;
                }
            }

            if (y == 150 && x < 500) {
                mutexIntersecao4.unlock();
                intersecao4ocupadaPeloT2 = false;
            }


            if (y == 30 && x <630) {
                intersecao0ocupadaPeloT2 = false;
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
            if (intersecao4ocupadaPeloT2 && x < 520 && y >= 170 && y < 190) {
                mutexIntersecao4.lock();
            } else if (intersecao6ocupadaPeloT4 && x >= 520 && x <= 540 && y == 270) {
                mutexIntersecao6.lock();
            }

            else if (x >= 500 && x <= 650 && y == 150) {
                if (!intersecao4ocupadaPeloT2) {
                    intersecao4ocupadaPeloT3 = true;
                }
            } else if (x >= 500 && x <= 510 && y == 270) {
                if (!intersecao6ocupadaPeloT4) {
                    intersecao6ocupadaPeloT3 = true;
                }
            }

            if (x >= 650 && y == 150) {
                intersecao4ocupadaPeloT3 = false;
                mutexIntersecao4.unlock();
            } else if (x >= 520 && y == 150) {
                mutexIntersecao6.unlock();
                intersecao6ocupadaPeloT3 = false;
            }


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

        case 4: //Trem 4
            if (intersecao6ocupadaPeloT3 && x <= 480 && x >= 460 && y == 150) {
                mutexIntersecao6.lock();
            }

            if (x <= 500 && x >= 470 && y == 150) {
                if (!intersecao6ocupadaPeloT3) {
                    intersecao6ocupadaPeloT4 =  true;
                }
            }

            if (x <= 480 && y == 270) {
                mutexIntersecao6.unlock();
                intersecao6ocupadaPeloT4 = false;
            }

            if (x >= 250 && x < 500 && y == 150) {
                x+=10;
            }
            else if (x == 500 && y >= 150 && y < 270) {
                y+=10;
            }
            else if (y == 270 && x <= 500 && x > 250) {
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
