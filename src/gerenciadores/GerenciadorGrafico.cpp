#include "gerenciadores/GerenciadorGrafico.h"
#include "entidades/Entidade.h"




namespace jogo {
    namespace gerenciadores {

        GerenciadorGrafico::GerenciadorGrafico()
        {
            criarJanela();
        }
        GerenciadorGrafico::~GerenciadorGrafico() = default;




        void GerenciadorGrafico::criarJanela()
        {
            pJanela = new sf::RenderWindow(sf::VideoMode({1280, 720}), "Game");
            pJanela->setFramerateLimit(30);
        }
        void GerenciadorGrafico::fecharJanela() const {
            pJanela->close();
        }




        bool GerenciadorGrafico::isJanelaAberta() const
        {
            if (pJanela)
                return pJanela->isOpen();
            return false;
        }



        void GerenciadorGrafico::limpar() const
        {
            if (pJanela)
                pJanela->clear();
        }
        void GerenciadorGrafico::desenhar(Ente *pEnte) const
        {
            if (pJanela && pEnte)
                pJanela->draw(*pEnte->getSprite());
        }
        void GerenciadorGrafico::mostrar() const
        {
            if (pJanela)
                pJanela->display();
        }




        sf::Vector2u GerenciadorGrafico::getWindowSize() const
        {
            return pJanela->getSize();
        }
        sf::RenderWindow* GerenciadorGrafico::getJanela() const
        {
            return pJanela;
        }

    }
}
