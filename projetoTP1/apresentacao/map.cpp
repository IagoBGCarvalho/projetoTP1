#include "map.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

using namespace std;

bool MAP::executar(const Email& emailUsuarioLogado) {
    if (this->servicoProjeto == nullptr) {
        cout << "Erro interno: Servico de Projeto nao injetado." << endl;
        return false;
    }

    string opcao;
    bool deslogar = false;

    while (!deslogar) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "========================================" << endl;
        cout << "   SISTEMA SCRUM - GESTAO DE PROJETOS   " << endl;
        cout << " Utilizador logado: " << emailUsuarioLogado.getEmail() << endl;
        cout << "========================================" << endl;
        cout << " 1 - Criar Novo Projeto" << endl;
        cout << " 2 - Listar/Gerenciar Projetos (Em breve)" << endl;
        cout << " 3 - Logout (Sair da conta)" << endl;
        cout << "========================================" << endl;
        cout << "Escolha uma opcao: ";

        getline(cin, opcao);

        if (opcao == "1") {
            string codigoDigitado, nomeDigitado;
            Codigo codigo;
            Nome nome;
            Projeto novoProjeto;

            cout << "\n--- NOVO PROJETO ---" << endl;
            cout << "Digite o codigo do novo projeto (ou 'sair' para cancelar): ";
            getline(cin, codigoDigitado);

            if (codigoDigitado == "sair" || codigoDigitado == "SAIR") {
                continue;
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
                } else {
                    cout << "\nErro: O codigo introduzido ja pertence a outro projeto.\n" << endl;
                }
            }
            catch (const invalid_argument& e) {
                cout << "\nErro de formatacao: " << e.what() << "\nPor favor, introduza os dados corretamente.\n" << endl;
            }

            cout << "Pressione ENTER para voltar ao menu.";
            cin.get();

        }
        else if (opcao == "2") {
            cout << "\nModulo em desenvolvimento..." << endl;
            cout << "Pressione ENTER para voltar ao menu.";
            cin.get();
        }
        else if (opcao == "3") {
            cout << "\nRealizando logout... Ate logo!\n" << endl;
            deslogar = true;
        }
        else {
            cout << "\nOpcao invalida! Pressione ENTER para tentar novamente." << endl;
            cin.get();
        }
    }

    return false;
}
