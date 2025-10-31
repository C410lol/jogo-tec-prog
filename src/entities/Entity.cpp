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

        float Entity::getPositionX() const
        {
            return position.x / 2;
        }
        float Entity::getPositionY() const
        {
            return position.y / 2;
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
