//
// Created by mvmko on 18/11/2025.
//

#ifndef JOGO_GERENCIADORESTADO_H
#define JOGO_GERENCIADORESTADO_H

#include <stack>
#include "estados/Estado.h"




namespace jogo {
    namespace gerenciadores {

        class GerenciadorEstado {
        private:
            std::stack<estados::Estado*> pilhaEstados;
            static GerenciadorEstado* pGerenciadorEstado;
            GerenciadorEstado();

        public:
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenEstado();
            void executar();
            void adicionarEstado(IDs id, int numJogadores = 1, IDs r_fase = IDs::primeira_fase, bool continuar = false);
            void removerEstado();

            estados::Estado* getEstadoAtual();
            void limparEstados();
        };

    }
}
#endif //JOGO_GERENCIADORESTADO_H