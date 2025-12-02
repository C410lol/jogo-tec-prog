#include "Jogo.h"

#include <iostream>

#include "estados/EstadoJogo.h"
#include "estados/EstadoMenu.h"
#include "fases/PrimeiraFase.h"
#include "fases/SegundaFase.h"
#include "gerenciadores/GerenciadorEstado.h"
#include "menus/Botao.h"
#include "menus/MenuPrincipal.h"


namespace jogo {
    Jogo::Jogo() : pge(gerenciadores::GerenciadorEstado::getGerenEstado())
    {
        fases::Fase::setJogo(this);
        Ente::setGerenciadorGrafico(&gerenciadorGrafico);
        Menu::setJogo(this);
        estados::Estado::setGE(gerenciadores::GerenciadorEstado::getGerenEstado());
        pge->adicionarEstado(IDs::menu_principal);
        criarJogadores();
        exec();
    }

    Jogo::~Jogo() = default;


    void Jogo::exec()
    {
        while (gerenciadorGrafico.isJanelaAberta()) {
            sf::Event event;
            while (gerenciadorGrafico.getJanela()->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
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


    void Jogo::criarJogadores()
    {
        jogadores.push_back(new entidades::personagens::Jogador(
            sf::Vector2f(0, 0), sf::Vector2f(0, 0)
        ));
        jogadores.push_back(new entidades::personagens::Jogador(
            sf::Vector2f(0, 0), sf::Vector2f(0, 0)
        ));

        jogadorObservers.push_back(new observers::JogadorObserver(jogadores[0]));
        jogadorObservers.push_back(new observers::JogadorObserver(jogadores[1]));

        observers::InputSubject::getInstancia()->attach(jogadorObservers[0]);
        observers::InputSubject::getInstancia()->attach(jogadorObservers[1]);
    }

    void Jogo::resetarJogadores()
    {
        jogadores[0]->resetarJogador(
            sf::Vector2f(0, 0), sf::Vector2f(0, 0), true
        );
        jogadores[1]->resetarJogador(
            sf::Vector2f(0, 0), sf::Vector2f(0, 0), true
        );
    }

    std::vector<entidades::personagens::Jogador *> &Jogo::getJogadores()
    {
        return jogadores;
    }
}