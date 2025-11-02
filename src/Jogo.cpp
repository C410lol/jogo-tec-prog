#include "Jogo.h"




namespace jogo
{
    Jogo::Jogo()
    {
        menus::MenuPrincipal::setGerenciadorGrafico(&gerenciadorGrafico);
        fases::Fase::setGerenciadorGrafico(&gerenciadorGrafico);

        pMenuPrincipal = new menus::MenuPrincipal();
        exec();
    }

    Jogo::~Jogo() = default;


    void Jogo::exec()
    {
        while (gerenciadorGrafico.isJanelaAberta())
        {
            sf::Event event;
            while (gerenciadorGrafico.getJanela()->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    gerenciadorGrafico.getJanela()->close();
                }
            }
            gerenciadorGrafico.limpar();

            //primeiraFase.exec();
            pMenuPrincipal->executar();

            gerenciadorGrafico.mostrar();
        }
    }
}
