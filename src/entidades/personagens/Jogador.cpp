#include "entidades/personagens/Jogador.h"

#include <cmath>

#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace entidades {
        namespace personagens {

            #define DESLOCAMENTO_JOGADOR_PADRAO 7.5

            Jogador::Jogador():
            Personagem(10, true), deslocamentoX(DESLOCAMENTO_JOGADOR_PADRAO), cooldown(0),
            pontos(0)
            {
                tamanho = sf::Vector2f(48.0f, 48.0f);
                posicao = sf::Vector2f(200.0f, 200.0f);

                retangulo.setSize(tamanho);
                retangulo.setPosition(posicao);
                retangulo.setFillColor(sf::Color::Blue);
            };
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
                    setVelocidade(sf::Vector2f(getVelocidade().x, -550));
                }
            }


        }
    }
}

