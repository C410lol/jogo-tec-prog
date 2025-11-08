#include "entidades/personagens/inimigos/Voador.h"

#include <cmath>
#include <iostream>


namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                Voador::Voador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
                Inimigo(r_posicao, r_tamanho, 2, false)
                {
                    retangulo.setFillColor(sf::Color::Yellow);
                }
                Voador::Voador() = default;
                Voador::~Voador() = default;




                void Voador::deslocar()
                {
                    if (pJogadorAlvo)
                    {
                        float disX = pJogadorAlvo->getPosicao().x - getPosicao().x;
                        float disY = pJogadorAlvo->getPosicao().y - getPosicao().y;
                        float magnitude = std::sqrt(disX * disX + disY * disY);

                        if (magnitude != 0.f)
                        {
                            //  Normaliza o vetor direção
                            float dirX = disX / magnitude;
                            float dirY = disY / magnitude;

                            mover(dirX * VELOCIDADE, dirY * VELOCIDADE);
                        }
                    }
                }

            }
        }
    }
}
