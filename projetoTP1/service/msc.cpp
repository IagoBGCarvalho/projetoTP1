#include "msc.hpp"

void MSC::setDadosPessoa(IDPE* dados) {
    this->dadosPessoa = dados;
}

bool MSC::cadastrar(const Pessoa& pessoa) {
    if (dadosPessoa == nullptr) return false;
    return dadosPessoa->cadastrar(pessoa);
}

bool MSC::ler(const Email& email, Pessoa& pessoa) {
    if (dadosPessoa == nullptr) return false;
    return dadosPessoa->ler(email, pessoa);
}

bool MSC::atualizar(const Pessoa& pessoa) {
    if (dadosPessoa == nullptr) return false;
    return dadosPessoa->atualizar(pessoa);
}

bool MSC::excluir(const Email& email) {
    if (dadosPessoa == nullptr) return false;
    return dadosPessoa->excluir(email);
}
