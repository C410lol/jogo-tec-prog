#include "fases/Fase.h"




namespace jogo {
    namespace fases {

        gerenciadores::GerenciadorGrafico *Fase::pGerenciadorGrafico = nullptr;
        gerenciadores::GerenciadorColisao *Fase::pGerenciadorColisao = nullptr;


        Fase::Fase(): voador(&jogador), terrestre(&jogador)
        {
            //pCollision = new managers::Collision(&player, &obstacle);
        };
        Fase::~Fase() = default;


        void Fase::setGerenciadorGrafico(
            gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico
        )
        {
            pGerenciadorGrafico = r_pGerenciadorGrafico;
        }
        void Fase::setGerenciadorColisao(gerenciadores::GerenciadorColisao *r_pGerenciadorColisao)
        {
            pGerenciadorColisao = r_pGerenciadorColisao;
        }


        void Fase::exec()
        {
            jogador.exec();
            voador.exec();
            terrestre.exec();

            if (pGerenciadorGrafico)
            {
                //pCollision->checkCollisions();

                pGerenciadorGrafico->desenhar(jogador);
                pGerenciadorGrafico->desenhar(voador);
                pGerenciadorGrafico->desenhar(terrestre);
                //pGraphicManager->draw(obstacle);
            }
        }


    }
}
