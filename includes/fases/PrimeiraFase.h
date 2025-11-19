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
            const int maxPlataformas;
            const int maxEspinhos;
        private:
            void criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho) override;
            void criarVoador(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao);
            void criarEspinho(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarInimigos(char c, float x, float y) override;
            void criarObstaculos(char c, float x, float y) override;

        public:
            PrimeiraFase(int r_numJogadores, IDs id);
            ~PrimeiraFase() override;
        };

    }
}




#endif //JOGO_PROLOGUE_H