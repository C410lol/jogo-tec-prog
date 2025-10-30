#ifndef JOGO_GRAPHICMANAGER_H
#define JOGO_GRAPHICMANAGER_H

#include <SFML/Graphics.hpp>
#include "entities/Entity.h"




namespace game
{
    namespace managers
    {

        class GraphicManager
        {
        private:
            sf::RenderWindow* pWindow;
        private:
            void createWindow();

        public:
            GraphicManager();
            ~GraphicManager();

            bool isWindowOpen() const;

            void clear() const;
            void draw(const entities::Entity &entity) const;
            void display() const;

            sf::RenderWindow* getWindow() const;
        };
    }
}




#endif //JOGO_GRAPHICMANAGER_H