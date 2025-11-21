#include "entidades/personagens/inimigos/Inimigo.h"
#include "entidades/personagens/Jogador.h"

#include <iostream>


namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                Inimigo::Inimigo
                (
                    sf::Vector2f r_posicao, sf::Vector2f r_tamanho, int r_vidas, bool r_sofreGravidade,
                    int r_nivelMaldade
                ):
                Personagem(r_posicao, r_tamanho, r_vidas, r_sofreGravidade), pJogadorAlvo(nullptr),
                nivelMaldade(r_nivelMaldade)
                {}
                Inimigo::Inimigo(dtos::InimigoDTO iniDTO):
                Personagem(iniDTO.perDTO), pJogadorAlvo(iniDTO.pJogadorAlvo),
                nivelMaldade(iniDTO.nivelMaldade), deslocamento(iniDTO.deslocamento)
                {}
                Inimigo::Inimigo() = default;
                Inimigo::~Inimigo() = default;




                void Inimigo::executar()
                {
                    deslocar();
                    Personagem::executar();
                }




                void Inimigo::salvar()
                {
                    Personagem::salvar();
                    buffer << static_cast<int>(IDs::inimigo) << " " << NULL << " " << nivelMaldade << " " <<
                    deslocamento << " ";
                }




                void Inimigo::danificar(Jogador *pJogador)
                {
                    if (!pJogador)
                        return;

                    sf::Vector2f vetorVelocidade;
                    vetorVelocidade.y = -275;
                    if (this->getPosicao().x < pJogador->getPosicao().x)
                        vetorVelocidade.x = 200;
                    else
                        vetorVelocidade.x = -200;

                    pJogador->setNoChao(false);
                    pJogador->setKnokback(true);
                    pJogador->setVelocidade(vetorVelocidade);
                    pJogador->tomarDano(nivelMaldade);
                }




                void Inimigo::setJogadoralvo(Jogador* pjog)
                {
                    pJogadorAlvo=pjog;
                }




                int Inimigo::getNivelMaldade() const
                {
                    return nivelMaldade;
                }

            }
        }
    }
}
