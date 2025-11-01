#ifndef JOGO_COLISION_H
#define JOGO_COLISION_H

#include "entidades/personagens/Jogador.h"
#include "entidades/obstaculos/Obstaculo.h"




namespace jogo {
    namespace gerenciadores {

        class GerenciadorColisao
        {
        private:
            entidades::personagens::Jogador *pJogador;
            entidades::obstacles::Obstaculo *pObstaculo;

        public:
            GerenciadorColisao(
                entidades::personagens::Jogador *r_pJogador,
                entidades::obstacles::Obstaculo *r_pObstaculo
            );
            ~GerenciadorColisao();

            void checarColisao();
        };

    }
}




#endif //JOGO_COLISION_H