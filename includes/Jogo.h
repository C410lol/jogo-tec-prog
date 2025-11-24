#ifndef JOGO_JOGO_H
#define JOGO_JOGO_H

#include "entidades/personagens/Jogador.h"
#include "menus/Menu.h"
#include "gerenciadores/GerenciadorGrafico.h"
#include "observer-pattern/input/InputSubject.h"




namespace jogo {
    namespace gerenciadores {
        class GerenciadorEstado;
    }

    class Jogo
    {
    private:
        gerenciadores::GerenciadorEstado* pge;
        gerenciadores::GerenciadorGrafico gerenciadorGrafico;
        Menu *pMenu;
        std::list<entidades::personagens::Jogador*> listaJogadores;

    public:
        Jogo();
        ~Jogo();

        std::list<entidades::personagens::Jogador*>* getLista();
        void exec();
        void startF1();
        void startF2();
    };

}




#endif //JOGO_JOGO_H