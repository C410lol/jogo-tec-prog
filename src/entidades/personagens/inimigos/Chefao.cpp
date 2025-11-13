#include "entidades/personagens/inimigos/Chefao.h"

#include <iostream>

#include "entidades/personagens/Jogador.h"
#include "entidades/personagens/inimigos/Inimigo.h"
#include "fases/Fase.h"
#include "gerenciadores/GerenciadorColisao.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                int Chefao::instancias = 0;
                int Chefao::getInstancias() { return instancias; }




                Chefao::Chefao(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
                Inimigo(r_posicao, r_tamanho, 5, true, 3),
                rapidez(rand() % 3 + 1)
                {
                    ++instancias;
                    deslocamento = 3;

                    setTexture("../assets/personagens/mago.png");
                    fixTexture();
                }
                Chefao::Chefao(): rapidez(0) {}
                Chefao::~Chefao() = default;




                void Chefao::executar()
                {
                    atirar();
                    Inimigo::executar();
                }




                void Chefao::deslocar()
                {
                    if (pJogadorAlvo)
                    {
                        float disX = pJogadorAlvo->getPosicao().x - getPosicao().x;

                        if (disX > RAIO_MAX)
                        {
                            olhandoDireita = true;
                            mover(deslocamento, 0.f);
                        }
                        if (disX < -RAIO_MAX)
                        {
                            olhandoDireita = false;
                            mover(-deslocamento, 0.f);
                        }
                    }
                }




                void Chefao::atirar()
                {
                    if (!pJogadorAlvo)
                        return;

                    if (gerenciadores::GerenciadorColisao::calcOverlap(this, pJogadorAlvo).y <= 0)
                        return;

                    pFase->criarProjetil(this);
                }




                float Chefao::getRapidez() const
                {
                    return rapidez;
                }

            }
        }
    }
}
