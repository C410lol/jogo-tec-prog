#include "entities/obstacles/Obstacle.h"




namespace game {
    namespace entities {
        namespace obstacles {

            Obstacle::Obstacle()
            {
                size = sf::Vector2f(400.0f, 50.0f);
                position = sf::Vector2f(500.0f, 550.0f);

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
                float disX =
                    (entity.getPosition().x + (getSize().x / 2.f)) -
                    (getPosition().x + (getSize().x / 2.f));
                float disY =
                    (entity.getPosition().y + (getSize().y / 2.f)) -
                    (getPosition().y + (getSize().y / 2.f));

                float disAX = std::abs(disX);
                float disAY = std::abs(disY);

                float sumX = (entity.getSize().x / 2.f + getSize().x / 2);
                float sumY = (entity.getSize().y / 2.f + getSize().y / 2.f);
                if (disAX < sumX && disAY < sumY)
                {
                    if (sumX - disAX > sumY - disAY)
                    {
                        if (disX < 0)
                        {
                            entity.setPosition(
                                sf::Vector2f(entity.getPosition().x - (sumX - disAX), entity.getPosition().y)
                            );
                        }
                        else
                        {
                            entity.setPosition(
                                sf::Vector2f(entity.getPosition().x + (sumX - disAX), entity.getPosition().y)
                            );
                        }
                    }
                    else
                    {
                        if (disY < 0)
                        {
                            entity.setPosition(
                                sf::Vector2f(entity.getPosition().x, entity.getPosition().y - (sumY - disAY))
                            );
                        }
                        else
                        {
                            entity.setPosition(
                                sf::Vector2f(entity.getPosition().x, entity.getPosition().y + (sumY - disAY))
                            );
                        }
                    }
                }
            }


        }
    }
}
