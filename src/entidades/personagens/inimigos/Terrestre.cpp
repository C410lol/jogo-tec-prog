#include "entidades/personagens/inimigos/Terrestre.h"
#include "entidades/personagens/Jogador.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                int Terrestre::instancias = 0;
                int Terrestre::getInstancias() { return instancias; }




                Terrestre::Terrestre(sf::Vector2f r_posicao, sf::Vector2f r_tamanho):
                Inimigo(r_posicao, r_tamanho, 1, true, 1), atrito((rand() % 6) + 1)
                {
                    ++instancias;
                    deslocamento = atrito;

                    setTexture("../assets/personagens/terrestre.png");
                    fixTexture();
                }
                Terrestre::Terrestre() = default;
                Terrestre::~Terrestre() {
                    --instancias;
                };




                void Terrestre::executar() {
                    Inimigo::executar();
                }




                void Terrestre::deslocar()
                {
                    if (!pJogadorAlvo)
                        return;

                    if (!pJogadorAlvo->getAtivo())
                        return;

                    float disX = pJogadorAlvo->getPosicao().x - getPosicao().x;
                    if (disX > 0)
                    {
                        olhandoDireita = true;
                        mover(deslocamento, 0.f);
                    }
                    if (disX < 0)
                    {
                        olhandoDireita = false;
                        mover(-deslocamento, 0.f);
                    }
                }

            }
        }
    }
}
