#include "entidades/obstaculos/Espinho.h"

#include <iostream>

#include "entidades/personagens/Jogador.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            Espinho::Espinho(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_danosidade):
            Obstaculo(r_posicao, r_tamanho, r_danoso), danosidade(r_danosidade)
            {
                retangulo.setFillColor(sf::Color::Magenta);
            }
            Espinho::Espinho(): danosidade(0) {}
            Espinho::~Espinho() = default;




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
                --(*pJogador);
            }


        }
    }
}
