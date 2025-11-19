


#include "estados/EstadoJogo.h"

#include <iostream>

#include "fases/PrimeiraFase.h"
#include "fases/SegundaFase.h"

namespace jogo {
    namespace estados {
        EstadoJogo::EstadoJogo(IDs id, int numJogadores):Estado(id) {
            criarFase(id, numJogadores);
        }
        EstadoJogo::~EstadoJogo() {
            if (fase) {
                delete fase;
                fase = nullptr;
            }
        }
        void EstadoJogo::executar() {
            fase->executar();
            voltaMenu = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                voltaMenu = true;
            }

        }
        void EstadoJogo::criarFase(IDs idFase, int numJogadores) {
            if (idFase == IDs::primeira_fase)
                fase = static_cast<fases::Fase*>(new fases::PrimeiraFase(numJogadores, IDs::primeira_fase));
            else {
                fase = static_cast<fases::Fase*>(new fases::SegundaFase(numJogadores, IDs::segunda_fase));
            }
        }


    }
}
