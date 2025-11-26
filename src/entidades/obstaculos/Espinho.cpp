#include "entidades/obstaculos/Espinho.h"

#include <cmath>
#include <iostream>

#include "entidades/personagens/Jogador.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            int Espinho::numInstancias = 0;
            int Espinho::getInstancias() { return numInstancias; }
            void Espinho::setInstancias(int r_instancias) { numInstancias = r_instancias; }







            Espinho::Espinho(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_danosidade):
            Obstaculo(r_posicao, r_tamanho, r_danoso), danosidade(r_danosidade),
            disMax(r_posicao.x + r_tamanho.x), disMin(r_posicao.x - r_tamanho.x), deslocandoEsquerda(true)
            {
                ++numInstancias;

                setTexture("../assets/obstaculos/espinho.png");
                fixTexture();
            }
            Espinho::Espinho
            (
                dtos::ObstaculoDTO obsDTO, int r_danosidade, float r_disMax,
                float r_disMin, bool r_deslocandoEsquerda
            ):
            Obstaculo(obsDTO), danosidade(r_danosidade), disMax(r_disMax),
            disMin(r_disMin), deslocandoEsquerda(r_deslocandoEsquerda)
            {
                ++numInstancias;

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




            void Espinho::salvar()
            {
                Obstaculo::salvar();
                buffer << static_cast<int>(IDs::espinho) << " " << danosidade << " " << disMax << " " <<
                disMin << " " << deslocandoEsquerda;
            }

        }
    }
}
