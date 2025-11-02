#include "entidades/obstaculos/Obstaculo.h"




namespace jogo {
    namespace entidades {
        namespace obstacles {

            Obstaculo::Obstaculo()
            {
                tamanho = sf::Vector2f(400.0f, 50.0f);
                posicao = sf::Vector2f(500.0f, 550.0f);

                retangulo.setSize(tamanho);
                retangulo.setPosition(posicao);
                retangulo.setFillColor(sf::Color::Red);
            }
            Obstaculo::~Obstaculo() = default;


            void Obstaculo::executar() {}


            void Obstaculo::obstaculizar(Entidade &entidade)
            {
                float disX =
                    (entidade.getPosicao().x + (getTamanho().x / 2.f)) -
                    (getPosicao().x + (getTamanho().x / 2.f));
                float disY =
                    (entidade.getPosicao().y + (getTamanho().y / 2.f)) -
                    (getPosicao().y + (getTamanho().y / 2.f));

                float disAX = std::abs(disX);
                float disAY = std::abs(disY);

                float somX = (entidade.getTamanho().x / 2.f + getTamanho().x / 2);
                float somY = (entidade.getTamanho().y / 2.f + getTamanho().y / 2.f);
                if (disAX < somX && disAY < somY)
                {
                    if (somX - disAX > somY - disAY)
                    {
                        if (disX < 0)
                        {
                            entidade.setPosicao(
                                sf::Vector2f(entidade.getPosicao().x - (somX - disAX), entidade.getPosicao().y)
                            );
                        }
                        else
                        {
                            entidade.setPosicao(
                                sf::Vector2f(entidade.getPosicao().x + (somX - disAX), entidade.getPosicao().y)
                            );
                        }
                    }
                    else
                    {
                        if (disY < 0)
                        {
                            entidade.setPosicao(
                                sf::Vector2f(entidade.getPosicao().x, entidade.getPosicao().y - (somY - disAY))
                            );
                        }
                        else
                        {
                            entidade.setPosicao(
                                sf::Vector2f(entidade.getPosicao().x, entidade.getPosicao().y + (somY - disAY))
                            );
                        }
                    }
                }
            }


        }
    }
}
