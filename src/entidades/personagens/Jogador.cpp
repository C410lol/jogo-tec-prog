#include "entidades/personagens/Jogador.h"

#include <cmath>
#include <iostream>

#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace entidades {
        namespace personagens {

            #define DESLOCAMENTO_JOGADOR_PADRAO 7.5




            int Jogador::instancias = 0;
            bool Jogador::primeiroExiste = false;




            Jogador::Jogador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
            Personagem(r_posicao, r_tamanho, 10, true), ehPrimeiro(false),
            deslocamentoX(DESLOCAMENTO_JOGADOR_PADRAO), pontos(0)
            {
                ++instancias;
                if (!primeiroExiste)
                {
                    ehPrimeiro = true;
                    primeiroExiste = true;

                    setTexture("../assets/personagens/jogador1.png");
                }
                else
                    setTexture("../assets/personagens/jogador2.png");

                fixTexture();
            }
            Jogador::Jogador(): deslocamentoX(DESLOCAMENTO_JOGADOR_PADRAO), pontos(0) {}
            Jogador::~Jogador() {
                --instancias;
            };




            void Jogador::executar()
            {
                Personagem::executar();
                atualizarNaMeleca();
            }




            void Jogador::deslocar()
            {
                if (getKnokback())
                    return;

                if (ehPrimeiro)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        olhandoDireita = false;
                        mover(-deslocamentoX, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        olhandoDireita = true;
                        mover(deslocamentoX, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        pular();
                    }

                    //  Ataque do Jogador
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !cooldown)
                    {
                        cooldown = std::pow(2, 15);
                        atacando = true;
                    }
                    else
                        atacando = false;
                    cooldown /= 2;
                }
                else
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    {
                        olhandoDireita = false;
                        mover(-deslocamentoX, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        olhandoDireita = true;
                        mover(deslocamentoX, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        pular();
                    }

                    //  Ataque do Jogador
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !cooldown)
                    {
                        cooldown = std::pow(2, 15);
                        atacando = true;
                    }
                    else
                        atacando = false;
                    cooldown /= 2;
                }
            }




            bool Jogador::getAtacando() const
            {
                return atacando;
            }





            void Jogador::setNaMeleca(bool r_estaNaMeleca)
            {
                naMeleca = r_estaNaMeleca;
            }
            void Jogador::atualizarNaMeleca()
            {
                if (naMeleca)
                    deslocamentoX = 3.f;
                else
                    deslocamentoX = DESLOCAMENTO_JOGADOR_PADRAO;
                naMeleca = false;
            }





            void Jogador::atacar(inimigos::Inimigo *pInimigo)
            {
                if (!pInimigo)
                    return;

                sf::Vector2f vetorVelocidade;
                vetorVelocidade.y = -400;
                if (this->getPosicao().x < pInimigo->getPosicao().x)
                    vetorVelocidade.x = 300;
                else
                    vetorVelocidade.x = -300;

                pInimigo->setNoChao(false);
                pInimigo->setKnokback(true);
                pInimigo->setVelocidade(vetorVelocidade);
                pInimigo->tomarDano(1);
            }

            void Jogador::pular() {
                if (noChao && !naMeleca) {
                    noChao = false;
                    setVelocidade(sf::Vector2f(getVelocidade().x, -350));
                }
            }


        }
    }
}

