#ifndef JOGO_PONTUACAODTO_H
#define JOGO_PONTUACAODTO_H

#include <string>


namespace jogo {
    namespace dtos {
        class PontuacaoDTO {
        public:
            std::string username;
            int pontuacao;

            PontuacaoDTO(std::string &r_username, int r_pontuacao) : username(r_username), pontuacao(r_pontuacao)
            {
            }

            PontuacaoDTO() = default;

            ~PontuacaoDTO() = default;
        };
    }
}


#endif //JOGO_PONTUACAODTO_H