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

    static QMutex mutexIntersecao; // Mutex para sincronizar acesso à interseção
    static bool intersecaoOcupada; // Indica se a área de interseção está ocupada
};

#endif // TREM_H
