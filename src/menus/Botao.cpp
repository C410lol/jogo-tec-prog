#include "menus/Botao.h"

#include <iostream>

#include "gerenciadores/GerenciadorGrafico.h"

namespace jogo {
    namespace menus {
        Botao::Botao(const std::string &str, const sf::Vector2f &pos, const sf::Vector2f &tam)
            : Ente(), selecionado(false)
        {
            corpo.setSize(tam);
            corpo.setPosition(pos);
            corpo.setFillColor(sf::Color::Transparent);

            setTexture("../assets/Botao.png");
            pSprite->setTexture(*pTexture);
            pSprite->setPosition(pos);
            pSprite->setScale(
                tam.x / pTexture->getSize().x,
                tam.y / pTexture->getSize().y
            );

            if (!fonte.loadFromFile("../assets/fonts/Pixlpowr.ttf"))
                std::cout << "Fonte.loadFromFile() failed" << std::endl;
            texto.setFont(fonte);
            texto.setString(str);
            texto.setCharacterSize(24);
            texto.setFillColor(sf::Color::White);

            // centralizar texto no botão
            sf::FloatRect bounds = texto.getLocalBounds();
            texto.setOrigin(bounds.width / 2, bounds.height / 2);
            texto.setPosition(pos.x + tam.x / 2, pos.y + tam.y / 2);
        }

        Botao::~Botao()
        {
        }

        void Botao::desenhar()
        {
            pGerenciadorGrafico->desenhar(*pSprite);
            pGerenciadorGrafico->desenhar(texto);
        }

        bool Botao::contem(const sf::Vector2f &mousepos) const
        {
            return corpo.getGlobalBounds().contains(mousepos);
        }

        void Botao::executar()
        {
            desenhar();
        }
    }
}