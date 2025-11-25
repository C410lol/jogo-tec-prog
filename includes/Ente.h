#ifndef JOGO_ENTE_H
#define JOGO_ENTE_H

#include <SFML/Graphics.hpp>
#include "IDs.h"




namespace jogo {
    namespace gerenciadores {
        class GerenciadorGrafico;
    }

    class Ente
    {
    protected:
        IDs Id;
        sf::Texture *pTexture;
        sf::Sprite *pSprite;
        static gerenciadores::GerenciadorGrafico *pGerenciadorGrafico;

    public:
        Ente();
        virtual ~Ente();

        virtual void executar() = 0;
        virtual void desenhar();

        sf::Sprite* getSprite() const;
        void setTexture(std::string path);

        static void setGerenciadorGrafico(gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico);
        IDs getId();
    };

}




#endif //JOGO_ENTE_H