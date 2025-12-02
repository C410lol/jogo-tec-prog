#ifndef JOGO_OBSTACULODTO_H
#define JOGO_OBSTACULODTO_H

#include "dtos/EntidadeDTO.h"


namespace jogo {
    namespace dtos {
        class ObstaculoDTO {
        public:
            EntidadeDTO entDTO;
            bool danoso;
            double cooldown;

            ObstaculoDTO(EntidadeDTO r_entDTO, bool r_danoso, double r_cooldown) : entDTO(r_entDTO), danoso(r_danoso),
                cooldown(r_cooldown)
            {
            }

            ~ObstaculoDTO() = default;
        };
    }
}


#endif //JOGO_OBSTACULODTO_H