#include <string>
#include <stdexcept>
#include "dominios.hpp"
#include "entidades.hpp"

// PROJETO
void Projeto::setCodigo(const string codigoFornecido){
    this->codigo = codigoFornecido;
}

void Projeto::setNome(const string nomeFornecido){
    this->nome = nomeFornecido;
}

void Projeto::setInicio(const Data dataFornecida){
    this->inicio = dataFornecida;
}

void Projeto::setTermino(const Data dataFornecida){
    this->termino = dataFornecida;
}

// HISTÓRIA DE USUARIO
void HistoriaDeUsuario::setCodigo(const string codigoFornecido){
    this->codigo = codigoFornecido;
}

void HistoriaDeUsuario::setTitulo(const string textoFornecido){
    this->titulo = textoFornecido;
}

void HistoriaDeUsuario::setPapel(const string textoFornecido){
    this->papel = textoFornecido;
}

void HistoriaDeUsuario::setAcao(const string textoFornecido){
    this->acao = textoFornecido;
}

void HistoriaDeUsuario::setValor(const string textoFornecido){
    this->valor = textoFornecido;
}

void HistoriaDeUsuario::setEstimativa(const string tempoFornecido){
    this->estimativa = tempoFornecido;
}

void HistoriaDeUsuario::setPrioridade(const string prioridadeFornecida){
    this->prioridade = prioridadeFornecida;
}

void HistoriaDeUsuario::setEstado(const string estadoFornecido){
    this->estado = estadoFornecido;
}
