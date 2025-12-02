#include "entidades/personagens/inimigos/Terrestre.h"
#include "entidades/personagens/Jogador.h"


namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {
                int Terrestre::numInstancias = 0;
                int Terrestre::getInstancias() { return numInstancias; }
                void Terrestre::setInstancias(int r_instancias) { numInstancias = r_instancias; }


                Terrestre::Terrestre(sf::Vector2f r_posicao, sf::Vector2f r_tamanho) : Inimigo(r_posicao, r_tamanho, 1,
                    true, 1), atrito((rand() % 6) + 1)
                {
                    ++numInstancias;

                    deslocamento = atrito;

                    setTexture("../assets/personagens/terrestre.png");
                    fixTexture();
                }

                Terrestre::Terrestre(dtos::InimigoDTO iniDTO, int r_atrito) : Inimigo(iniDTO), atrito(r_atrito)
                {
                    ++numInstancias;

                    deslocamento = atrito;

                    setTexture("../assets/personagens/terrestre.png");
                    fixTexture();
                }

                Terrestre::Terrestre() = default;

                Terrestre::~Terrestre() { --numInstancias; }


                void Terrestre::executar()
                {
                    Inimigo::executar();
                }


                void Terrestre::salvar()
                {
                    Inimigo::salvar();
                    buffer << static_cast<int>(IDs::terrestre) << " " << atrito;
                }


                void Terrestre::deslocar()
                {
                    if (!pJogadorAlvo)
                        return;

                    if (!pJogadorAlvo->getAtivo())
                        return;

                    float disX = pJogadorAlvo->getPosicao().x - getPosicao().x;
                    if (disX > 0) {
                        olhandoDireita = true;
                        mover(deslocamento, 0.f);
                    }
                    if (disX < 0) {
                        olhandoDireita = false;
                        mover(-deslocamento, 0.f);
                    }
                }
            }
        }
    }
}