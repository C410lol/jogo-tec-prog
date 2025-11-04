#include "entidades/obstaculos/Obstaculo.h"
#include "gerenciadores/GerenciadorColisao.h"




namespace jogo {
    namespace entidades {
        namespace obstaculos {

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




            void Obstaculo::colidir(Entidade *pEntidade)
            {
                std::cout << "Colidiu com obstaculo" << std::endl;
                obstaculizar(pEntidade);
            }
            void Obstaculo::obstaculizar(Entidade *pEntidade)
            {
                if (pEntidade)
                {
                    sf::Vector2f overlap = gerenciadores::GerenciadorColisao::calcOverlap(this, pEntidade);

                    if (overlap.x < overlap.y)
                    {
                        if (this->getPosicao().x < pEntidade->getPosicao().x)
                            pEntidade->mover(overlap.x, 0);
                        else
                            pEntidade->mover(-overlap.x, 0);
                    }
                    else
                    {
                        if (this->getPosicao().y < pEntidade->getPosicao().y)
                            pEntidade->mover(0, overlap.y);
                        else
                            pEntidade->mover(0, -overlap.y);
                    }
                }
            }



        }
    }
}
