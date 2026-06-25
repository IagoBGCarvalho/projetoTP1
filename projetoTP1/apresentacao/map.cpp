#include "map.hpp"
#include "../entidades/entidades.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

bool MAP::executar(const Email& emailUsuarioLogado) {
    if (this->servicoProjeto == nullptr) {
        cout << "Erro interno: Servico de Projeto nao injetado." << endl;
    }

    string codigoDigitado, nomeDigitado;
    Codigo codigo;
    Nome nome;
    Projeto novoProjeto;

    cout << "\n========================================" << endl;
    cout << "   SISTEMA SCRUM - GESTAO DE PROJETOS   " << endl;
    cout << " Utilizador logado: " << emailUsuarioLogado.getEmail() << endl; // Mostra de quem é a sessão
    cout << "========================================" << endl;

    while (true) {
        cout << "Digite o codigo do novo projeto (ou 'sair' para voltar): ";
        getline(cin, codigoDigitado);

        if (codigoDigitado == "sair" || codigoDigitado == "SAIR") {
            break;
        }

        cout << "Digite o nome do projeto: ";
        getline(cin, nomeDigitado);

        try {
            codigo.setCodigo(codigoDigitado);
            nome.setNome(nomeDigitado);

            novoProjeto.setCodigo(codigo);
            novoProjeto.setNome(nome);

            if (this->servicoProjeto->cadastrarProjeto(novoProjeto)) {
                cout << "\n>>> Projeto registado com sucesso! <<<\n" << endl;
                break;
            } else {
                cout << "\nErro: O codigo introduzido ja pertence a outro projeto.\n" << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << "\nErro de formatacao: " << e.what() << "\nPor favor, introduza os dados corretamente.\n" << endl;
        }
    }
    return false;
}
