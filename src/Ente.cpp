#include "Ente.h"

#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {

    Ente::Ente()
    {
        pSprite = new sf::Sprite();
    };
    Ente::~Ente()
    {
        if (pTexture)
            delete pTexture;
        if (pSprite)
            delete pSprite;
    };




    gerenciadores::GerenciadorGrafico *Ente::pGerenciadorGrafico = nullptr;
    void Ente::setGerenciadorGrafico(gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico)
    {
        pGerenciadorGrafico = r_pGerenciadorGrafico;
    }
    void Ente::desenhar()
    {
        pGerenciadorGrafico->desenhar(this);
    }




    sf::Sprite* Ente::getSprite() const
    {
        return pSprite;
    }

    void Ente::setTexture(std::string path)
    {
        pTexture = new sf::Texture();
        pTexture->loadFromFile(path);
        pSprite->setTexture(*pTexture);
    }


}
