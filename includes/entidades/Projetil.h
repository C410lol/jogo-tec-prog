//
// Created by mvmko on 03/11/2025.
//

#ifndef JOGO_PROJETIL_H
#define JOGO_PROJETIL_H
#include "Entidade.h"
#include "personagens/inimigos/Inimigo.h"


namespace jogo {
        namespace entidades {

            class Projetil:public Entidade
            {
                protected:
                    float vel;
                    personagens::Personagem* pDono;
                public:
                    Projetil(personagens::Personagem* r_pPersonagem, float vel);
                    ~Projetil();
                    void executar();
                    void deslocar();
            };
        }
    }
#endif //JOGO_PROJETIL_H
