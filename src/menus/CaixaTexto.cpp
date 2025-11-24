#include "menus/CaixaTexto.h"

#include <iostream>

#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {
    namespace menus {

        CaixaTexto::CaixaTexto(const sf::Vector2f &pos, const sf::Vector2f &tam, bool centralizado)
        {
            corpo.setSize(tam);
            corpo.setPosition(pos);
            corpo.setFillColor(sf::Color::Transparent);

            setTexture("../assets/CaixaTexto.png");
            pSprite->setTexture(*pTexture);
            pSprite->setPosition(pos);
            pSprite->setScale(
                tam.x / pTexture->getSize().x,
                tam.y / pTexture->getSize().y
            );

            if (!fonte.loadFromFile("../assets/fonts/Pixlpowr.ttf"))
                std::cout<< "Fonte.loadFromFile() failed" << std::endl;

            texto.setFont(fonte);
            texto.setCharacterSize(24);
            texto.setFillColor(sf::Color::Black);

            if (centralizado)
            {
                // centralizar texto
                sf::FloatRect bounds = texto.getLocalBounds();
                texto.setOrigin(bounds.width / 2, bounds.height / 2);
                texto.setPosition(pos.x + tam.x / 2, pos.y + tam.y / 2);
            }
            else
                texto.setPosition(pos.x + 10, pos.y + tam.y / 2.f - 10);
        }
        CaixaTexto::~CaixaTexto() = default;




        void CaixaTexto::desenhar() {
            pGerenciadorGrafico->desenhar(*pSprite);
            pGerenciadorGrafico->desenhar(texto);
        }
        void CaixaTexto::executar()
        {
            desenhar();
        }




        void CaixaTexto::setTexto(std::string& username)
        {
            texto.setString(username);
        }

    }
}
