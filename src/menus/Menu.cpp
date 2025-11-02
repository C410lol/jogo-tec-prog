#include "menus/Menu.h"

#include <iostream>


namespace jogo {
    namespace menus {

        gerenciadores::GerenciadorGrafico *Menu::pGerenciadorGrafico = nullptr;


        Menu::Menu()
        {
            Menu::inicializaTexto();
        }
        Menu::~Menu() = default;


        void Menu::setGerenciadorGrafico(gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico)
        {
            pGerenciadorGrafico = r_pGerenciadorGrafico;
        }


        void Menu::criarBotoes()
        {
            botoes[0]->setSelecionado(true);
        }


        void Menu::inicializaTexto()
        {
            texto.setFillColor(sf::Color::White);
            texto.setFont(*gerenciadores::GerenciadorGrafico::fonte);
        }

        void Menu::desenhaTexto() const
        {
            if (pGerenciadorGrafico)
                pGerenciadorGrafico->desenhar(getTexto());
        }

        void Menu::executar()
        {
            desenhaTexto();
            desenhaBotoes();
        }

        sf::Text Menu::getTexto() const
        {
            return texto;
        }


        void Menu::navegar()
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {

            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {

            }
        }



        void Menu::desenhaBotoes()
        {
            if (pGerenciadorGrafico)
            {
                int i;
                for (i = 0; i < botoes.size(); ++i)
                {
                    botoes[i]->executar();
                    pGerenciadorGrafico->desenhar(botoes[i]->getTexto());
                }
            }
        }

    }
}
