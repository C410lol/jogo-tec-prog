#ifndef JOGO_ENEMY_H
#define JOGO_ENEMY_H

#include "entidades/personagens/Personagem.h"
#include "entidades/personagens/Jogador.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
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
                };

            }
        }
    }
}




#endif //JOGO_ENEMY_H