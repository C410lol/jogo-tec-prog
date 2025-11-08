#include "./entidades/personagens/Personagem.h"

#include <iostream>

#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace entidades {
        namespace personagens {

            Personagem::Personagem(const int r_vidas, const bool r_sofreGravidade):
            vidas(r_vidas), sofreGravidade(r_sofreGravidade), noChao(false), olhandoDireita(true), knokback(false)
            {}
            Personagem::~Personagem() = default;

            void Personagem::executar()
            {
                deslocar();
                cair();
                atualizaKnokback();
                atualizaVelocidadeX();
                atualizaPosicao();
                pGerenciadorGrafico->desenhar(this);

                retangulo.setPosition(posicao);
            }

            void Personagem::cair()
            {
                if (sofreGravidade)
                    velocidade.y += GRAVIDADE;
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






            void Personagem::operator--()
            {
                --vidas;
            }


        }
    }
}
