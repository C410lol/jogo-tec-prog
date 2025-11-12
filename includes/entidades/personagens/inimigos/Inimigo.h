#ifndef JOGO_ENEMY_H
#define JOGO_ENEMY_H

#include "entidades/personagens/Personagem.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            class Jogador;

            namespace inimigos {

                class Inimigo: public Personagem
                {
                protected:
                    Jogador *pJogadorAlvo;
                    int nivelMaldade;
                    int deslocamento;

                public:
                    Inimigo
                    (
                        sf::Vector2f r_posicao, sf::Vector2f r_tamanho, int r_vidas, bool r_sofreGravidade,
                        int r_nivelMaldade
                    );
                    Inimigo();
                    virtual ~Inimigo();

                    void executar() override;
                    virtual void deslocar() = 0;

                    void danificar(Jogador *pJogador);
                    void setJogadoralvo(Jogador* pjog);
                };

            }
        }
    }
}




#endif //JOGO_ENEMY_H