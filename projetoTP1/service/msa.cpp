#include "msa.hpp"

void MSA::setDadosPessoa(IDPE* dados) {
    this->dadosPessoa = dados;
}

bool MSA::autenticar(const Email& email, const Senha& senha) {
    // Proteção contra falha de injeção
    if (dadosPessoa == nullptr) return false;

    Pessoa pessoaRecuperada;

    // Regra de Negócio: Tenta ler a pessoa do banco de dados pelo e-mail
    if (dadosPessoa->ler(email, pessoaRecuperada)) {
        // Se a pessoa existe, compara a senha fornecida com a senha do banco
        if (pessoaRecuperada.getSenha().getSenha() == senha.getSenha()) {
            return true; // Autenticado com sucesso
        }
    }

    return false; // E-mail não encontrado ou senha incorreta
}
