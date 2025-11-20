#ifndef JOGO_PROJETIL_H
#define JOGO_PROJETIL_H

#include "entidades/Entidade.h"
#include "entidades/personagens/Jogador.h"




namespace jogo {
        namespace entidades {

            class Projetil:public Entidade
            {
                private:
                    int dano;
                    float vel;
                    personagens::Personagem* pDono;

                public:
                    Projetil
                    (
                        sf::Vector2f r_posicao, sf::Vector2f r_tamanho,
                        personagens::Personagem* r_pPersonagem, float vel, int r_dano
                    );
                    Projetil();
                    ~Projetil();

                    void executar() override;
                    void deslocar();

                    void salvar() override;

                    void acertar(personagens::Jogador *pJogador);
                    void destruir();
            };
        }
    }
#endif //JOGO_PROJETIL_H
