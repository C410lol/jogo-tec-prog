#include "entidades/personagens/Jogador.h"

#include <iostream>

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

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    mover(-deslocamentoX, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    mover(deslocamentoX, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    pular();
                }
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






            void Jogador::pular() {
                if (noChao && !naMeleca) {
                    noChao = false;
                    setVelocidade(sf::Vector2f(getVelocidade().x, -350));
                }
            }


        }
    }
}

