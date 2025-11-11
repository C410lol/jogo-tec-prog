#include "entidades/personagens/Jogador.h"

#include <cmath>

#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace entidades {
        namespace personagens {

            #define DESLOCAMENTO_JOGADOR_PADRAO 7.5




            Jogador::Jogador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
            Personagem(r_posicao, r_tamanho, 10, true), deslocamentoX(DESLOCAMENTO_JOGADOR_PADRAO), pontos(0)
            {
                retangulo.setFillColor(sf::Color::Blue);
            }
            Jogador::Jogador(): deslocamentoX(DESLOCAMENTO_JOGADOR_PADRAO), pontos(0) {}
            Jogador::~Jogador() = default;




            void Jogador::checarEstaMorto() const {
                if (vidas <= 0)
                    pGerenciadorGrafico->fecharJanela();
            }



            void Jogador::executar()
            {
                Personagem::executar();
                atualizarNaMeleca();
                checarEstaMorto();
            }


            void Jogador::colidir(Entidade *pEntidade)
            {

            }



            void Jogador::deslocar()
            {
                if (getKnokback())
                    return;
                bool movimento=false;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        olhandoDireita = false;
                        movimento=true;

                        setVelocidade(sf::Vector2f(-deslocamentoX*30, getVelocidade().y));
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        olhandoDireita = true;
                        movimento=true;
                        setVelocidade(sf::Vector2f(deslocamentoX*30, getVelocidade().y));
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

                if(!movimento)
                {
                    if (velocidade.x>0)
                    {
                        velocidade.x-=deslocamentoX*10;
                        if (velocidade.x<0)
                            velocidade.x=0;
                    }
                    if (velocidade.x<0)
                    {
                        velocidade.x+=deslocamentoX*10;
                        if (velocidade.x>0)
                            velocidade.x=0;
                    }
                }
                //std::cout<<velocidade.x<<std::endl;
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
                --(*pInimigo);
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

