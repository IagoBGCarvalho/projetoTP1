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

bool MSP::associarHistoriaPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->associarHistoriaPessoa(codigoHistoria, emailPessoa);
}

bool MSP::desassociarHistoriaPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->desassociarHistoriaPessoa(codigoHistoria, emailPessoa);
}

bool MSP::listarProjetosPorPessoa(const Email& emailPessoa, std::vector<Codigo>& codigos) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->listarProjetosPorPessoa(emailPessoa, codigos);
}

bool MSP::listarHistoriasPorProjeto(const Codigo& codigoProjeto, std::vector<Codigo>& codigos) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->listarHistoriasPorProjeto(codigoProjeto, codigos);
}

bool MSP::listarSprintsPorProjeto(const Codigo& codigoProjeto, std::vector<Codigo>& codigos) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->listarSprintsPorProjeto(codigoProjeto, codigos);
}

bool MSP::listarHistoriasPorSprint(const Codigo& codigoSprint, std::vector<Codigo>& codigos) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->listarHistoriasPorSprint(codigoSprint, codigos);
}

bool MSP::listarHistoriasPorPessoa(const Email& emailPessoa, std::vector<Codigo>& codigos) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->listarHistoriasPorPessoa(emailPessoa, codigos);
}

bool MSP::moverHistoriaParaSprint(const Codigo& codigoHistoria, const Codigo& codigoSprint) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->moverHistoriaParaSprint(codigoHistoria, codigoSprint);
}

bool MSP::alterarEstadoHistoria(const Codigo& codigoHistoria, const Estado& novoEstado) {
    if (dadosProjeto == nullptr) return false;
    return dadosProjeto->alterarEstadoHistoria(codigoHistoria, novoEstado);
}
