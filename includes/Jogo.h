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
        observers::InputSubject *inputSubject;
        Menu *pMenu;
        std::list<entidades::personagens::Jogador *> listaJogadores;

    public:
        Jogo();
        ~Jogo();

        void exec();
        bool verificaVazio();
        void incluiJogador(entidades::personagens::Jogador *pjog);
        void retirarJogador(entidades::personagens::Jogador *pjog);
        int getTam();
        void setposicao(sf::Vector2f posicao, sf::Vector2f tamanho, int pos);
        entidades::personagens::Jogador* getJogador(int pos);

    };

}




#endif //JOGO_JOGO_H