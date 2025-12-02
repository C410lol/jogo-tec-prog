#ifndef JOGO_CAIXATEXTO_H
#define JOGO_CAIXATEXTO_H

#include "Ente.h"


namespace jogo {
    namespace menus {
        class CaixaTexto : public Ente {
        private:
            sf::RectangleShape corpo; // área do botão
            sf::Text texto;
            sf::Font fonte;

        public:
            CaixaTexto(const sf::Vector2f &pos, const sf::Vector2f &tam, bool centralizado = false);

            ~CaixaTexto();

            void desenhar();

            void executar() override;

            void setTexto(std::string &username);
        };
    }
}


#endif //JOGO_CAIXATEXTO_H