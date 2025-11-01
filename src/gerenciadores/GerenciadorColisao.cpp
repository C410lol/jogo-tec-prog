#include "gerenciadores/GerenciadorColisao.h"




namespace jogo {
    namespace gerenciadores {

        GerenciadorColisao::GerenciadorColisao(
            entidades::personagens::Jogador *r_pJogador,
            entidades::obstacles::Obstaculo *r_pObstaculo
        ): pJogador(r_pJogador), pObstaculo(r_pObstaculo)
        {}
        GerenciadorColisao::~GerenciadorColisao()
        {
            pJogador = nullptr;
            pObstaculo = nullptr;
        }

        void GerenciadorColisao::checarColisao()
        {
            if (pObstaculo && pJogador)
            {
                pObstaculo->obstaculizar(*pJogador);
            }
        }


    }
}
