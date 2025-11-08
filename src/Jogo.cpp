#include "Jogo.h"




namespace jogo
{
    Jogo::Jogo()
    {
        Ente::setGerenciadorGrafico(&gerenciadorGrafico);
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
            primeiraFase.exec();
            gerenciadorGrafico.mostrar();
        }
    }
}
