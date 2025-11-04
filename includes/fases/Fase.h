#ifndef JOGO_FASE_H
#define JOGO_FASE_H

#include "gerenciadores/GerenciadorColisao.h"
#include "listas/Lista.h"




namespace jogo {
    namespace fases {

        class Fase
        {
        private:
            void criaJogadores();
            void criaInimigos();
            void criaObstaculos();

        protected:
            static gerenciadores::GerenciadorGrafico *pGerenciadorGrafico;
            gerenciadores::GerenciadorColisao *pGerenciadorColisao;
            listas::Lista<entidades::personagens::Jogador*> listaJogadores;
            listas::Lista<entidades::personagens::inimigos::Inimigo*> listaInimigos;
            listas::Lista<entidades::obstaculos::Obstaculo*> listaObstaculos;

        public:
            Fase();
            virtual ~Fase();

            virtual void exec();

            static void setGerenciadorGrafico(gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico);
        };

    }
}




#endif //JOGO_FASE_H