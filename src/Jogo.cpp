#include "Jogo.h"

#include <iostream>

#include "estados/EstadoJogo.h"
#include "estados/EstadoMenu.h"
#include "fases/PrimeiraFase.h"
#include "fases/SegundaFase.h"
#include "gerenciadores/GerenciadorEstado.h"
#include "menus/Botao.h"
#include "menus/MenuPrincipal.h"
#include "fases/Fase.h"


namespace jogo
{
    Jogo::Jogo():
    inputSubject(observers::InputSubject::getInstancia()),
    pge(gerenciadores::GerenciadorEstado::getGerenEstado())
    {
        Ente::setGerenciadorGrafico(&gerenciadorGrafico);
        pge->adicionarEstado(IDs::menu_principal);
        fases::Fase::pjogo = this;
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
            inputSubject->execute();
            pge->executar();
            if (pge->getEstadoAtual()->getvoltaMenu()) {
                pge->adicionarEstado(IDs::menu_pausa);
            }
            gerenciadorGrafico.mostrar();
        }
    }
    bool Jogo::verificaVazio() {
        if (listaJogadores.empty())
            return true;
        else
            return false;
    }
    void Jogo::incluiJogador(entidades::personagens::Jogador *pjog) {

        listaJogadores.push_back(pjog);
    }
    void Jogo::retirarJogador(entidades::personagens::Jogador *pjog) {
        std::list<entidades::personagens::Jogador*>::iterator it;
        for (it = listaJogadores.begin(); it != listaJogadores.end(); ++it) {
            if (pjog == *it) {
                listaJogadores.erase(it);
                break;
            }
        }
    }
    int Jogo::getTam() {
        return listaJogadores.size();
    }
    void Jogo::setposicao(sf::Vector2f posicao, sf::Vector2f tamanho, int pos) {
        std::list<entidades::personagens::Jogador*>::iterator it = listaJogadores.begin();

        for (int i = 0; i < pos; i++) {
            it++;
        }

        (*it)->setPosicao(posicao);
        (*it)->setTamanho(tamanho);
    }
    entidades::personagens::Jogador *Jogo::getJogador(int pos) {
        std::list<entidades::personagens::Jogador*>::iterator it = listaJogadores.begin();

        for (int i = 0; i < pos; i++) {
            it++;
        }
        return (*it);
    }









}
