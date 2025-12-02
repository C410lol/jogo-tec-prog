#ifndef JOGO_GRAPHICMANAGER_H
#define JOGO_GRAPHICMANAGER_H

#include <SFML/Graphics.hpp>
#include "entidades/Entidade.h"


namespace jogo {
    namespace gerenciadores {
#define FRAMERATE_LIMIT 30

        class GerenciadorGrafico {
        private:
            sf::RenderWindow *pJanela;

        private:
            void criarJanela();

        public:
            GerenciadorGrafico();

            ~GerenciadorGrafico();

            bool isJanelaAberta() const;

            void limpar() const;

            void desenhar(Ente *pEnte) const;

            void desenhar(sf::Sprite pSrite);

            void desenhar(sf::Text &fonte);

            void desenhar(sf::RectangleShape pshape);

            void mostrar() const;

            void fecharJanela() const;

            sf::Vector2u getWindowSize() const;

            sf::RenderWindow *getJanela() const;
        };
    }
}


#endif //JOGO_GRAPHICMANAGER_H