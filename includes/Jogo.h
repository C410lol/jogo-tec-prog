#ifndef JOGO_JOGO_H
#define JOGO_JOGO_H

#include "menus/Menu.h"
#include "gerenciadores/GerenciadorGrafico.h"
#include "observer-pattern/input/InputSubject.h"




namespace jogo {

    class Jogo
    {
    private:
        gerenciadores::GerenciadorEstado* pge;
        gerenciadores::GerenciadorGrafico gerenciadorGrafico;
        observers::InputSubject *inputSubject;
        Menu *pMenu;

    public:
        Jogo();
        ~Jogo();

        void exec();
        void startF1();
        void startF2();
    };

}




#endif //JOGO_JOGO_H