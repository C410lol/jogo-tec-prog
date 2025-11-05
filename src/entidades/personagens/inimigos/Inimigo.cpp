#include "entidades/personagens/inimigos/Inimigo.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                Inimigo::Inimigo(Jogador *r_pJogadorAlvo, int r_vidas, bool r_sofreGravidade):
                Personagem(r_vidas, r_sofreGravidade), pJogadorAlvo(r_pJogadorAlvo)
                {}
                Inimigo::~Inimigo() = default;


                void Inimigo::executar()
                {
                    Personagem::executar();
                }

            }
        }
    }
}
