#include "./entidades/personagens/Personagem.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            Personagem::Personagem(const int r_vidas, const bool r_sofreGravidade):
            vidas(r_vidas), sofreGravidade(r_sofreGravidade), noChao(false), olhandoDireita(true)
            {}
            Personagem::~Personagem() = default;

            void Personagem::executar()
            {
                deslocar();
                cair();
                setNoChao(false);

                posicao.x += velocidade.x / 30.f;
                posicao.y += velocidade.y / 30.f;
                retangulo.setPosition(posicao);
            }

            void Personagem::cair()
            {
                if (sofreGravidade)
                    velocidade.y += GRAVIDADE;
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

        }
    }
}
