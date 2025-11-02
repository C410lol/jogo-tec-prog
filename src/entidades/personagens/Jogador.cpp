#include "entidades/personagens/Jogador.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            Jogador::Jogador(): pontos(0)
            {
                tamanho = sf::Vector2f(50.0f, 50.0f);
                posicao = sf::Vector2f(200.0f, 200.0f);

                retangulo.setSize(tamanho);
                retangulo.setPosition(posicao);
                retangulo.setFillColor(sf::Color::Blue);
            };
            Jogador::~Jogador() = default;


            void Jogador::executar()
            {
                deslocar();

                //Character::fall();
                Personagem::executar();
            }


            void Jogador::deslocar()
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    mover(-0.5f, 0.f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    mover(0.5f, 0.f);

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    mover(0.f, -0.5f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    mover(0.f, 0.5f);
                }
            }


        }
    }
}

