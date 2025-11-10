#include "entidades/obstaculos/Meleca.h"
#include "entidades/personagens/Jogador.h"




namespace jogo {
    namespace entidades {
        namespace obstaculos {

            Meleca::Meleca(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_viscosidade):
            Obstaculo(r_posicao, r_tamanho, r_danoso), viscosidade(r_viscosidade)
            {}
            Meleca::Meleca()
            {
                tamanho = sf::Vector2f(100.f, 5.f);
                posicao = sf::Vector2f(601.f, 495.f);

                retangulo.setSize(tamanho);
                retangulo.setPosition(posicao);
                retangulo.setFillColor(sf::Color::Green);
            }
            Meleca::~Meleca() = default;




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
