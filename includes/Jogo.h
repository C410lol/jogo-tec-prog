#ifndef JOGO_JOGO_H
#define JOGO_JOGO_H

#include "menus/Menu.h"
#include "gerenciadores/GerenciadorGrafico.h"
#include "entidades/personagens/Jogador.h"
#include "observer-pattern/input/InputSubject.h"
#include "observer-pattern/input/JogadorObserver.h"


namespace jogo {
    namespace gerenciadores {
        class GerenciadorEstado;
    }

    class Jogo {
    private:
        gerenciadores::GerenciadorEstado *pge;
        gerenciadores::GerenciadorGrafico gerenciadorGrafico;
        Menu *pMenu;
        std::vector<entidades::personagens::Jogador *> jogadores;
        std::vector<observers::JogadorObserver *> jogadorObservers;

    public:
        Jogo();

        ~Jogo();

        void exec();

        void criarJogadores();

        void resetarJogadores();

        std::vector<entidades::personagens::Jogador *> &getJogadores();
    };
}


#endif //JOGO_JOGO_H