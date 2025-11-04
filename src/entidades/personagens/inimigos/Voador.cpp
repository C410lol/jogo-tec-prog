#include "entidades/personagens/inimigos/Voador.h"

#include <cmath>
#include <iostream>


namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                Voador::Voador(Jogador *r_pJogador): Inimigo(r_pJogador)
                {
                    tamanho = sf::Vector2f(50.0f, 50.0f);
                    posicao = sf::Vector2f(600.0f, 100.0f);

                    retangulo.setSize(tamanho);
                    retangulo.setPosition(posicao);
                    retangulo.setFillColor(sf::Color::Yellow);
                }

                Voador::~Voador() = default;




                void Voador::colidir(Entidade *pEntidade)
                {
                    std::cout << "Colidiu com voador" << std::endl;
                }



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
