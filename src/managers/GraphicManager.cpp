#include "managers/GraphicManager.h"
#include "entities/Entity.h"




namespace game {
    namespace managers {

        GraphicManager::GraphicManager()
        {
            createWindow();
        }
        GraphicManager::~GraphicManager() = default;


        void GraphicManager::createWindow()
        {
            pWindow = new sf::RenderWindow(sf::VideoMode({1280, 720}), "Game");
        }


        bool GraphicManager::isWindowOpen() const
        {
            if (pWindow)
                return pWindow->isOpen();
            return false;
        }



        void GraphicManager::clear() const
        {
            if (pWindow)
                pWindow->clear();
        }
        void GraphicManager::draw(const entities::Entity &entity) const
        {
            if (pWindow)
                pWindow->draw(entity.getRectangle());
        }
        void GraphicManager::display() const
        {
            if (pWindow)
                pWindow->display();
        }

        sf::RenderWindow* GraphicManager::getWindow() const
        {
            return pWindow;
        }


    }
}
