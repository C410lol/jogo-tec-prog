#include "entidades/obstaculos/Bandeira.h"

#include <iostream>

#include "entidades/personagens/Jogador.h"
#include "fases/Fase.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {
            Bandeira::Bandeira(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso) :
            Obstaculo(r_posicao, r_tamanho, r_danoso),
            pge(gerenciadores::GerenciadorEstado::getGerenEstado()){

                setTexture("../assets/obstaculos/Waving Flag Red.gif");
                fixTexture();

            }
            Bandeira::~Bandeira() {

            }
            void Bandeira::obstaculizar(Entidade *pEntidade) {
                personagens::Jogador* pJogador = dynamic_cast<personagens::Jogador*>(pEntidade);
                if (!pJogador)
                    return;
                pge->adicionarEstado(IDs::segunda_fase, fases::Fase::pjogo->getTam());

            }
            void Bandeira::executar() {

            }




        }
    }
}