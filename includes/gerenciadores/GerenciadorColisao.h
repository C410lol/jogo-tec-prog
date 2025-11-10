#ifndef JOGO_COLISION_H
#define JOGO_COLISION_H

#include "listas/Lista.h"
#include "entidades/personagens/Jogador.h"
#include "entidades/personagens/inimigos/Inimigo.h"
#include "entidades/obstaculos/Obstaculo.h"




namespace jogo {
    namespace gerenciadores {

        class GerenciadorColisao
        {
        private:
            listas::Lista<entidades::personagens::Jogador*> *pListaJogadores;
            listas::Lista<entidades::personagens::inimigos::Inimigo*> *pListaInimigos;
            listas::Lista<entidades::obstaculos::Obstaculo*> *pListaObstaculos;
        private:
            static float calcOverlapHor(entidades::Entidade *ent1, entidades::Entidade *ent2, float gap = 0);
            static float calcOverlapVert(entidades::Entidade *ent1, entidades::Entidade *ent2);

            bool colidiuHor(entidades::Entidade *ent1, entidades::Entidade *ent2, float gap = 0);
            bool colidiuVert(entidades::Entidade *ent1, entidades::Entidade *ent2);
            bool colidiu(entidades::Entidade *ent1, entidades::Entidade *ent2);

            void checarObstaculo_InimigosColisao(entidades::obstaculos::Obstaculo *pObstaculo);
            void checarObstaculo_JogadoresColisao(entidades::obstaculos::Obstaculo *pObstaculo);

            void checarInimigo_JogadoresColisao(entidades::personagens::inimigos::Inimigo *pInimigo);

        public:
            GerenciadorColisao(
                listas::Lista<entidades::personagens::Jogador*> *r_pListaJogadores,
                listas::Lista<entidades::personagens::inimigos::Inimigo*> *r_pListaInimigos,
                listas::Lista<entidades::obstaculos::Obstaculo*> *r_pListaObstaculos
            );
            ~GerenciadorColisao();

            static sf::Vector2f calcOverlap(entidades::Entidade *ent1, entidades::Entidade *ent2);

            void checarColisoes();

            void checarObstaculoColisoes();
            void checarInimigoColisoes();
        };

    }
}




#endif //JOGO_COLISION_H