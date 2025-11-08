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
        private:
            void abrirFaseTemplate() override;
            void criarTerrestres(sf::Vector2f posicao, sf::Vector2f tamanho) override;
            void criarPlataformas(sf::Vector2f posicao, sf::Vector2f tamanho) override;
            void criarJogadores(sf::Vector2f posicao, sf::Vector2f tamanho) override;
            void criarInimigos() override;
            void criarObstaculos() override;

            void criarVoadores(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarMelecas(sf::Vector2f posicao, sf::Vector2f tamanho);

        public:
            PrimeiraFase();
            ~PrimeiraFase() override;
        };

    }
}




#endif //JOGO_PROLOGUE_H