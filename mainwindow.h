#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"
#include <QSemaphore>
#include <QSlider>
#include <QAbstractSlider>

static QSemaphore regiao[8];// semaforos das regioes criticas
static QSemaphore mutex;// mutex para controlar as mudanças de estado

static std::array<int, 5> estados{0, 0, 6, 0, 0}; // array que guarda o estado de cada trem

namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private slots:
    QString atualizarTexto(int);
    void on_horizontalSlider_1_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_3_valueChanged(int value);
    void on_horizontalSlider_4_valueChanged(int value);
    void on_horizontalSlider_5_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;

};

#endif // MAINWINDOW_H
