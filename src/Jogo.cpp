#include "Jogo.h"

#include <iostream>

#include "estados/EstadoJogo.h"
#include "estados/EstadoMenu.h"
#include "fases/PrimeiraFase.h"
#include "fases/SegundaFase.h"
#include "gerenciadores/GerenciadorEstado.h"
#include "menus/Botao.h"
#include "menus/MenuPrincipal.h"


namespace jogo
{
    Jogo::Jogo():
    pge(gerenciadores::GerenciadorEstado::getGerenEstado())
    {
        Ente::setGerenciadorGrafico(&gerenciadorGrafico);
        estados::Estado::setGE(gerenciadores::GerenciadorEstado::getGerenEstado());
        fases::Fase::pjogo = this;
        pge->adicionarEstado(IDs::menu_principal);
        exec();
    }
    Jogo::~Jogo() = default;

    std::list<entidades::personagens::Jogador*>* Jogo::getLista()
    {
        return &listaJogadores;
    }



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
            pge->executar();
            if (pge->getEstadoAtual()->getvoltaMenu()) {
                pge->adicionarEstado(IDs::menu_pausa);
            }
            gerenciadorGrafico.mostrar();
        }
    }




    void Jogo::startF1()
    {

    }
    void Jogo::startF2()
    {

    }

}
