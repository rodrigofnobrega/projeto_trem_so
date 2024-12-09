#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex>

class Trem : public QThread {
    Q_OBJECT
public:
    Trem(int, int, int); // Construtor
    void setVelocidade(int velocidade);
    void run(); // Função executada pela thread

signals:
    void updateGUI(int, int, int);

private:
    int x; // Posição X do trem na tela
    int y; // Posição Y do trem na tela
    int ID; // ID do trem
    int velocidade; // Velocidade

    static QMutex mutexIntersecao0; // Mutex para sincronizar acesso à interseção
    static QMutex mutexIntersecao4; // Mutex para sincronizar acesso à interseção
    static QMutex mutexIntersecao6; // Mutex para sincronizar acesso à interseção
    static QMutex mutexIntersecao3; // Mutex para sincronizar acesso à interseção
    static bool intersecao0ocupadaPeloT1; // Indica se a área de interseção está ocupada
    static bool intersecao0ocupadaPeloT2; // Indica se a área de interseção está ocupada
    static bool intersecao4ocupadaPeloT2; // Indica se a área de interseção está ocupada
    static bool intersecao4ocupadaPeloT3; // Indica se a área de interseção está ocupada
    static bool intersecao6ocupadaPeloT4; // Indica se a área de interseção está ocupada
    static bool intersecao6ocupadaPeloT3; // Indica se a área de interseção está ocupada
    static bool intersecao3ocupadaPeloT2; // Indica se a área de interseção está ocupada
    static bool intersecao3ocupadaPeloT4; // Indica se a área de interseção está ocupada
};

#endif // TREM_H
