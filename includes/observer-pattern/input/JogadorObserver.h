#ifndef JOGO_JOGADOROBSERVER_H
#define JOGO_JOGADOROBSERVER_H

#include "observer-pattern/Observer.h"
#include "entidades/personagens/Jogador.h"




namespace jogo {
    namespace observers {

        class JogadorObserver: public Observer
        {
        private:
            entidades::personagens::Jogador* pJogador;

        public:
            JogadorObserver(entidades::personagens::Jogador* r_pJogador);
            JogadorObserver();
            ~JogadorObserver();

            void update(int message) override;

            entidades::personagens::Jogador* getJogador() const;
        };

    }
}




#endif //JOGO_JOGADOROBSERVER_H