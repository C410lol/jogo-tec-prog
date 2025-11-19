#include "menus/MenuJogadores.h"

#include "gerenciadores/GerenciadorEstado.h"
#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {
    namespace menus {

        MenuJogadores::MenuJogadores(IDs r_fase): fase(r_fase)
        {
            float posX = sf::VideoMode::getDesktopMode().width / 2.75;
            botoes.push_back( new Botao("1 Jogador", {posX, 300.f}, {300.f, 50.f}));
            botoes.push_back( new Botao("2 Jogadores", {posX, 400.f}, {300.f, 50.f}));
            botoes.push_back(new Botao("Sair", {posX, 500.f}, {300.f, 50.f}));

            setTexture("../assets/Menu.png");
            pSprite->setTexture(*pTexture);

            sf::Vector2u windowSize = pGerenciadorGrafico->getJanela()->getSize();
            sf::Vector2u textureSize = pTexture->getSize();
            pSprite->setScale(
                static_cast<float>(windowSize.x) / textureSize.x,
                static_cast<float>(windowSize.y) / textureSize.y
            );
        }
        MenuJogadores::~MenuJogadores() = default;




        void MenuJogadores::executar()
        {
            desenhaMenu();
            atualizar();
        }




        void MenuJogadores::desenhaMenu()
        {
            pGerenciadorGrafico->desenhar(*pSprite);
            for (size_t i = 0; i < botoes.size(); ++i) {
                botoes[i]->desenhar();
            }
        }
        void MenuJogadores::atualizar()
        {
            sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*pGerenciadorGrafico->getJanela()));

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (botoes[0]->contem(mousePos)) {
                    pge->adicionarEstado(fase, 1);
                }
                else if (botoes[1]->contem(mousePos)) {
                    pge->adicionarEstado(fase, 2);
                }
                else if (botoes[2]->contem(mousePos)) {
                    pge->limparEstados();                     // esvazia toda a pilha
                    pge->adicionarEstado(IDs::menu_principal);
                }
            }
        }

    }
}
