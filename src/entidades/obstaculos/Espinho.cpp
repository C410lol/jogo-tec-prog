#include "entidades/obstaculos/Espinho.h"

#include "entidades/personagens/Jogador.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            Espinho::Espinho(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_danosidade):
            Obstaculo(r_posicao, r_tamanho, r_danoso), danosidade(r_danosidade)
            {}
            Espinho::Espinho(): danosidade(0) {
                tamanho = sf::Vector2f(48.f, 48.f);
                posicao = sf::Vector2f(400.f, 452.f);

                retangulo.setSize(tamanho);
                retangulo.setPosition(posicao);
                retangulo.setFillColor(sf::Color::Cyan);
            }
            Espinho::~Espinho() = default;




            void Espinho::obstaculizar(Entidade *pEntidade) {
                if (!pEntidade)
                    return;

                personagens::Jogador* pJogador = dynamic_cast<personagens::Jogador*>(pEntidade);
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
