#ifndef JOGO_FASE_H
#define JOGO_FASE_H

#include "gerenciadores/GerenciadorColisao.h"
#include "listas/Lista.h"
#include"listas/ListaEntidades.h"




namespace jogo {
    namespace fases {

        class Fase
        {
        private:
            void criaJogadores();
            void criaInimigos();
            void criaObstaculos();

        protected:

            gerenciadores::GerenciadorColisao GerenciadorColisao;
            listas::ListaEntidades listaEntidades;

        public:
            Fase();
            virtual ~Fase();

            virtual void exec();


        };

    }
}




#endif //JOGO_FASE_H