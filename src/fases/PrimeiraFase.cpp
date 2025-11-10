#include "fases/PrimeiraFase.h"

#include "entidades/obstaculos/Espinho.h"
#include "entidades/personagens/inimigos/Terrestre.h"
#include "entidades/personagens/inimigos/Voador.h"




namespace jogo {
    namespace fases {

        PrimeiraFase::PrimeiraFase(): maxTerrestres(8), maxVoadores(4), maxEspinhos(20) {}
        PrimeiraFase::~PrimeiraFase() = default;




        void PrimeiraFase::criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::personagens::inimigos::Terrestre::instancias >= maxTerrestres)
                return;
            Fase::criarTerrestre(posicao, tamanho);
        }
        void PrimeiraFase::criarVoador(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::personagens::inimigos::Voador::instancias >= maxVoadores)
                return;
            Fase::criarVoador(posicao, tamanho);
        }




        void PrimeiraFase::criarEspinho(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::obstaculos::Espinho::instancias >= maxEspinhos)
                return;
            Fase::criarEspinho(posicao, tamanho);
        }

    }
}
