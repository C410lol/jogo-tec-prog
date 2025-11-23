#include "menus/MenuPontuacao.h"

#include <fstream>
#include <iostream>

#include "gerenciadores/GerenciadorEstado.h"
#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {
    namespace menus {

        MenuPontuacao::MenuPontuacao()
        {
            float posX = sf::VideoMode::getDesktopMode().width / 2.75;
            botoes.push_back( new Botao("Username:", {posX, 300.f}, {300.f, 50.f}));
            pCaixaTexto = new CaixaTexto(sf::Vector2f(posX, 400.f), sf::Vector2f(300.f, 50.f));
            botoes.push_back( new Botao("Confirmar", {posX, 500.f}, {300.f, 50.f}));

            setTexture("../assets/Menu.png");
            pSprite->setTexture(*pTexture);

            sf::Vector2u windowSize = pGerenciadorGrafico->getJanela()->getSize();
            sf::Vector2u textureSize = pTexture->getSize();
            pSprite->setScale(
                static_cast<float>(windowSize.x) / textureSize.x,
                static_cast<float>(windowSize.y) / textureSize.y
            );
        };
        MenuPontuacao::~MenuPontuacao()
        {
            delete pCaixaTexto;
        };




        void MenuPontuacao::executar()
        {
            desenhaMenu();
            atualizar();
            pCaixaTexto->setTexto(username);
        }
        void MenuPontuacao::desenhaMenu()
        {
            pGerenciadorGrafico->desenhar(*pSprite);
            pCaixaTexto->desenhar();
            for (size_t i = 0; i < botoes.size(); ++i)
            {
                botoes[i]->desenhar();
            }
        }
        void MenuPontuacao::atualizar()
        {
            static sf::Clock keyClock;  // controla repetição
            const float keyDelay = 0.15f;

            //   MAPEAMENTO DAS LETRAS A–Z
            if (keyClock.getElapsedTime().asSeconds() > keyDelay)
            {
                if (username.size() < 10)
                {
                    for (char c = 'A'; c <= 'Z'; c++)
                    {
                        sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(sf::Keyboard::A + (c - 'A'));

                        if (sf::Keyboard::isKeyPressed(key)) {
                            username += c;
                            keyClock.restart();
                            break;
                        }
                    }
                    // espaço
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    {
                        username += ' ';
                        keyClock.restart();
                    }
                }
                // backspace
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                {
                    if (!username.empty())
                        username.pop_back();
                    keyClock.restart();
                }
            }

            sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*pGerenciadorGrafico->getJanela()));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (botoes[1]->contem(mousePos))
                {
                    if (username.empty())
                        return;

                    salvarPontuacao();

                    pge->limparEstados();                     // esvazia toda a pilha
                    pge->adicionarEstado(IDs::menu_principal);
                }
            }
        }




        void MenuPontuacao::salvarPontuacao()
        {
            //  Não sobreescreve o arquivo
            std::ofstream file("../salvamentos/pontuacoes.txt", std::ios::app);

            int pontuacao = -1;
            //  Resgatar pontuação do(s) jogador(es)

            file << username << " " << pontuacao << std::endl;
        }

    }
}
