#ifndef JOGO_FASE_H
#define JOGO_FASE_H

#include <vector>

#include "Ente.h"
#include "gerenciadores/GerenciadorColisao.h"
#include "listas/ListaEntidades.h"
#include "entidades/personagens/inimigos/Chefao.h"
#include "entidades/Projetil.h"
#include "observer-pattern/input/JogadorObserver.h"

#include "dtos/EntidadeDTO.h"
#include "dtos/ObstaculoDTO.h"
#include "dtos/PersonagemDTO.h"
#include "dtos/InimigoDTO.h"




namespace jogo {
    namespace fases {

        class Fase: public Ente
        {
        private:
            int numJogadores;
            bool faseAcabou;
        private:
            void carregaPersonagem(std::stringstream& linha, dtos::EntidadeDTO entDTO);
            void carregaJogador(std::stringstream& linha, dtos::PersonagemDTO perDTO);
            void carregaProjetil(std::stringstream& linha, dtos::EntidadeDTO entDTO);

            void setarProporcao();
            void criarCenario();
            void criarEntidade(char c, float x, float y);
            void criarJogador(sf::Vector2f posicao, sf::Vector2f tamanho);
            void retirarJogadorObserver(entidades::personagens::Jogador *pJogador);

        protected:
            gerenciadores::GerenciadorColisao gerenciadorColisao;
            listas::ListaEntidades listaEntidades;
            std::vector<observers::JogadorObserver*> jogadorObservers;
            sf::Vector2f proporcao;
        protected:
            void carregarFase();
            virtual dtos::ObstaculoDTO carregaObstaculos(std::stringstream& linha, dtos::EntidadeDTO entDTO);
            void carregaPlataforma(std::stringstream& linha, dtos::ObstaculoDTO obsDTO);
            virtual dtos::InimigoDTO carregaInimigos(std::stringstream& linha, dtos::PersonagemDTO perDTO);
            void carregaTerrestre(std::stringstream& linha, dtos::InimigoDTO iniDTO);

            virtual void criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho);
            virtual void criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao, IDs id);
            virtual void criarInimigos(char c, float x, float y) = 0;
            virtual void criarObstaculos(char c, float x, float y) = 0;

        public:
            Fase(int r_numJogadores = 1);
            virtual ~Fase();

            void inicializar();
            void executar() override;

            void salvarFase();

            void criarProjetil(entidades::personagens::inimigos::Chefao *pChefao, float velocidade);
            void retirarProjetil(entidades::Projetil *pProjetil);

            void retirarPersonagem(entidades::personagens::Personagem *pPersonagem);

            bool getfaseAcabou() const;
        };

    }
}




#endif //JOGO_FASE_H