#include "entidades/personagens/inimigos/Terrestre.h"
#include "entidades/personagens/Jogador.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                int Terrestre::instancias = 0;




                Terrestre::Terrestre(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
                Inimigo(r_posicao, r_tamanho, 1, true)
                {
                    ++instancias;
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

                        if (disX > 0)
                        {
                            olhandoDireita = true;
                            mover(VELOCIDADE, 0.f);
                        }
                        if (disX < 0)
                        {
                            olhandoDireita = false;
                            mover(-VELOCIDADE, 0.f);
                        }
                    }
                }

            }
        }
    }
}
