#include "maa.hpp"
#include "../dominios/dominios.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Email MAA::getEmailLogado() const {
    return this->emailLogado;
}

bool MAA::executar() {
    if (this->servicoAutenticacao == nullptr) {
        cout << "Erro interno: Servico de Autenticacao nao injetado em MAA." << endl;
        return false;
    }

    string emailDigitado, senhaDigitada;
    Email email;
    Senha senha;

    while (true) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "========================================" << endl;
        cout << "          SISTEMA SCRUM - LOGIN         " << endl;
        cout << "========================================" << endl;
        cout << "Digite seu email (ou 'sair' para voltar): ";
        getline(cin, emailDigitado);

        if (emailDigitado == "sair" || emailDigitado == "SAIR") {
            break;
        }

        cout << "Digite sua senha: ";
        getline(cin, senhaDigitada);

        try {
            email.setEmail(emailDigitado);
            senha.setSenha(senhaDigitada);

            if (this->servicoAutenticacao->autenticar(email, senha)) {
                cout << "\n>>> Login efetuado com sucesso! Bem-vindo(a). <<<\n" << endl;

                this->emailLogado = email;
                return true;
            } else {
                cout << "\nErro: E-mail ou senha incorretos no banco de dados." << endl;
                cout << "Pressione ENTER para tentar novamente.";
                cin.get();
            }
        }
        catch (const invalid_argument& e) {
            cout << "\nErro de formatacao: " << e.what() << endl;
            cout << "Pressione ENTER para tentar novamente.";
            cin.get();
        }
    }
    return false;
}
