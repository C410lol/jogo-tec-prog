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
        sf::Vector2f Entity::getPosition() const
        {
            return position;
        }
        sf::Vector2f Entity::getSize() const
        {
            return size;
        }

        void Entity::setPosition(sf::Vector2f r_position)
        {
            position = r_position;
        }

    }
}
