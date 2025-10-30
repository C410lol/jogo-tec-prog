#include "./entities/Entity.h"
#include <SFML/Graphics.hpp>




namespace game {
    namespace entities {

        Entity::Entity() {}
        Entity::~Entity() {}

        sf::RectangleShape Entity::getRectangle() const
        {
            return rectangle;
        }


    }
}
