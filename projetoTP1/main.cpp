#include <iostream>
#include <string>
#include <stdexcept>
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"
#include "data/md_pessoa.hpp"
#include "data/md_projeto.hpp"
#include "service/msa.hpp"
#include "service/msc.hpp"
#include "service/msp.hpp"
#include "apresentacao/maa.hpp"
#include "apresentacao/mac.hpp"
#include "apresentacao/map.hpp"

using namespace std;

int main() {
    MDPessoa* mdPessoa = new MDPessoa();
    MDProjeto* mdProjeto = new MDProjeto();

    MSA* servicoAutenticacao = new MSA();
    MSC* servicoCadastro = new MSC();
    MSP* servicoProjeto = new MSP();

    servicoAutenticacao->setDadosPessoa(mdPessoa);
    servicoCadastro->setDadosPessoa(mdPessoa);
    servicoProjeto->setDadosProjeto(mdProjeto);

    MAA* apresentacaoAutenticacao = new MAA();
    IAC* apresentacaoCadastro = new MAC();
    IAP* apresentacaoProjeto = new MAP();

    apresentacaoAutenticacao->setServicoAutenticacao(servicoAutenticacao);
    apresentacaoCadastro->setServicoCadastro(servicoCadastro);
    apresentacaoProjeto->setServicoProjeto(servicoProjeto);

    string opcao;
    bool autenticado = false;
    Email emailLogado;

    while (!autenticado) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "===========================================" << endl;
        cout << "          SISTEMA SCRUM INICIADO           " << endl;
        cout << "===========================================" << endl;
        cout << "\n1 - Login" << endl;
        cout << "2 - Cadastrar-se" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma opcao: ";

        cin >> opcao;
        cin.ignore(256, '\n');

        if (opcao == "1") {
            if (apresentacaoAutenticacao->executar()) {
                autenticado = true;
                emailLogado = apresentacaoAutenticacao->getEmailLogado();

                cout << "\nPressione ENTER para ir para o painel de Projetos." << endl;
                cin.get();
            }
        }
        else if (opcao == "2") {
            apresentacaoCadastro->executar();
            cout << "\nPressione ENTER para voltar ao menu e fazer Login." << endl;
            cin.get();
        }
        else if (opcao == "3") {
            cout << "\nEncerrando sistema..." << endl;
            goto cleanup;
        }
        else {
            cout << "\nOpcao invalida! Pressione ENTER para tentar novamente." << endl;
            cin.get();
        }
    }

    if (autenticado) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        apresentacaoProjeto->executar(emailLogado);
    }

cleanup:
    delete apresentacaoAutenticacao;
    delete apresentacaoCadastro;
    delete apresentacaoProjeto;
    delete servicoAutenticacao;
    delete servicoCadastro;
    delete servicoProjeto;
    delete mdPessoa;
    delete mdProjeto;

    return 0;
}
