#include "entidades/obstaculos/Plataforma.h"

#include "gerenciadores/GerenciadorColisao.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            Plataforma::Plataforma(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, bool r_movel):
            Obstaculo(r_posicao, r_tamanho, r_danoso), movel(r_movel)
            {}
            Plataforma::Plataforma(): movel(false) {
                tamanho = sf::Vector2f(1280.f, 50.f);
                posicao = sf::Vector2f(0.f, 500.f);

                retangulo.setSize(tamanho);
                retangulo.setPosition(posicao);
                retangulo.setFillColor(sf::Color::White);
            }
            Plataforma::~Plataforma() = default;




            void Plataforma::obstaculizar(Entidade *pEntidade) {
                if (pEntidade)
                {
                    sf::Vector2f overlap = gerenciadores::GerenciadorColisao::calcOverlap(this, pEntidade);
                    personagens::Personagem* pPersonagem = dynamic_cast<personagens::Personagem*>(pEntidade);

                    if (overlap.x < overlap.y)
                    {
                        pPersonagem->setVelocidade(sf::Vector2f(0, pPersonagem->getVelocidade().y));
                        if (this->getPosicao().x < pEntidade->getPosicao().x)
                            pEntidade->mover(overlap.x, 0);
                        else
                            pEntidade->mover(-overlap.x, 0);
                    }
                    else
                    {
                        pPersonagem->setVelocidade(sf::Vector2f(pPersonagem->getVelocidade().x, 0));
                        if (this->getPosicao().y < pEntidade->getPosicao().y)
                            pEntidade->mover(0, overlap.y);
                        else {
                            pPersonagem->setNoChao(true);
                            pEntidade->mover(0, -overlap.y);
                        }
                    }
                }
            }


        }
    }
}
