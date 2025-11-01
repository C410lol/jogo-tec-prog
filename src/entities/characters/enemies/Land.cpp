#include "entities/characters/enemies/Land.h"



namespace game {
    namespace entities {
        namespace characters {
            namespace enemies {

                Land::Land(Player *r_pPlayer): Enemy(r_pPlayer)
                {
                    size = sf::Vector2f(50.0f, 50.0f);
                    position = sf::Vector2f(600.0f, 500.0f);

                    rectangle.setSize(size);
                    rectangle.setPosition(position);
                    rectangle.setFillColor(sf::Color::Red);
                }
                Land::~Land() = default;


                void Land::mover()
                {
                    if (pPlayerTarget)
                    {
                        float disX = pPlayerTarget->getPosition().x - getPosition().x;

                        //  Se desloca até o jogador até certo raio
                        if (std::abs(disX) > LAND_MAX_RADIUS)
                        {
                            if (disX > 0)
                                move(SPEED, 0.f);
                            if (disX < 0)
                                move(-SPEED, 0.f);
                        }
                    }
                }

            }
        }
    }
}