#ifndef JOGO_MENU_H
#define JOGO_MENU_H

#include "gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics.hpp>
#include "menus/Botao.h"




namespace jogo {
    namespace menus {

        class Menu
        {
        protected:
            static gerenciadores::GerenciadorGrafico *pGerenciadorGrafico;
            std::string titulo;
            sf::Text texto;
            std::vector<Botao*> botoes;

        public:
            Menu();
            virtual ~Menu();

            static void setGerenciadorGrafico(gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico);

            virtual void executar();

            sf::Text getTexto() const;

            virtual void inicializaTexto();
            void desenhaTexto() const;

            void desenhaBotoes();
            virtual void criarBotoes();

            void navegar();
        };

    }
}




#endif //JOGO_MENU_H