#include "entidades/obstaculos/Meleca.h"
#include "entidades/personagens/Jogador.h"




namespace jogo {
    namespace entidades {
        namespace obstaculos {

            int Meleca::instancias = 0;




            Meleca::Meleca(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_viscosidade):
            Obstaculo(r_posicao, r_tamanho, r_danoso), viscosidade(r_viscosidade),
            tamMaximo(r_tamanho.x * 5), tamMinimo(r_tamanho.x), aumentando(true)
            {
                ++instancias;
                retangulo.setFillColor(sf::Color::Green);
            }
            Meleca::Meleca(): viscosidade(0) {}
            Meleca::~Meleca() = default;




            void Meleca::executar()
            {
                if (aumentando)
                {
                    aumentar(getTamanho().x / 50, 0);
                    mover(getTamanho().x / -100, 0);
                    if (getTamanho().x >= tamMaximo)
                        aumentando = false;
                }
                else
                {
                    aumentar(getTamanho().x / -50, 0);
                    mover(getTamanho().x / 100, 0);
                    if (getTamanho().x <= tamMinimo)
                        aumentando = true;
                }

                retangulo.setPosition(getPosicao());
            }




            void Meleca::obstaculizar(Entidade *pEntidade)
            {
                if (!pEntidade)
                    return;

                personagens::Jogador* pJogador = dynamic_cast<personagens::Jogador*>(pEntidade);
                if (!pJogador)
                    return;

                pJogador->setNaMeleca(true);
            }


        }
    }
}
