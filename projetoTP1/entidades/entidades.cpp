#include <string>
#include <stdexcept>
#include "../dominios/dominios.hpp"
#include "entidades.hpp"

// PROJETO
void Projeto::setCodigo(const Codigo& codigoFornecido){
    this->codigo = codigoFornecido;
}

void Projeto::setNome(const Nome& nomeFornecido){
    this->nome = nomeFornecido;
}

void Projeto::setInicio(const Data& dataFornecida){
    this->inicio = dataFornecida;
}

void Projeto::setTermino(const Data& dataFornecida){
    this->termino = dataFornecida;
}

// HISTÓRIA DE USUARIO
void HistoriaDeUsuario::setCodigo(const Codigo& codigoFornecido){
    this->codigo = codigoFornecido;
}

void HistoriaDeUsuario::setTitulo(const Texto& textoFornecido){
    this->titulo = textoFornecido;
}

void HistoriaDeUsuario::setPapel(const Texto& textoFornecido){
    this->papel = textoFornecido;
}

void HistoriaDeUsuario::setAcao(const Texto& textoFornecido){
    this->acao = textoFornecido;
}

void HistoriaDeUsuario::setValor(const Texto& textoFornecido){
    this->valor = textoFornecido;
}

void HistoriaDeUsuario::setEstimativa(const Tempo& tempoFornecido){
    this->estimativa = tempoFornecido;
}

void HistoriaDeUsuario::setPrioridade(const Prioridade& prioridadeFornecida){
    this->prioridade = prioridadeFornecida;
}

void HistoriaDeUsuario::setEstado(const Estado& estadoFornecido){
    this->estado = estadoFornecido;
}

// PESSOA

void Pessoa::setEmail(const Email& emailFornecido) {
    this->email = emailFornecido;
}

void Pessoa::setNome(const Nome& nomeFornecido) {
    this->nome = nomeFornecido;
}

void Pessoa::setSenha(const Senha& senhaFornecida) {
    this->senha = senhaFornecida;
}

void Pessoa::setPapel(const Papel& papelFornecido) {
    this->papel = papelFornecido;
}

// PLANO DE SPRINT
void PlanoDeSprint::setCodigo(const Codigo& codigoFornecido) {
    this->codigo = codigoFornecido;
}

void PlanoDeSprint::setObjetivo(const Texto& objetivoFornecido) {
    this->objetivo = objetivoFornecido;
}

void PlanoDeSprint::setCapacidade(const Tempo& capacidadeFornecida) {
    this->capacidade = capacidadeFornecida;
}