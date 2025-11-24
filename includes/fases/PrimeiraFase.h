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
            dtos::ObstaculoDTO carregaObstaculos(std::stringstream &linha, dtos::EntidadeDTO entDTO) override;
            void carregaEspinho(std::stringstream &linha, dtos::ObstaculoDTO obsDTO);
            dtos::InimigoDTO carregaInimigos(std::stringstream &linha, dtos::PersonagemDTO perDTO) override;
            void carregaVoador(std::stringstream &linha, dtos::InimigoDTO iniDTO);

            void criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho) override;
            void criarVoador(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao);
            void criarEspinho(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarInimigos(char c, float x, float y) override;
            void criarObstaculos(char c, float x, float y) override;
            void criaBandeira(sf::Vector2f posicao, sf::Vector2f tamanho);

        public:
            PrimeiraFase(int r_numJogadores, IDs id, bool continuar = false);
            ~PrimeiraFase() override;
        };

    }
}




#endif //JOGO_PROLOGUE_H