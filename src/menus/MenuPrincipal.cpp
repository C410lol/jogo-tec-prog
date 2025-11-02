#include "menus/MenuPrincipal.h"




namespace jogo {
    namespace menus {

        MenuPrincipal::MenuPrincipal()
        {
            MenuPrincipal::inicializaTexto();
        }
        MenuPrincipal::~MenuPrincipal() = default;


        void MenuPrincipal::executar()
        {
            if (!botoes.size())
                criarBotoes();
            Menu::executar();
        }


        void MenuPrincipal::inicializaTexto()
        {
            titulo = "Jogo";

            texto.setString(titulo);
            texto.setPosition(sf::Vector2f(500, 100));
        }



        void MenuPrincipal::criarBotoes()
        {
            int buttonPositionY = 300;

            botoes.push_back(new Botao(sf::Vector2f(500, buttonPositionY), "Novo Jogo"));
            buttonPositionY += 100;

            botoes.push_back(new Botao(sf::Vector2f(500, buttonPositionY), "Leaderboard"));
            buttonPositionY += 100;

            botoes.push_back(new Botao(sf::Vector2f(500, buttonPositionY), "Sair"));

            Menu::criarBotoes();
        }

    }
}
