#ifndef JOGO_PERSONAGEMDTO_H
#define JOGO_PERSONAGEMDTO_H

#include "dtos/EntidadeDTO.h"
#include <SFML/System.hpp>


namespace jogo {
    namespace dtos {
        class PersonagemDTO {
        public:
            EntidadeDTO entDTO;
            int vidas;
            sf::Vector2f velocidade;
            bool sofreGravidade;
            bool noChao;
            bool olhandoDireita;
            bool knokback;

            PersonagemDTO(
                EntidadeDTO r_entDTO, int r_vidas, sf::Vector2f r_velocidade, bool r_sofreGravidade,
                bool r_noChao, bool r_olhandoDireita, bool r_knokback
            ) : entDTO(r_entDTO), vidas(r_vidas), velocidade(r_velocidade), sofreGravidade(r_sofreGravidade),
                noChao(r_noChao), olhandoDireita(r_olhandoDireita), knokback(r_knokback)
            {
            }

            ~PersonagemDTO() = default;
        };
    }
}


#endif //JOGO_PERSONAGEMDTO_H