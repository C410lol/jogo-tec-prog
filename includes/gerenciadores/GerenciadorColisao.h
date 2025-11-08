#ifndef JOGO_COLISION_H
#define JOGO_COLISION_H

#include <list>

#include "listas/Lista.h"
#include "entidades/personagens/Jogador.h"
#include "entidades/personagens/inimigos/Inimigo.h"
#include "entidades/obstaculos/Obstaculo.h"




namespace jogo {
    namespace gerenciadores {

        class GerenciadorColisao
        {
        private:
            entidades::personagens::Jogador* pJog1;
            std::vector<entidades::personagens::inimigos::Inimigo*> pListaInimigos;
            std::list<entidades::obstaculos::Obstaculo*> pListaObstaculos;
        private:
            static float calcOverlapHor(entidades::Entidade *ent1, entidades::Entidade *ent2);
            static float calcOverlapVert(entidades::Entidade *ent1, entidades::Entidade *ent2);

            bool colidiuHor(entidades::Entidade *ent1, entidades::Entidade *ent2);
            bool colidiuVert(entidades::Entidade *ent1, entidades::Entidade *ent2);
            bool colidiu(entidades::Entidade *ent1, entidades::Entidade *ent2);

            void checarObstaculo_InimigosColisao(entidades::obstaculos::Obstaculo *pObstaculo);
            void checarObstaculo_JogadoresColisao(entidades::obstaculos::Obstaculo *pObstaculo);

            void checarInimigo_JogadoresColisao(entidades::personagens::inimigos::Inimigo *pInimigo);

        public:
            GerenciadorColisao(
            );
            ~GerenciadorColisao();

            static sf::Vector2f calcOverlap(entidades::Entidade *ent1, entidades::Entidade *ent2);

            void checarColisoes();

            void checarObstaculoColisoes();
            void checarInimigoColisoes();
            void incluirJogador(entidades::personagens::Jogador* jog);
            void incluirInimigo(entidades::personagens::inimigos::Inimigo* pInimigo);
            void incluirObstaculo(entidades::obstaculos::Obstaculo* pObstaculo);
            entidades::personagens::Jogador* const getJogador();
        };

    }
}




#endif //JOGO_COLISION_H