#ifndef JOGO_JOGO_H
#define JOGO_JOGO_H

#include "menus/MenuPrincipal.h"
#include "fases/PrimeiraFase.h"
#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {

    class Jogo
    {
        menus::MenuPrincipal *pMenuPrincipal;
        fases::PrimeiraFase primeiraFase;
        gerenciadores::GerenciadorGrafico gerenciadorGrafico;

    public:
        Jogo();
        ~Jogo();

        void exec();
    };

}




#endif //JOGO_JOGO_H