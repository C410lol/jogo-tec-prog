#include "Game.h"
#include "fases/Fase.h"




namespace game
{
    Game::Game()
    {
        fases::Fase::setGraphicManager(&graphicManager);
        exec();
    }

    Game::~Game() = default;

    void Game::exec()
    {
        while (graphicManager.isWindowOpen())
        {
            sf::Event event;
            while (graphicManager.getWindow()->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    graphicManager.getWindow()->close();
                }
            }

            graphicManager.clear();
            prologue.exec();
            graphicManager.display();
        }
    }
}
