#include "entidades/personagens/inimigos/Voador.h"
#include "entidades/personagens/Jogador.h"

#include <cmath>
#include "fases/Fase.h"



namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                int Voador::instancias = 0;




                Voador::Voador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
                Inimigo(r_posicao, r_tamanho, 2, false, 2),
                energia((rand() % 6) + 1)
                {
                    ++instancias;
                    deslocamento = energia;

                    setTexture("../assets/personagens/voador.png");
                    fixTexture();
                }
                Voador::Voador() = default;
                Voador::~Voador() {
                    --instancias;
                };




                void Voador::deslocar()
                {
                    if (pJogadorAlvo)
                    {
                        float disX = pJogadorAlvo->getPosicao().x - getPosicao().x;
                        float disY = pJogadorAlvo->getPosicao().y - getPosicao().y;
                        float magnitude = std::sqrt(disX * disX + disY * disY);

                        if (magnitude != 0.f)
                        {
                            //  Normaliza o vetor direção
                            float dirX = disX / magnitude;
                            float dirY = disY / magnitude;

                            olhandoDireita = disX >= 0;
                            mover(dirX * static_cast<float>(deslocamento), dirY * static_cast<float>(deslocamento));
                        }
                    }
                }
                void Voador::atacar()
                {
                    pFase->incluiprojetil(pFase->criaprojetil(this));
                }

            }
        }
    }
}
