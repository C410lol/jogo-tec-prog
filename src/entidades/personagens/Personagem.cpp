#include "./entidades/personagens/Personagem.h"

#include <iostream>

#include "fases/Fase.h"
#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace entidades {
        namespace personagens {

            fases::Fase *Personagem::pFase = nullptr;

            Personagem::Personagem(
                sf::Vector2f r_posicao, sf::Vector2f r_tamanho, const int r_vidas, const bool r_sofreGravidade
            ):
            Entidade(r_posicao, r_tamanho), vidas(r_vidas), sofreGravidade(r_sofreGravidade), noChao(false),
            olhandoDireita(true), knokback(false)
            {}
            Personagem::Personagem() = default;
            Personagem::~Personagem() = default;


            void Personagem::executar()
            {
                checarMorte();
                deslocar();
                cair();
                atualizaSprite();
                atualizaKnokback();
                atualizaVelocidadeX();
                atualizaPosicao();

                pSprite->setPosition(posicao);
                desenhar();
            }

            void Personagem::cair()
            {
                if (sofreGravidade)
                    velocidade.y += GRAVIDADE;
            }

            void Personagem::checarMorte()
            {
                if (vidas <= 0)
                    pFase->retirarPersonagem(this);
            }





            void Personagem::atualizaSprite()
            {
                sf::IntRect rect = pSprite->getTextureRect();
                if (olhandoDireita)
                {
                    if (rect.width < 0)
                    {
                        rect.left += rect.width;
                        rect.width *= -1;
                    }
                }
                else
                {
                    if (rect.width > 0)
                    {
                        rect.left += rect.width;
                        rect.width *= -1;
                    }
                }
                pSprite->setTextureRect(rect);
            }
            void Personagem::atualizaVelocidadeX()
            {
                if (noChao)
                    setVelocidade(sf::Vector2f(0, getVelocidade().y));
            }
            void Personagem::atualizaPosicao()
            {
                posicao.x += velocidade.x / 30.f;
                posicao.y += velocidade.y / 30.f;
            }




            sf::Vector2f Personagem::getVelocidade() const {
                return velocidade;
            }
            void Personagem::setVelocidade(const sf::Vector2f r_velocidade) {
                velocidade = r_velocidade;
            }




            bool Personagem::getNoChao() const {
                return noChao;
            }
            void Personagem::setNoChao(const bool r_noChao) {
                noChao = r_noChao;
            }




            void Personagem::atualizaKnokback()
            {
                if (getNoChao())
                    setKnokback(false);
            }
            bool Personagem::getKnokback() const
            {
                return knokback;
            }
            void Personagem::setKnokback(bool r_knokback)
            {
                knokback = r_knokback;
            }




            bool Personagem::getOlhandoDireita() const
            {
                return olhandoDireita;
            }




            void Personagem::tomarDano(int dano)
            {
                vidas -= dano;
            }





            void Personagem::setFase(fases::Fase *r_pFase)
            {
                pFase = r_pFase;
            }

        }
    }
}
