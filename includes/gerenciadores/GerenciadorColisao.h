#ifndef JOGO_COLISION_H
#define JOGO_COLISION_H

#include <vector>
#include <list>
#include <set>

#include "listas/Lista.h"
#include "entidades/personagens/Jogador.h"
#include "entidades/personagens/inimigos/Inimigo.h"
#include "entidades/obstaculos/Obstaculo.h"
#include "entidades/Projetil.h"


namespace jogo {
    namespace gerenciadores {
        class GerenciadorColisao {
        private:
            std::vector<entidades::personagens::Jogador *> listaJogadores;
            std::vector<entidades::personagens::inimigos::Inimigo *> listaInimigos;
            std::list<entidades::obstaculos::Obstaculo *> listaObstaculos;
            std::set<entidades::Projetil *> listaProjeteis;

        private:
            static float calcOverlapHor(entidades::Entidade *ent1, entidades::Entidade *ent2, float gap = 0);

            static float calcOverlapVert(entidades::Entidade *ent1, entidades::Entidade *ent2);

            bool colidiuHor(entidades::Entidade *ent1, entidades::Entidade *ent2, float gap = 0);

            bool colidiuVert(entidades::Entidade *ent1, entidades::Entidade *ent2);

            bool colidiu(entidades::Entidade *ent1, entidades::Entidade *ent2);

            void checarObstaculo_InimigosColisao(entidades::obstaculos::Obstaculo *pObstaculo);

            void checarObstaculo_JogadoresColisao(entidades::obstaculos::Obstaculo *pObstaculo);

            void checarObstaculo_ProjeteisColisao(entidades::obstaculos::Obstaculo *pObstaculo);

            void checarInimigo_JogadoresColisao(entidades::personagens::inimigos::Inimigo *pInimigo);

            void checarProjeteis_JogadoresColisao(entidades::Projetil *pProjetil);

        public:
            GerenciadorColisao(
            );

            ~GerenciadorColisao();

            static sf::Vector2f calcOverlap(entidades::Entidade *ent1, entidades::Entidade *ent2);

            void checarColisoes();

            void checarObstaculoColisoes();

            void checarInimigoColisoes();

            void checarProjeteisColisoes();

            void incluirJogador(entidades::personagens::Jogador *jog);

            void incluirInimigo(entidades::personagens::inimigos::Inimigo *pInimigo);

            void incluirObstaculo(entidades::obstaculos::Obstaculo *pObstaculo);

            void incluirProjetil(entidades::Projetil *pProjetil);

            void retirarJogador(entidades::personagens::Jogador *pJogador);

            void retirarInimigo(entidades::personagens::inimigos::Inimigo *pInimigo);

            void retirarProjetil(entidades::Projetil *pProjetil);
        };
    }
}


#endif //JOGO_COLISION_H