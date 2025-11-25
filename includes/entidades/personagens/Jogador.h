#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "entidades/personagens/Personagem.h"
#include "inimigos/Terrestre.h"

#include "dtos/PersonagemDTO.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            class Jogador: public Personagem
            {
            private:
                static int instancias;
                static bool primeiroExiste;

                bool ehPrimeiro;
                float deslocamentoX;
                bool naMeleca;
                bool atacando;
                int cooldown;
                int pontos;
                int ultimaPontuacao;
            private:
                void atualizarNaMeleca();

            public:
                Jogador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);
                Jogador
                (
                    dtos::PersonagemDTO perDTO, bool r_ehPrimeiro, float r_deslocamentoX, bool r_naMeleca,
                    bool r_atacando, int r_cooldown, int r_pontos
                );
                Jogador();
                ~Jogador() override;

                void executar() override;

                void salvar() override;

                void setNaMeleca(bool r_estaNaMeleca);
                void setAtacando(bool r_atacando);

                bool getAtacando() const;

                bool getEhPrimeiro() const;

                void atacar(inimigos::Inimigo *pInimigo);

                void pular();
                void moverEsquerda();
                void moverDireita();
                void ataque();

                void resetarJogador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool resetarPontuacao);
                void setJogador
                (
                    dtos::PersonagemDTO perDTO, bool r_ehPrimeiro, float r_deslocamentoX, bool r_naMeleca,
                    bool r_atacando, int r_cooldown, int r_pontos
                );

                int getUltimaPontuacao() const;
                
                static void setJogadorExiste(bool est);

                static int getInstancias();
                static void setInstancias(int instancias);
            };

        }
    }

}




#endif //JOGO_PLAYER_H