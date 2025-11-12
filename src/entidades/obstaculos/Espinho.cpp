#include "entidades/obstaculos/Espinho.h"

#include <cmath>
#include <iostream>

#include "entidades/personagens/Jogador.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            int Espinho::instancias = 0;





            Espinho::Espinho(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_danosidade):
            Obstaculo(r_posicao, r_tamanho, r_danoso), danosidade(r_danosidade),
            disMax(r_posicao.x + r_tamanho.x), disMin(r_posicao.x - r_tamanho.x), deslocandoEsquerda(true)
            {
                ++instancias;

                setTexture("../assets/obstaculos/espinho.png");
                fixTexture();
            }
            Espinho::Espinho(): danosidade(0) {}
            Espinho::~Espinho() = default;




            void Espinho::executar()
            {
                if (deslocandoEsquerda) {
                    mover(-0.75, 0);
                    if (getPosicao().x <= disMin)
                        deslocandoEsquerda = false;
                }
                else
                {
                    mover(0.75, 0);
                    if (getPosicao().x >= disMax)
                        deslocandoEsquerda = true;
                }
                pSprite->setPosition(getPosicao());
            }





            void Espinho::obstaculizar(Entidade *pEntidade) {
                if (!pEntidade)
                    return;

                personagens::Jogador* pJogador = dynamic_cast<personagens::Jogador*>(pEntidade);
                if (!pJogador)
                    return;

                sf::Vector2f vetorVelocidade;
                vetorVelocidade.y = -275;
                if (this->getPosicao().x < pJogador->getPosicao().x)
                    vetorVelocidade.x = 175;
                else
                    vetorVelocidade.x = -175;

                pJogador->setNoChao(false);
                pJogador->setKnokback(true);
                pJogador->setVelocidade(vetorVelocidade);
                pJogador->tomarDano(danosidade);
            }

        }
    }
}
