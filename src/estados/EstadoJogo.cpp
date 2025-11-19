


#include "estados/EstadoJogo.h"

#include <iostream>

#include "fases/PrimeiraFase.h"
#include "fases/SegundaFase.h"

namespace jogo {
    namespace estados {
        EstadoJogo::EstadoJogo(IDs id):Estado(id) {
            criarFase(id);
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
        void EstadoJogo::criarFase(IDs idfase) {
            if (idfase == IDs::primeira_fase)
                fase = static_cast<fases::Fase*>(new fases::PrimeiraFase(2, IDs::primeira_fase));
            else {
                fase = static_cast<fases::Fase*>(new fases::SegundaFase(2, IDs::segunda_fase));
            }
        }


    }
}
