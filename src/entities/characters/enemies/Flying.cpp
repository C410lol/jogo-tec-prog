#include "entities/characters/enemies/Flying.h"

#include <cmath>
#include <iostream>


namespace game {
    namespace entities {
        namespace characters {
            namespace enemies {

                Flying::Flying(Player *r_pPlayer): Enemy(r_pPlayer)
                {
                    size = sf::Vector2f(50.0f, 50.0f);
                    position = sf::Vector2f(600.0f, 500.0f);

                    rectangle.setSize(size);
                    rectangle.setPosition(position);
                    rectangle.setFillColor(sf::Color::Yellow);
                }

                Flying::~Flying() = default;


                /*
                void Flying::mover()
                {
                    if (pPlayerTarget)
                    {

                        float disX = pPlayerTarget->getPosition().x - getPosition().x;
                        float disY = pPlayerTarget->getPosition().y - getPosition().y;

                        if (disX > 0)
                            move(0.1f, 0.f);
                        if (disX < 0)
                            move(-0.1f, 0.f);
                        if (disY > 0)
                            move(0.f, 0.1f);
                        if (disY < 0)
                            move(0.f, -0.1f);
                    }
                }
                */

                void Flying::mover()
                {
                    if (pPlayerTarget)
                    {

                        float disX = pPlayerTarget->getPosition().x - getPosition().x;
                        float disY = pPlayerTarget->getPosition().y - getPosition().y;
                        float magnitude = std::sqrt(disX * disX + disY * disY);

                        if (magnitude != 0.f)
                        {
                            //  Normaliza o vetor direção
                            float dirX = disX / magnitude;
                            float dirY = disY / magnitude;

                            move(dirX * SPEED, dirY * SPEED);
                        }
                    }
                }

            }
        }
    }
}
