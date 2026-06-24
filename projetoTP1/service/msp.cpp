#include "msp.hpp"

void MSP::setDadosProjeto(IDPR* dados) {
    this->dadosProjeto = dados;
}

// Projeto
bool MSP::cadastrarProjeto(const Projeto& projeto) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->cadastrarProjeto(projeto);
}
bool MSP::lerProjeto(const Codigo& codigo, Projeto& projeto) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->lerProjeto(codigo, projeto);
}
bool MSP::atualizarProjeto(const Projeto& projeto) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->atualizarProjeto(projeto);
}
bool MSP::excluirProjeto(const Codigo& codigo) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->excluirProjeto(codigo);
}

// Historia
bool MSP::cadastrarHistoria(const HistoriaDeUsuario& historia) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->cadastrarHistoria(historia);
}
bool MSP::lerHistoria(const Codigo& codigo, HistoriaDeUsuario& historia) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->lerHistoria(codigo, historia);
}
bool MSP::atualizarHistoria(const HistoriaDeUsuario& historia) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->atualizarHistoria(historia);
}
bool MSP::excluirHistoria(const Codigo& codigo) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->excluirHistoria(codigo);
}

// Sprint
bool MSP::cadastrarSprint(const PlanoDeSprint& sprint) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->cadastrarSprint(sprint);
}
bool MSP::lerSprint(const Codigo& codigo, PlanoDeSprint& sprint) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->lerSprint(codigo, sprint);
}
bool MSP::atualizarSprint(const PlanoDeSprint& sprint) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->atualizarSprint(sprint);
}
bool MSP::excluirSprint(const Codigo& codigo) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->excluirSprint(codigo);
}
