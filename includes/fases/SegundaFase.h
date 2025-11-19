//
// Created by mvmko on 16/11/2025.

#ifndef JOGO_SEGUNDAFASE_H
#define JOGO_SEGUNDAFASE_H
#include "Fase.h"


namespace jogo{
    namespace fases
    {
        class SegundaFase:public fases::Fase
        {

        private:
            const int maxTerrestres;
            const int maxChefoes;
            const int maxPlataformas;
            const int maxMelecas;
        private:
            void criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho) override;
            void criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao);
            void criarInimigos(char c, float x, float y) override;
            void criarObstaculos(char c, float x, float y) override;
            void criarChefoes(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarMelecas(sf::Vector2f r_posicao, sf::Vector2f);
        public:
            SegundaFase(int r_numJogadores, IDs id);
            ~SegundaFase() override;
        };
    }


}

#endif //JOGO_SEGUNDAFASE_H
