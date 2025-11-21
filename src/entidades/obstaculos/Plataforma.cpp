#include "entidades/obstaculos/Plataforma.h"

#include <cmath>

#include "fases/Fase.h"
#include "gerenciadores/GerenciadorColisao.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            int Plataforma::instancias = 0;
            int Plataforma::getInstancias() { return instancias; }
            void Plataforma::setInstancias(int r_instancias) { instancias = r_instancias; }




            Plataforma::Plataforma(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, bool r_ehChao, IDs id):
            Obstaculo(r_posicao, r_tamanho, r_danoso), ehChao(r_ehChao), invisivel(false)
            {
                if (!ehChao && pFase->getId() == IDs::primeira_fase)
                {
                    setTexture("../assets/obstaculos/plataformaFase1.png");
                    ++instancias;
                }
                else if (!ehChao && pFase->getId() == IDs::segunda_fase) {
                    setTexture("../assets/obstaculos/plataformaFase2.png");
                    ++instancias;
                }
                else if (ehChao && pFase->getId() == IDs::primeira_fase)
                    setTexture("../assets/obstaculos/chaofase1.png");
                else if (ehChao && pFase->getId() == IDs::segunda_fase)
                    setTexture("../assets/obstaculos/chaofase2.png");

                fixTexture();
            }
            Plataforma::Plataforma(dtos::ObstaculoDTO obsDTO, bool r_ehChao, bool r_invisivel):
            Obstaculo(obsDTO), ehChao(r_ehChao), invisivel(r_invisivel)
            {
                if (!ehChao && pFase->getId() == IDs::primeira_fase)
                {
                    setTexture("../assets/obstaculos/plataformaFase1.png");
                    ++instancias;
                }
                else if (!ehChao && pFase->getId() == IDs::segunda_fase) {
                    setTexture("../assets/obstaculos/plataformaFase2.png");
                    ++instancias;
                }
                else if (ehChao && pFase->getId() == IDs::primeira_fase)
                    setTexture("../assets/obstaculos/chaofase1.png");
                else if (ehChao && pFase->getId() == IDs::segunda_fase)
                    setTexture("../assets/obstaculos/chaofase2.png");

                fixTexture();
            }
            Plataforma::Plataforma(): invisivel(false) {}
            Plataforma::~Plataforma() = default;




            void Plataforma::executar()
            {
                if (!ehChao) {
                    atualizarInvisibilidade();
                }
            }




            void Plataforma::atualizarInvisibilidade()
            {
                if (!invisivel && cooldown < 0.1) {
                    invisivel = true;
                    cooldown = std::pow(1.1, 30);
                }
                else if (invisivel && cooldown < 0.1)
                {
                    invisivel = false;
                    cooldown = std::pow(1.1, 30);
                }
                cooldown /= 1.1;

                if (invisivel)
                    pSprite->setScale(0, 0);
                else
                    fixTexture();
            }





            void Plataforma::obstaculizar(Entidade *pEntidade)
            {
                if (pEntidade && !invisivel)
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




            void Plataforma::salvar()
            {
                Obstaculo::salvar();
                buffer << static_cast<int>(IDs::plataforma) << " " << ehChao << " " << invisivel;
            }

        }
    }
}
