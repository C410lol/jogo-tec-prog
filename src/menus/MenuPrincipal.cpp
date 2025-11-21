#include "menus/MenuPrincipal.h"

#include <fstream>
#include <iostream>

#include "estados/Estado.h"
#include "gerenciadores/GerenciadorEstado.h"
#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {
    namespace menus {

        MenuPrincipal::MenuPrincipal() {
            float posX = sf::VideoMode::getDesktopMode().width / 2.75;
            botoes.push_back( new Botao("JOGO", {posX, 100.f}, {300.f, 100.f}));
            botoes.push_back( new Botao("Continuar", {posX + 50, 300.f}, {200.f, 50.f}));
            botoes.push_back( new Botao("Fase 1", {posX + 50, 400.f}, {200.f, 50.f}));
            botoes.push_back( new Botao("Fase 2", {posX + 50, 500.f}, {200.f, 50.f}));
            botoes.push_back( new Botao("Sair", {posX + 50, 600.f}, {200.f, 50.f}));

            setTexture("../assets/Menu.png");
            pSprite->setTexture(*pTexture);

            sf::Vector2u windowSize = pGerenciadorGrafico->getJanela()->getSize();
            sf::Vector2u textureSize = pTexture->getSize();
            pSprite->setScale(
                static_cast<float>(windowSize.x) / textureSize.x,
                static_cast<float>(windowSize.y) / textureSize.y
            );
        }

        MenuPrincipal::~MenuPrincipal() {
            // nada especial por enquanto
        }
        void MenuPrincipal::executar() {
            desenhaMenu();
            atualizar();
        }

        void MenuPrincipal::atualizar() {
            sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*pGerenciadorGrafico->getJanela()));

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (botoes[1]->contem(mousePos))
                {
                    pge->adicionarEstado(carregarFaseContinuar(), 0, static_cast<IDs>(NULL), true);
                }
                if (botoes[2]->contem(mousePos))
                {
                    pge->adicionarEstado(IDs::menu_jogadores, 0, IDs::primeira_fase);
                }
                else if (botoes[3]->contem(mousePos))
                {
                    pge->adicionarEstado(IDs::menu_jogadores, 0, IDs::segunda_fase);
                }
                else if (botoes[4]->contem(mousePos))
                {
                    pGerenciadorGrafico->fecharJanela(); // sair
                }
            }
        }

        void MenuPrincipal::desenhaMenu() {
            pGerenciadorGrafico->desenhar(*pSprite);
            for (size_t i = 0; i < botoes.size(); ++i) {
                botoes[i]->desenhar();
            }
        }




        IDs MenuPrincipal::carregarFaseContinuar()
        {
            std::ifstream file("../salvamentos/salvamento.txt");

            char fase;
            file.get(fase);
            file.close();

            if (!fase || fase == '1')
                return IDs::primeira_fase;

            return IDs::segunda_fase;
        }

    }
}
