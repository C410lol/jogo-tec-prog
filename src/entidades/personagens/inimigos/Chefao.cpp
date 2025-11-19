#include "entidades/personagens/inimigos/Chefao.h"

#include <cmath>
#include <iostream>

#include "entidades/obstaculos/Plataforma.h"
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
                void Chefao::setInstancias(int n) {
                    instancias = n;
                }




                Chefao::Chefao(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
                Inimigo(r_posicao, r_tamanho, 5, true, 1),
                cooldown(0), rapidez(rand() % 5 + 3)
                {
                    ++instancias;
                    deslocamento = 2;

                    setTexture("../assets/personagens/mago.png");
                    fixTexture();
                }
                Chefao::Chefao(): rapidez(0) {}
                Chefao::~Chefao() = default;




                void Chefao::executar()
                {
                    atirar();
                    Inimigo::executar();

                    cooldown /= 1.1;
                }




                void Chefao::deslocar()
                {
                    if (!pJogadorAlvo)
                        return;

                    if (!pJogadorAlvo->getAtivo())
                        return;

                    if (gerenciadores::GerenciadorColisao::calcOverlap(this, pJogadorAlvo).y <= 0)
                        return;

                    float disX = pJogadorAlvo->getPosicao().x - getPosicao().x;
                    if (disX > RAIO_MAX)
                    {
                        olhandoDireita = true;
                        mover(deslocamento, 0.f);
                    }
                    else if (disX < -RAIO_MAX)
                    {
                        olhandoDireita = false;
                        mover(-deslocamento, 0.f);
                    }
                    else
                    {
                        if (disX > 0)
                            mover(-deslocamento, 0);
                        else
                            mover(deslocamento, 0);
                    }
                }




                void Chefao::atirar()
                {
                    if (!pJogadorAlvo || !pJogadorAlvo->getAtivo())
                        return;

                    if (gerenciadores::GerenciadorColisao::calcOverlap(this, pJogadorAlvo).y <= 0)
                        return;

                    if (cooldown > 0.1)
                        return;

                    cooldown = std::pow(1.1, 60);

                    float velocidadeProjetil;
                    if (pJogadorAlvo->getPosicao().x > getPosicao().x)
                        velocidadeProjetil = rapidez;
                    else
                        velocidadeProjetil = -rapidez;

                    pFase->criarProjetil(this, velocidadeProjetil);
                }




                float Chefao::getRapidez() const
                {
                    return rapidez;
                }

            }
        }
    }
}
