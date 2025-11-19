

#include "gerenciadores/GerenciadorEstado.h"

#include <iostream>

#include "estados/EstadoJogo.h"
#include "estados/EstadoMenu.h"


namespace jogo {
    namespace gerenciadores {
        GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;

        GerenciadorEstado::GerenciadorEstado(): pilhaEstados() {
        }
        GerenciadorEstado *GerenciadorEstado::getGerenEstado() {
            if (pGerenciadorEstado == nullptr) {
                pGerenciadorEstado = new GerenciadorEstado();
            }
            return pGerenciadorEstado;
        }
        GerenciadorEstado::~GerenciadorEstado() {
            while (!pilhaEstados.empty()) {
                removerEstado();
            }
        }
        void GerenciadorEstado::adicionarEstado(IDs id) {
            estados::Estado* estado = nullptr;
            if (id == IDs::primeira_fase || id == IDs::segunda_fase) {
                estado = (new estados::EstadoJogo(id));
            }
            else if (id == IDs::menu_principal || id == IDs::menu_pausa) {
                estado = new estados::EstadoMenu(id);
            }
            pilhaEstados.push(estado);
        }
        void GerenciadorEstado::removerEstado() {
            if (!pilhaEstados.empty() && pilhaEstados.top()!=nullptr) {
                //delete pilhaEstados.top();
                pilhaEstados.pop();
            }
            if (pilhaEstados.empty()) {

            }
        }
        estados::Estado* GerenciadorEstado::getEstadoAtual() {
            if (!pilhaEstados.empty()) {
                return pilhaEstados.top();
            }
        }
        void GerenciadorEstado::executar() {
            if (!pilhaEstados.empty()) {
                pilhaEstados.top()->executar();
            }
        }
        void GerenciadorEstado::limparEstados() {
            while (!pilhaEstados.empty()) {
                pilhaEstados.pop();
            }



        }
    }
}
