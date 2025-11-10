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
        private:
            sf::Vector2f proporcao;
        private:
            void setarProporcao();
            void criarFase();
            void criarEntidade(char c, float x, float y);
            void criarJogador(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho);

        protected:
            gerenciadores::GerenciadorColisao gerenciadorColisao;
            listas::ListaEntidades listaEntidades;
            entidades::personagens::Jogador *jogador;
        protected:
            virtual void criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho);
            virtual void criarVoador(sf::Vector2f posicao, sf::Vector2f tamanho);
            virtual void criarEspinho(sf::Vector2f posicao, sf::Vector2f tamanho);

        public:
            Fase();
            virtual ~Fase();

            void inicializar();
            void executar() override;
        };

    }
}




#endif //JOGO_FASE_H