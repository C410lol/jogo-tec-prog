#include "Jogo.h"
#include "fases/PrimeiraFase.h"
#include "fases/SegundaFase.h"


namespace jogo
{
    Jogo::Jogo():
    inputSubject(observers::InputSubject::getInstancia())
    {
        Ente::setGerenciadorGrafico(&gerenciadorGrafico);
        pMenu= new Menu(this);
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
            inputSubject->execute();
            pFase->executar();
            gerenciadorGrafico.mostrar();
        }
    }
    void Jogo::startF1()
    {
        pFase= new fases::PrimeiraFase(2);
        pFase->inicializar();
        exec();
    }
    void Jogo::startF2()
    {
        pFase = new fases::SegundaFase(2);
        pFase->inicializar();
        exec();
    }
}
