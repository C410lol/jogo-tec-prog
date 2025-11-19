#include "menus/MenuPrincipal.h"
#include <iostream>

#include "estados/Estado.h"
#include "gerenciadores/GerenciadorEstado.h"
#include "gerenciadores/GerenciadorGrafico.h"

namespace jogo {
    namespace menus {

        MenuPrincipal::MenuPrincipal() {
            botoes.push_back( new Botao("Fase 1", {500.f, 300.f}, {200.f, 50.f}));
            botoes.push_back( new Botao("Fase 2", {500.f, 400.f}, {200.f, 50.f}));
            botoes.push_back( new Botao("Sair",   {500.f, 500.f}, {200.f, 50.f}));
            botoes.push_back( new Botao("JOGO++",   {450.f, 100.f}, {300.f, 100.f}));

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
                if (botoes[0]->contem(mousePos)) {
                    pge->adicionarEstado(IDs::primeira_fase);
                }
                else if (botoes[1]->contem(mousePos)) {
                    pge->adicionarEstado(IDs::segunda_fase);
                }
                else if (botoes[2]->contem(mousePos)) {
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
        }

    }
