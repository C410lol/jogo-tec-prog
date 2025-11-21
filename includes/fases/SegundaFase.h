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
            dtos::ObstaculoDTO carregaObstaculos(std::stringstream &linha, dtos::EntidadeDTO entDTO) override;
            void carregaMeleca(std::stringstream &linha, dtos::ObstaculoDTO obsDTO);
            dtos::InimigoDTO carregaInimigos(std::stringstream &linha, dtos::PersonagemDTO perDTO) override;
            void carregaChefao(std::stringstream &linha, dtos::InimigoDTO iniDTO);

            void criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho) override;
            void criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao);
            void criarInimigos(char c, float x, float y) override;
            void criarObstaculos(char c, float x, float y) override;
            void criarChefoes(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarMelecas(sf::Vector2f r_posicao, sf::Vector2f);

        public:
            SegundaFase(int r_numJogadores, IDs id, bool continuar = false);
            ~SegundaFase() override;
        };
    }


}

#endif //JOGO_SEGUNDAFASE_H
