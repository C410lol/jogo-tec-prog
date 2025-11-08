#include "entidades/personagens/inimigos/Inimigo.h"

#include <iostream>


namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                Inimigo::Inimigo(Jogador *r_pJogadorAlvo, int r_vidas, bool r_sofreGravidade):
                Personagem(r_vidas, r_sofreGravidade), pJogadorAlvo(r_pJogadorAlvo)
                {}
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


            }
        }
    }
}
