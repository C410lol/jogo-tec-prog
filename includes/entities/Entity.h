#ifndef JOGO_ENTITY_H
#define JOGO_ENTITY_H

#include <SFML/Graphics.hpp>




namespace game {
    namespace entities {

        class Entity
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
            sf::Vector2f getPosition() const;
            sf::Vector2f getSize() const;

            void setPosition(sf::Vector2f r_position);

        };

    }
}




#endif //JOGO_ENTITY_H