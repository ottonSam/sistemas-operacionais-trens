#include "trem.h"
#include <QtCore>
#include <vector>
#include <iostream>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::set_sepeed(int new_velocidade){
    this->velocidade = new_velocidade;
}

//Atualiza a lista de estados
void Trem::updateRegionState(int id, bool state){
    if (id >= 0 && id < 7)
      this->regioes[id] = state;
}

void Trem::run(){

    while(true){

        switch(ID){
        case 1:     //Trem 1
            //Casos de parada do trem 1
            //Região 0
            if(y == 30 && x == 430 && (this->regioes[0] || this->regioes[1] || this->regioes[2]))
                continue;

            //Região 1
            if(y == 150 && x == 330 && this->regioes[1])
                continue;

            //Região 2
            if(y == 120 && x == 450 && (this->regioes[2] || this->regioes[1]))
                continue;

            //Logica de movimentação
            if (y == 30 && x <450){
                x += 10;
                if(x == 440)
                    emit(updateState(0, true));
            }
            else if (x == 450 && y < 150){
                y+=10;
                if (y == 130)
                    emit(updateState(2, true));
            }
            else if (x > 180 && y == 150){
                x-=10;
                if (x == 430)
                    emit(updateState(0, false));
                if (x == 320)
                    emit(updateState(1, true));
                if (x == 290)
                    emit(updateState(2, false));
            }
            else{
                y-=10;
                if (y == 130)
                    emit(updateState(1, false));
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            //Casos de parada do trem 2
            // Região 0
            if(y == 150 && x == 470 && this->regioes[0])
                continue;

            //Região 3
            if(y == 150 && x == 600 && (this->regioes[3] || this->regioes[0]))
                continue;

            //Região 4
            if(y == 130 && x == 720 && (this->regioes[4] || this->regioes[6]))
                continue;

            //Logica de movimentação
            if (y == 30 && x <720){
                x+=10;
                if (x == 470)
                    emit(updateState(0, false));
            }
            else if (x == 720 && y < 150){
                y+=10;
                if (y == 140)
                    emit(updateState(4, true));
            }
            else if (x > 450 && y == 150){
                x-=10;
                if (x == 460)
                    emit(updateState(0, true));
                if (x == 570)
                    emit(updateState(3, true));
                if (x == 560)
                    emit(updateState(4, false));
            }
            else{
                y-=10;
                if (y == 130)
                    emit(updateState(3, false));
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            //Casos de parada
            //Região 1
            if (y == 150 && x == 160 && (this->regioes[1] || this->regioes[5]))
                continue;

            //Região 5
            if (y == 150 && x == 290 && (this->regioes[5]))
                continue;

            //Logica de movimentação
            if (y == 150 && x <310){
                x+=10;
                if (x == 170)
                    emit(updateState(1, true));
                if (x == 300)
                    emit(updateState(5, true));
            }
            else if (x == 310 && y < 270){
                y+=10;
                if (y == 170)
                    emit(updateState(1, false));
            }
            else if (x > 40 && y == 270){
                x-=10;
                if (x == 290)
                    emit(updateState(5, false));
            }
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            //Casos de parada
            //Região 2
            if (y == 170 && x == 310 && (this->regioes[2] || this->regioes[3]))
                continue;

            //Região 3
            if (y == 150 && x == 430 && this->regioes[3])
                continue;

            //Região 5
            if (y == 270 && x == 330 && (this->regioes[5] || this->regioes[2]))
                continue;

            //Região 6
            if (y == 150 && x == 560 && (this->regioes[6]))
                continue;

            //Logica de movimentaçorão
            if (y == 150 && x <580){
                x+=10;
                if (x == 470)
                    emit(updateState(2, false));
                if (x == 460)
                    emit(updateState(3, true));
                if (x == 330)
                    emit(updateState(5, false));
                if (x == 570)
                    emit(updateState(6, true));
            }
            else if (x == 580 && y < 270){
                y+=10;
                if (y == 170)
                    emit(updateState(3, false));
            }
            else if (x > 310 && y == 270){
                x-=10;
                if (x == 320)
                    emit(updateState(5, true));
                if (x == 560)
                    emit(updateState(6, false));
            }
            else{
                y-=10;   
                if (y == 160)
                    emit(updateState(2, true));
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5: //Trem 5
            //Casos de parada
            //Região 4
            if (y == 170 && x == 580 && (this->regioes[4]))
                continue;

            //Região 6
            if (y == 270 && x == 600 && (this->regioes[6] || this->regioes[4]))
                continue;

            //Logica de movimentação
            if (y == 150 && x <850){
                x+=10;
                if (x == 740)
                    emit(updateState(4, false));
                if (x == 600)
                    emit(updateState(6, false));
            }
            else if (x == 850 && y < 270)
                y+=10;
            else if (x > 580 && y == 270){
                x-=10;
                if (x == 590)
                    emit(updateState(6, true));
            }
            else{
                y-=10;
                if (y == 160)
                    emit(updateState(4, true));
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}




