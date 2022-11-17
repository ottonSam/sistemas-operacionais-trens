#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <vector>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
    Q_OBJECT
public:
    Trem(int, int, int);  //construtor
    void run();         //função a ser executada pela thread
    void set_sepeed(int); //função para mudar a velocidade
    void updateRegionState(int, bool); //função para atualizar a lista de estados

//Cria um sinal
signals:
    void updateGUI(int,int,int);
    void updateState(int, bool);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
   std::vector<bool> regioes = {false, false, false, false, false, false, false};
};

#endif // TREM_H
