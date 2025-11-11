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
                        float disY = pJogadorAlvo->getPosicao().y - getPosicao().y;

                        //  Se desloca até o jogador até certo raio
                        //if (std::abs(disX) > TERRESTRE_RAIO_MAX)
                        //{
                        if (abs(disY)<50)
                        {
                            if (disX > 0) {
                                mover(VELOCIDADE, 0.f);
                            }
                            if (disX < 0) {
                                mover(-VELOCIDADE, 0.f);
                            }
                        }
                        //}
                        olhandoDireita = disX >= 0;
                    }
                }

            }
        }
    }
}
