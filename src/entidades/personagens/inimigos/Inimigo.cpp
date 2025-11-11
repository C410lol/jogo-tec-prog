#include "entidades/personagens/inimigos/Inimigo.h"
#include "entidades/personagens/Jogador.h"

#include <iostream>


namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                Inimigo::Inimigo(
                    sf::Vector2f r_posicao, sf::Vector2f r_tamanho, int r_vidas, bool r_sofreGravidade
                ):
                Personagem(r_posicao, r_tamanho, r_vidas, r_sofreGravidade), pJogadorAlvo(nullptr)
                {}
                Inimigo::Inimigo() = default;
                Inimigo::~Inimigo() = default;




                void Inimigo::executar()
                {
                    Personagem::executar();
                }




                void Inimigo::colidir(Entidade *pEntidade)
                {
                    if (!pEntidade)
                        return;

                    Jogador* pJogador = dynamic_cast<Jogador*>(pEntidade);
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
                    --(*pJogador);
                }




                void Inimigo::setJogadoralvo(Jogador* pjog)
                {
                    pJogadorAlvo=pjog;
                }

            }
        }
    }
}
