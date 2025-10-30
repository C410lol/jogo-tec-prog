#include "Game.h"




namespace game
{
    Game::Game()
    {
        exec();
    };
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

            prologue.exec();
        }
    }
}
