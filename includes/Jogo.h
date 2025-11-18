#ifndef JOGO_JOGO_H
#define JOGO_JOGO_H

#include "gerenciadores/GerenciadorGrafico.h"
#include "observer-pattern/input/InputSubject.h"




namespace jogo {

    class Jogo
    {
    private:
        fases::Fase *pFase;
        gerenciadores::GerenciadorGrafico gerenciadorGrafico;
        observers::InputSubject *inputSubject;

    public:
        Jogo();
        ~Jogo();

        void exec();
    };

}




#endif //JOGO_JOGO_H