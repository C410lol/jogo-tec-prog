#include "entidades/obstaculos/Obstaculo.h"
#include "gerenciadores/GerenciadorColisao.h"
#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            Obstaculo::Obstaculo(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso):
            Entidade(r_posicao, r_tamanho), danoso(r_danoso)
            {}
            Obstaculo::Obstaculo(): danoso(false) {}
            Obstaculo::~Obstaculo() = default;




            void Obstaculo::executar() {
                pGerenciadorGrafico->desenhar(this);
            }




            void Obstaculo::colidir(Entidade *pEntidade)
            {
                obstaculizar(pEntidade);
            }

        }
    }
}
