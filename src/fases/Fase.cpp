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



        Fase::Fase()
        {
            criaJogadores();
            criaInimigos();
            criaObstaculos();
        };
        Fase::~Fase() = default;




        void Fase::criaJogadores()
        {
            entidades::personagens::Jogador *pJogador = new entidades::personagens::Jogador();
            listaEntidades.incluir(pJogador);
            GerenciadorColisao.incluirJogador(pJogador);
        }
        void Fase::criaInimigos()
        {
            entidades::personagens::inimigos::Voador *pVoador = new entidades::personagens::inimigos::Voador(
                GerenciadorColisao.getJogador()
            );
            entidades::personagens::inimigos::Terrestre *pTerrestre = new entidades::personagens::inimigos::Terrestre(
                GerenciadorColisao.getJogador()
            );
            listaEntidades.incluir(pVoador);
            listaEntidades.incluir(pTerrestre);
            GerenciadorColisao.incluirInimigo(pVoador);
            GerenciadorColisao.incluirInimigo(pTerrestre);
        }
        void Fase::criaObstaculos()
        {
            entidades::obstaculos::Plataforma *pPlataforma = new entidades::obstaculos::Plataforma();
            entidades::obstaculos::Espinho *pEspinho = new entidades::obstaculos::Espinho();
            entidades::obstaculos::Meleca *pMeleca = new entidades::obstaculos::Meleca();
            listaEntidades.incluir(pPlataforma);
            listaEntidades.incluir(pEspinho);
            listaEntidades.incluir(pMeleca);
            GerenciadorColisao.incluirObstaculo(pPlataforma);
            GerenciadorColisao.incluirObstaculo(pEspinho);
            GerenciadorColisao.incluirObstaculo(pMeleca);
        }

        void Fase::exec()
        {
            GerenciadorColisao.checarColisoes();
            listaEntidades.percorrer();

            }
        }


    }

