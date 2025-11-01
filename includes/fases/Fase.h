#ifndef JOGO_FASE_H
#define JOGO_FASE_H

#include "gerenciadores/GerenciadorGrafico.h"
#include "gerenciadores/GerenciadorColisao.h"
#include "entidades/personagens/Jogador.h"
#include "entidades/obstaculos/Obstaculo.h"
#include "entidades/personagens/inimigos/Voador.h"
#include "entidades/personagens/inimigos/Terrestre.h"




namespace jogo {
    namespace fases {

        class Fase
        {
        protected:
            static gerenciadores::GerenciadorGrafico *pGerenciadorGrafico;
            static gerenciadores::GerenciadorColisao *pGerenciadorColisao;
            entidades::personagens::Jogador jogador;
            //entities::obstacles::Obstacle obstacle;
            entidades::personagens::inimigos::Voador voador;
            entidades::personagens::inimigos::Terrestre terrestre;

        public:
            Fase();
            virtual ~Fase();

            virtual void exec();

            static void setGerenciadorGrafico(gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico);
            static void setGerenciadorColisao(gerenciadores::GerenciadorColisao *r_pGerenciadorColisao);
        };

    }
}




#endif //JOGO_FASE_H