#include "mac.hpp"
#include "../dominios/dominios.hpp"
#include "../entidades/entidades.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

bool MAC::executar() {
    if (this->servicoCadastro == nullptr) {
        cout << "Erro interno: Servico de Cadastro nao injetado em MAC." << endl;
        return false;
    }

    string nomeDigitado, emailDigitado, senhaDigitada, papelDigitado;
    Nome nome;
    Email email;
    Senha senha;
    Papel papel;
    Pessoa novaPessoa;

    cout << "\n========================================" << endl;
    cout << "        SISTEMA SCRUM - NOVO CADASTRO     " << endl;
    cout << "========================================" << endl;

    while (true) {
        cout << "Digite seu nome (ou 'sair' para voltar): ";
        getline(cin, nomeDigitado);

        if (nomeDigitado == "sair" || nomeDigitado == "SAIR") {
            break;
        }

        cout << "Digite seu email: ";
        getline(cin, emailDigitado);

        cout << "Digite sua senha: ";
        getline(cin, senhaDigitada);

        cout << "Digite seu papel: ";
        getline(cin, papelDigitado);

        try {
            nome.setNome(nomeDigitado);
            email.setEmail(emailDigitado);
            senha.setSenha(senhaDigitada);
            papel.setPapel(papelDigitado);

            novaPessoa.setNome(nome);
            novaPessoa.setEmail(email);
            novaPessoa.setSenha(senha);
            novaPessoa.setPapel(papel);

            // Envia a entidade preenchida para a camada de negócio (Serviço)
            if (this->servicoCadastro->cadastrar(novaPessoa)) {
                cout << "\n>>> Cadastro realizado com sucesso! Cuenta criada. <<<\n" << endl;
                break;
            } else {
                cout << "\nErro no cadastro: E-mail ja cadastrado no sistema.\nTente novamente.\n" << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << "\nErro de validacao: " << e.what() << "\nPor favor, tente novamente.\n" << endl;
        }
    }
    return false;
}
