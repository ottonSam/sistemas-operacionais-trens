#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<vector>
#include<iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y, velocidade)
    trem1 = new Trem(1,310,30);
    trem2 = new Trem(2,720,90);
    trem3 = new Trem(3, 40, 210);
    trem4 = new Trem(4, 450, 270);
    trem5 = new Trem(5, 850, 210);

    //Inicializa as threads
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();

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

    /*
     * Coneção do UPDATESTATE à função CHANGESTATE
     * Sempre que o sinal UPDATESTATE for chamado será executada a função CHANGESTATE
     * Os parametros da função UPDATESTATE serão utilizados pela CHANGESTATE
     * A função CHANGESTATE atualiza o vetor que armazena o estado de todas as regiões criticas
     * nos objetos (trens)
     */

    connect(trem1, SIGNAL(updateState(int,bool)), SLOT(changeState(int, bool)));
    connect(trem2, SIGNAL(updateState(int,bool)), SLOT(changeState(int, bool)));
    connect(trem3, SIGNAL(updateState(int,bool)), SLOT(changeState(int, bool)));
    connect(trem4, SIGNAL(updateState(int,bool)), SLOT(changeState(int, bool)));
    connect(trem5, SIGNAL(updateState(int,bool)), SLOT(changeState(int, bool)));

}

void MainWindow::on_speed_trem1_sliderReleased(){
    trem1->set_sepeed(200 - ui->speed_trem1->value());
    if (ui->speed_trem1->value() == 0){
        trem1->terminate();
    } else {
        trem1->start();
    }
}

void MainWindow::on_speed_trem2_sliderReleased(){
    trem2->set_sepeed(200 - ui->speed_trem2->value());
    if (ui->speed_trem2->value() == 0){
        trem2->terminate();
    } else {
        trem2->start();
    }
}

void MainWindow::on_speed_trem3_sliderReleased(){
    trem3->set_sepeed(200 - ui->speed_trem3->value());
    if (ui->speed_trem3->value() == 0){
        trem3->terminate();
    } else {
        trem3->start();
    }
}

void MainWindow::on_speed_trem4_sliderReleased(){
    trem4->set_sepeed(200 - ui->speed_trem4->value());
    if (ui->speed_trem4->value() == 0){
        trem4->terminate();
    } else {
        trem4->start();
    }
}

void MainWindow::on_speed_trem5_sliderReleased(){
    trem5->set_sepeed(200 - ui->speed_trem5->value());
    if (ui->speed_trem5->value() == 0){
        trem5->terminate();
    } else {
        trem5->start();
    }
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
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

void MainWindow::changeState(int id, bool state){
    if (id >= 0 && id < 7){
        this->trem1->updateRegionState(id, state);
        this->trem2->updateRegionState(id, state);
        this->trem3->updateRegionState(id, state);
        this->trem4->updateRegionState(id, state);
        this->trem5->updateRegionState(id, state);
    }
    //std::cout << "valor do semaforo " << id << ": " << this->regioes[0] << "\n";
}

MainWindow::~MainWindow()
{
    delete ui;
}
