#include "entities/obstacles/Obstacle.h"




namespace game {
    namespace entities {
        namespace obstacles {

            Obstacle::Obstacle()
            {
                size = sf::Vector2f(5000.0f, 50.0f);
                position = sf::Vector2f(0.0f, 550.0f);

                rectangle.setSize(size);
                rectangle.setPosition(position);
                rectangle.setFillColor(sf::Color::Red);
            }
            Obstacle::~Obstacle()
            {

            }


            void Obstacle::exec()
            {
            }


            void Obstacle::obstruct(Entity &entity)
            {
                float disX = entity.getPositionX() - getPositionX();
                float disY = entity.getPositionX() - getPositionX();

                float disAX = std::abs(disX);
                float disAY = std::abs(disY);

                float sumX = entity.getSize().x / 2 + getSize().x / 2;
                float sumY = entity.getSize().y / 2 + getSize().y / 2;

                if (disAX < sumX && disAY < sumY)
                {
                    if (sumX - disAX > sumY - disAY)
                    {
                        if (disX < 0)
                        {
                            entity.setPosition(
                                sf::Vector2f(entity.getPositionX() - (sumX - disAX), entity.getPositionY())
                            );
                        }
                        else
                        {
                            entity.setPosition(
                                sf::Vector2f(entity.getPositionX() + (sumX - disAX), entity.getPositionY())
                            );
                        }
                    }
                    else
                    {
                        if (disY < 0)
                        {
                            entity.setPosition(
                                sf::Vector2f(entity.getPositionX(), entity.getPositionY() - (sumY - disAY))
                            );
                        }
                        else
                        {
                            entity.setPosition(
                                sf::Vector2f(entity.getPositionX(), entity.getPositionY() + (sumY - disAY))
                            );
                        }
                    }
                }
            }


        }
    }
}
