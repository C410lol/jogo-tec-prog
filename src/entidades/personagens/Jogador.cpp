#include "entidades/personagens/Jogador.h"

#include <iostream>

#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace entidades {
        namespace personagens {

            Jogador::Jogador(): Personagem(10, true), pontos(0)
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
                checarEstaMorto();
                Personagem::executar();
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
                    mover(-7.5f, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    mover(7.5f, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    pular();
                }
            }




            void Jogador::pular() {
                if (noChao) {
                    noChao = false;
                    setVelocidade(sf::Vector2f(getVelocidade().x, -550));
                }
            }


        }
    }
}

