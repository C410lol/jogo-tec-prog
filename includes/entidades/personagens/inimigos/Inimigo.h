#ifndef JOGO_ENEMY_H
#define JOGO_ENEMY_H

#include "entidades/personagens/Personagem.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            class Jogador;

            namespace inimigos {

                #define VELOCIDADE 3.f

                class Inimigo: public Personagem
                {
                protected:
                    Jogador *pJogadorAlvo;

                public:
                    Inimigo(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, int r_vidas, bool r_sofreGravidade);
                    Inimigo();
                    virtual ~Inimigo();

                    void executar() override;
                    virtual void deslocar() = 0;

                    void colidir(Entidade *pEntidade) override;
                    void setJogadoralvo(Jogador* pjog);
                };

            }
        }
    }
}




#endif //JOGO_ENEMY_H