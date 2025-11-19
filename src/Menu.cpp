/*
#include "Menu.h"

#include <iostream>

#include "Jogo.h"

namespace jogo{
    Menu::Menu(Jogo *r_pjogo)
    {
            pjogo=r_pjogo;
            executar();
    }
    Menu::Menu() = default;
    Menu::~Menu() = default;

    void Menu::executar()
    {
        std::cout<<"qual opcao"<<std::endl;
        int choice;

        std::cout<<"1"<<"jogar fase 1"<<std::endl;
        std::cout<<"2"<<"jogar fase 2"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
            case 1:
                pjogo->startF1();
                break;
            case 2:
                pjogo->startF2();
                break;
        }
    }


}
*/
