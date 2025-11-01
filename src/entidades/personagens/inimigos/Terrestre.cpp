#include "entidades/personagens/inimigos/Terrestre.h"



namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                Terrestre::Terrestre(Jogador *r_pJogador): Inimigo(r_pJogador)
                {
                    tamanho = sf::Vector2f(50.0f, 50.0f);
                    posicao = sf::Vector2f(600.0f, 500.0f);

                    retangulo.setSize(tamanho);
                    retangulo.setPosition(posicao);
                    retangulo.setFillColor(sf::Color::Red);
                }
                Terrestre::~Terrestre() = default;


                void Terrestre::deslocar()
                {
                    if (pJogadorAlvo)
                    {
                        float disX = pJogadorAlvo->getPosicao().x - getPosicao().x;

                        //  Se desloca até o jogador até certo raio
                        if (std::abs(disX) > TERRESTRE_RAIO_MAX)
                        {
                            if (disX > 0)
                                mover(VELOCIDADE, 0.f);
                            if (disX < 0)
                                mover(-VELOCIDADE, 0.f);
                        }
                    }
                }

            }
        }
    }
}