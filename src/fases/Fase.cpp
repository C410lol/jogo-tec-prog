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

        gerenciadores::GerenciadorGrafico *Fase::pGerenciadorGrafico = nullptr;


        Fase::Fase()
        {
            pGerenciadorColisao = new gerenciadores::GerenciadorColisao(
                &listaJogadores, &listaInimigos, &listaObstaculos
            );

            criaJogadores();
            criaInimigos();
            criaObstaculos();
        };
        Fase::~Fase() = default;




        void Fase::criaJogadores()
        {
            entidades::personagens::Jogador *pJogador = new entidades::personagens::Jogador();
            listaJogadores.incluir(pJogador);
        }
        void Fase::criaInimigos()
        {
            entidades::personagens::inimigos::Voador *pVoador = new entidades::personagens::inimigos::Voador(
                *listaJogadores.begin()
            );
            entidades::personagens::inimigos::Terrestre *pTerrestre = new entidades::personagens::inimigos::Terrestre(
                *listaJogadores.begin()
            );
            listaInimigos.incluir(pVoador);
            listaInimigos.incluir(pTerrestre);
        }
        void Fase::criaObstaculos()
        {
            entidades::obstaculos::Plataforma *pPlataforma = new entidades::obstaculos::Plataforma();
            entidades::obstaculos::Espinho *pEspinho = new entidades::obstaculos::Espinho();
            entidades::obstaculos::Meleca *pMeleca = new entidades::obstaculos::Meleca();
            listaObstaculos.incluir(pPlataforma);
            listaObstaculos.incluir(pEspinho);
            listaObstaculos.incluir(pMeleca);
        }





        void Fase::setGerenciadorGrafico(
            gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico
        )
        {
            pGerenciadorGrafico = r_pGerenciadorGrafico;
        }


        void Fase::exec()
        {
            if (pGerenciadorColisao)
                pGerenciadorColisao->checarColisoes();

            if (pGerenciadorGrafico)
            {
                listas::Lista<entidades::personagens::Jogador*>::Iterator itJogador;
                listas::Lista<entidades::personagens::inimigos::Inimigo*>::Iterator itInimigo;
                listas::Lista<entidades::obstaculos::Obstaculo*>::Iterator itObstaculo;

                for (itJogador = listaJogadores.begin(); itJogador != listaJogadores.end(); ++itJogador)
                {
                    if (!(*itJogador))
                        continue;

                    (*itJogador)->executar();
                    pGerenciadorGrafico->desenhar(*itJogador);
                }
                for (itInimigo = listaInimigos.begin(); itInimigo != listaInimigos.end(); ++itInimigo)
                {
                    if (!(*itInimigo))
                        continue;

                    (*itInimigo)->executar();
                    pGerenciadorGrafico->desenhar(*itInimigo);
                }
                for (itObstaculo = listaObstaculos.begin(); itObstaculo != listaObstaculos.end(); ++itObstaculo)
                {
                    if (!(*itObstaculo))
                        continue;

                    (*itObstaculo)->executar();
                    pGerenciadorGrafico->desenhar(*itObstaculo);
                }
            }
        }


    }
}
