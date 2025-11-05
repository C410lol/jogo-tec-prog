#include "entidades/obstaculos/Obstaculo.h"
#include "gerenciadores/GerenciadorColisao.h"




namespace jogo {
    namespace entidades {
        namespace obstaculos {

            Obstaculo::Obstaculo(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso):
            danoso(r_danoso)
            {}
            Obstaculo::Obstaculo(): danoso(false) {}
            Obstaculo::~Obstaculo() = default;




            void Obstaculo::executar() {}




            void Obstaculo::colidir(Entidade *pEntidade)
            {
                obstaculizar(pEntidade);
            }



        }
    }
}
