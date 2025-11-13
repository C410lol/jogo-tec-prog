#include "entidades/Projetil.h"

namespace jogo {
    namespace entidades {

        Projetil::Projetil
        (
            sf::Vector2f r_posicao, sf::Vector2f r_tamanho,
            personagens::Personagem *r_pPersonagem, float velocidade, int r_dano
        ): Entidade(r_posicao, r_tamanho), pDono(r_pPersonagem), dano(r_dano)
        {
            vel = velocidade;

            setTexture("../assets/projeteis/bolaDeFogo.png");
            fixTexture();
        }
        Projetil::Projetil(): pDono(nullptr), vel(0), dano(0) {}
        Projetil::~Projetil() { pDono = nullptr; }





        void Projetil::executar() {
            deslocar();
        }
        void Projetil::deslocar() {
            mover(vel, 0.0f);
            pSprite->setPosition(posicao);
        }




        void Projetil::acertar(personagens::Jogador *pJogador)
        {
            if (!pJogador)
                return;

            sf::Vector2f vetorVelocidade;
            vetorVelocidade.y = -400;
            if (this->getPosicao().x < pJogador->getPosicao().x)
                vetorVelocidade.x = 300;
            else
                vetorVelocidade.x = -300;

            pJogador->setNoChao(false);
            pJogador->setKnokback(true);
            pJogador->setVelocidade(vetorVelocidade);
            pJogador->tomarDano(dano);

            pFase->retirarProjetil(this);
        }


    }
}