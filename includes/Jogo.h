#ifndef JOGO_JOGO_H
#define JOGO_JOGO_H

#include "fases/PrimeiraFase.h"
#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {

    class Jogo
    {
        fases::Fase *pFase;
        gerenciadores::GerenciadorGrafico gerenciadorGrafico;

    public:
        Jogo();
        ~Jogo();

        void exec();
    };

}




#endif //JOGO_JOGO_H