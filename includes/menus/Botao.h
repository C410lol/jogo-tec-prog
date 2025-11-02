#ifndef JOGO_BOTAO_H
#define JOGO_BOTAO_H

#include <SFML/Graphics.hpp>
#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {
    namespace menus {

        class Botao
        {
        private:
            sf::Vector2f posicao;
            sf::Text texto;
            bool selecionado;

        public:
            Botao(sf::Vector2f r_posicao, std::string info);
            ~Botao();

            void executar();

            const sf::Text getTexto() const;
            const bool getSelecionado() const;

            void setSelecionado(bool r_selecionado);
        };

    }
}




#endif //JOGO_BOTAO_H