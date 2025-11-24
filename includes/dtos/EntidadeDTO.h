#ifndef JOGO_ENTIDADEDTO_H
#define JOGO_ENTIDADEDTO_H

#include <SFML/System.hpp>




namespace jogo {
    namespace dtos {

        class EntidadeDTO
        {
        public:
            int idNumber;
            bool ativo;
            sf::Vector2f posicao;
            sf::Vector2f tamanho;

            EntidadeDTO(int r_idNumber, bool r_ativo, sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
            idNumber(r_idNumber), ativo(r_ativo), posicao(r_posicao), tamanho(r_tamanho) {}
            ~EntidadeDTO() = default;
        };

    }
}




#endif //JOGO_ENTIDADEDTO_H