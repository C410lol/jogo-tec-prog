#include "entidades/obstaculos/Meleca.h"

#include "entidades/personagens/inimigos/Terrestre.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            int Meleca::instancias = 0;




            Meleca::Meleca(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_viscosidade):
            Obstaculo(r_posicao, r_tamanho, r_danoso), viscosidade(r_viscosidade)
            {
                ++instancias;
                retangulo.setFillColor(sf::Color::Green);
            }
            Meleca::Meleca(): viscosidade(0) {}
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
