#ifndef JOGO_FASE_H
#define JOGO_FASE_H

#include <fstream>

#include "Ente.h"
#include "gerenciadores/GerenciadorColisao.h"
#include "listas/ListaEntidades.h"
#include "entidades/personagens/inimigos/Chefao.h"
#include "entidades/Projetil.h"




namespace jogo {
    namespace fases {

        class Fase: public Ente
        {
        private:
            int numJogadores;
        private:
            void setarProporcao();
            void criarCenario();
            void criarEntidade(char c, float x, float y);
            void criarJogador(sf::Vector2f posicao, sf::Vector2f tamanho);

        protected:
            gerenciadores::GerenciadorColisao gerenciadorColisao;
            listas::ListaEntidades listaEntidades;
            sf::Vector2f proporcao;
        protected:
            virtual void criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho);
            virtual void criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao);
            virtual void criarInimigos(char c, float x, float y) = 0;
            virtual void criarObstaculos(char c, float x, float y) = 0;

        public:
            Fase(int r_numJogadores = 1);
            virtual ~Fase();

            void inicializar();
            void executar() override;

            void criarProjetil(entidades::personagens::inimigos::Chefao *pChefao, float velocidade);
            void retirarProjetil(entidades::Projetil *pProjetil);

            void retirarPersonagem(entidades::personagens::Personagem *pPersonagem);
        };

    }
}




#endif //JOGO_FASE_H