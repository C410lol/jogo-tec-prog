#include "entities/characters/Player.h"
#include <SFML/System.hpp>
#include <iostream>




namespace game {
    namespace entities {
        namespace characters {

            Player::Player(): points(0)
            {
                size = sf::Vector2f(50.0f, 50.0f);
                position = sf::Vector2f(200.0f, 200.0f);

                rectangle.setSize(size);
                rectangle.setPosition(position);
                rectangle.setFillColor(sf::Color::Blue);
            };
            Player::~Player() = default;


            void Player::exec()
            {
                mover();

                //Character::fall();
                Character::exec();
            }


            void Player::mover()
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    move(-0.5f, 0.f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    move(0.5f, 0.f);

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    move(0.f, -0.5f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    move(0.f, 0.5f);
                }
            }


        }
    }
}

