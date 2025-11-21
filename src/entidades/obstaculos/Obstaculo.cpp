#include "entidades/obstaculos/Obstaculo.h"
#include "gerenciadores/GerenciadorColisao.h"
#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            Obstaculo::Obstaculo(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso):
            Entidade(r_posicao, r_tamanho), danoso(r_danoso), cooldown(0)
            {}
            Obstaculo::Obstaculo(dtos::ObstaculoDTO obsDTO):
            Entidade(obsDTO.entDTO), danoso(obsDTO.danoso), cooldown(obsDTO.cooldown)
            {}
            Obstaculo::Obstaculo(): danoso(false), cooldown(0) {}
            Obstaculo::~Obstaculo() = default;




            void Obstaculo::salvar()
            {
                Entidade::salvar();
                buffer << static_cast<int>(IDs::obstaculo) << " " << danoso << " " << cooldown << " ";
            }

        }
    }
}
