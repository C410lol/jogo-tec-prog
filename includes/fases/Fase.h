#ifndef JOGO_FASE_H
#define JOGO_FASE_H

#include <fstream>

#include "Ente.h"
#include "gerenciadores/GerenciadorColisao.h"
#include "listas/ListaEntidades.h"




namespace jogo {
    namespace fases {

        class Fase: public Ente
        {
        protected:
            sf::Vector2f proporcao;
            std::ifstream faseTemplate;
            gerenciadores::GerenciadorColisao gerenciadorColisao;
            listas::ListaEntidades listaEntidades;
            entidades::personagens::Jogador *jogador;
        protected:
            void setarProporcao();
            virtual void abrirFaseTemplate() = 0;
            virtual void criarTerrestres(sf::Vector2f posicao, sf::Vector2f tamanho) = 0;
            virtual void criarPlataformas(sf::Vector2f posicao, sf::Vector2f tamanho) = 0;
            virtual void criarJogadores(sf::Vector2f posicao, sf::Vector2f tamanho) = 0;
            virtual void criarInimigos() = 0;
            virtual void criarObstaculos() = 0;
            void criarCenario();

        public:
            Fase();
            virtual ~Fase();

            void executar() override;
        };

    }
}




#endif //JOGO_FASE_H