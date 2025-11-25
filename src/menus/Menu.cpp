#include "../../includes/menus/Menu.h"

#include <iostream>

#include "Jogo.h"
#include "estados/EstadoJogo.h"
#include "estados/EstadoMenu.h"
#include "gerenciadores/GerenciadorEstado.h"

namespace jogo{
    //Menu::Menu(Jogo *r_pjogo) : pge(gerenciadores::GerenciadorEstado::getGerenEstado())
    //{
            //pjogo=r_pjogo;
        //executar();
    //}
    Jogo *Menu::pjogo = nullptr;
    void Menu::setJogo(Jogo *r_pJogo) {
        pjogo = r_pJogo;
    }


    Menu::Menu()  : pge(gerenciadores::GerenciadorEstado::getGerenEstado()), Ente() {
        //executar();

    }
    Menu::~Menu(){}

    void Menu::executar() {
        //atualizar();
        //desenharbotoes();
    }

    }

        /*std::cout<<"qual opcao"<<std::endl;
        int choice;

        std::cout<<"1"<<"jogar fase 1"<<std::endl;
        std::cout<<"2"<<"jogar fase 2"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
            case 1: {
                pge->adicionarEstado(IDs::primeira_fase);
                estados::EstadoJogo *estadoJogo =  dynamic_cast<estados::EstadoJogo *>(pge->getEstadoAtual());
                estadoJogo->criarFase(IDs::primeira_fase);
                break;
            }
            case 2: {
                pge->adicionarEstado(IDs::segunda_fase);
                estados::EstadoJogo* estadoJogo =  dynamic_cast<estados::EstadoJogo *>(pge->getEstadoAtual());
                estadoJogo->criarFase(IDs::segunda_fase);
                break;
            }
            //case 3:
                pge->adicionarEstado(IDs::menu_principal);
                estados::EstadoMenu* estadoMenu =  dynamic_cast<estados::EstadoMenu *>(pge->getEstadoAtual());
                estadoMenu->criarMenu();
                break;
        }
    }


}
*/
