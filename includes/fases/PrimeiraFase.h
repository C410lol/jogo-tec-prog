#ifndef JOGO_PROLOGUE_H
#define JOGO_PROLOGUE_H

#include "fases/Fase.h"




namespace jogo {
    namespace fases {

        class PrimeiraFase: public Fase
        {
        private:
            const int maxTerrestres;
            const int maxVoadores;
            const int maxEspinhos;
        private:
            void criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho) override;
            void criarVoador(sf::Vector2f posicao, sf::Vector2f tamanho) override;
            void criarEspinho(sf::Vector2f posicao, sf::Vector2f tamanho) override;

        public:
            PrimeiraFase();
            ~PrimeiraFase() override;
        };

    }
}




#endif //JOGO_PROLOGUE_H