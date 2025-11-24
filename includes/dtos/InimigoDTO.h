#ifndef JOGO_INIMIGODTO_H
#define JOGO_INIMIGODTO_H

#include "dtos/PersonagemDTO.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            class Jogador;
        }
    }

    namespace dtos {

        class InimigoDTO
        {
        public:
            PersonagemDTO perDTO;
            entidades::personagens::Jogador *pJogadorAlvo;
            int nivelMaldade;
            int deslocamento;

            InimigoDTO(
                PersonagemDTO r_perDTO, entidades::personagens::Jogador *r_pJogadorAlvo,
                int r_nivelMaldade, int r_deslocamento
            ):
            perDTO(r_perDTO), pJogadorAlvo(r_pJogadorAlvo), nivelMaldade(r_nivelMaldade), deslocamento(r_deslocamento) {}
            ~InimigoDTO() = default;
        };

    }
}




#endif //JOGO_INIMIGODTO_H