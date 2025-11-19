//
// Created by mvmko on 18/11/2025.
//

#ifndef JOGO_BOTAO_H
#define JOGO_BOTAO_H

#include "Ente.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace jogo {
    namespace menus {
        class Botao : public Ente {
        private:
            sf::RectangleShape corpo;   // área do botão
            sf::Text texto;
            sf::Font fonte;
            bool selecionado;

        public:
            Botao(const std::string& str, const sf::Vector2f& pos, const sf::Vector2f& tam);
            ~Botao();

            void desenhar();
            void executar() override;


            // Verifica se o clique está dentro do botão
            bool contem(const sf::Vector2f& ponto) const;
        };
    }

}
#endif //JOGO_BOTAO_H