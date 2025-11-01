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
        void GerenciadorGrafico::desenhar(const entidades::Entidade &entity) const
        {
            if (pJanela)
                pJanela->draw(entity.getRetangulo());
        }
        void GerenciadorGrafico::mostrar() const
        {
            if (pJanela)
                pJanela->display();
        }

        sf::RenderWindow* GerenciadorGrafico::getJanela() const
        {
            return pJanela;
        }

    }
}
