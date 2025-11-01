#ifndef JOGO_GRAPHICMANAGER_H
#define JOGO_GRAPHICMANAGER_H

#include <SFML/Graphics.hpp>
#include "entidades/Entidade.h"




namespace jogo {
    namespace gerenciadores {

        class GerenciadorGrafico
        {
        private:
            sf::RenderWindow* pJanela;
        private:
            void criarJanela();

        public:
            GerenciadorGrafico();
            ~GerenciadorGrafico();

            bool isJanelaAberta() const;

            void limpar() const;
            void desenhar(const entidades::Entidade &entidade) const;
            void mostrar() const;

            sf::RenderWindow* getJanela() const;
        };

    }
}




#endif //JOGO_GRAPHICMANAGER_H