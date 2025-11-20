


#include "menus/MenuPausa.h"

#include <iostream>

#include "gerenciadores/GerenciadorEstado.h"
#include "gerenciadores/GerenciadorGrafico.h"

namespace jogo {
    namespace menus {
        MenuPausa::MenuPausa(fases::Fase* r_fase) : fundoPainel(), fase(r_fase){
            float posX = sf::VideoMode::getDesktopMode().width / 2.75;
            botoes.push_back(new Botao("Sair", {posX, 175.f}, {200.f, 50.f}));
            botoes.push_back(new Botao("Continuar",{posX, 300.f}, {200.f, 50.f}));

            fundoPainel.setSize(sf::Vector2f(400.f, 300.f));   // largura e altura
            fundoPainel.setFillColor(sf::Color(0, 0, 0, 150)); // preto semi-transparente
            fundoPainel.setPosition(400.f, 200.f);
        }
        void MenuPausa::atualizar() {
            sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*pGerenciadorGrafico->getJanela()));

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (botoes[0]->contem(mousePos)) {
                    fase->salvarFase();
                    pge->limparEstados();                     // esvazia toda a pilha
                    pge->adicionarEstado(IDs::menu_principal);
                }
                if (botoes[1]->contem(mousePos)) {
                    pge->removerEstado();
                    pge->getEstadoAtual()->setvoltaMenu(false);
                }
            }
        }
        void MenuPausa::executar() {
            if (fase != nullptr) {
                fase->desenhar();
            }
            desenhaMenu();
            atualizar();
        }
        void MenuPausa::desenhaMenu() {
            pGerenciadorGrafico->desenhar(fundoPainel);
            for (size_t i = 0; i < botoes.size(); ++i) {
                botoes[i]->desenhar();
            }
        }


        }

    }
