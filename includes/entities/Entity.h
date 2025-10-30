#ifndef JOGO_ENTITY_H
#define JOGO_ENTITY_H

#include "Ente.h"
#include <SFML/Graphics.hpp>




namespace game {
    namespace entities {

        class Entity: public Ente
        {
        protected:
            sf::Vector2f position;
            sf::RectangleShape rectangle;
            sf::Vector2f size;

        public:
            Entity();
            virtual ~Entity();

            virtual void exec() = 0;

            sf::RectangleShape getRectangle() const;
        };

    }
}




#endif //JOGO_ENTITY_H