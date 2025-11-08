#include "entidades/personagens/inimigos/Terrestre.h"

#include <iostream>


namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                Terrestre::Terrestre(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
                Inimigo(r_posicao, r_tamanho, 1, true)
                {
                    retangulo.setFillColor(sf::Color::Red);
                }
                Terrestre::Terrestre() = default;
                Terrestre::~Terrestre() = default;




                void Terrestre::executar() {
                    Personagem::executar();
                }




                void Terrestre::deslocar()
                {
                    if (pJogadorAlvo)
                    {
                        float disX = pJogadorAlvo->getPosicao().x - getPosicao().x;

                        //  Se desloca até o jogador até certo raio
                        //if (std::abs(disX) > TERRESTRE_RAIO_MAX)
                        //{
                            if (disX > 0)
                                mover(VELOCIDADE, 0.f);
                            if (disX < 0)
                                mover(-VELOCIDADE, 0.f);
                        //}
                    }
                }

            }
        }
    }
}
