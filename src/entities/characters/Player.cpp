#include "entities/characters/Player.h"
#include <SFML/System.hpp>
#include <iostream>




namespace game {
    namespace entities {
        namespace characters {

            Player::Player(): points(0)
            {
                size = sf::Vector2f(100.0f, 150.0f);
                position = sf::Vector2f(200.0f, 200.0f);
                rectangle.setSize(size);
                rectangle.setPosition(position);
                rectangle.setFillColor(sf::Color::Blue);
                rectangle.setOrigin(rectangle.getSize()/2.f);
            };
            Player::~Player() = default;


            void Player::exec()
            {
                mover();
                Character::exec();
            }


            void Player::mover()
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    position.x += -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    position.x += 1;

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    position.y += -1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    position.y += 1;
                }
            }


        }
    }
}

