#include "fases/Fase.h"

#include <iostream>

#include "entidades/obstaculos/Espinho.h"
#include "entidades/obstaculos/Plataforma.h"
#include "entidades/obstaculos/Meleca.h"
#include "entidades/personagens/inimigos/Voador.h"
#include "entidades/personagens/inimigos/Terrestre.h"
#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {
    namespace fases {

        Fase::Fase() { setarProporcao(); }
        Fase::~Fase() = default;




        void Fase::setarProporcao()
        {
            if (pGerenciadorGrafico)
            {
                proporcao.x = pGerenciadorGrafico->getWindowSize().x / 42.f;
                proporcao.y = pGerenciadorGrafico->getWindowSize().y / 24.f;
            }
        }





        void Fase::criarCenario()
        {
            //criarJogadores();
            //criarInimigos();
            criarObstaculos();
        }




        void Fase::executar()
        {
            gerenciadorColisao.checarColisoes();
            listaEntidades.percorrer();
        }

    }
}

