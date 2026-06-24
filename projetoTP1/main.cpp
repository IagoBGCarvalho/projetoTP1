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

using namespace std;

int main() {
    cout << "===========================================" << endl;
    cout << "   TESTE DE INTEGRACAO: SERVICO E DADOS    " << endl;
    cout << "===========================================" << endl;

    // Instanciando a Camada de Dados e criando o banco
    MDPessoa* mdPessoa = new MDPessoa();
    MDProjeto* mdProjeto = new MDProjeto();

    // Instanciando a Camada de Serviço
    MSA* servicoAutenticacao = new MSA();
    MSC* servicoCadastro = new MSC();
    MSP* servicoProjeto = new MSP();

    // Injeção de Dependência (Ligando Serviço aos Dados)
    servicoAutenticacao->setDadosPessoa(mdPessoa);
    servicoCadastro->setDadosPessoa(mdPessoa);
    servicoProjeto->setDadosProjeto(mdProjeto);

    try {
        cout << "\n--- Testando Cadastro de Pessoa (MSC) ---" << endl;
        Pessoa usuario;

        Email email; email.setEmail("iago@unb.br");
        Nome nome; nome.setNome("Iago");
        Senha senha; senha.setSenha("A1b2C3");
        Papel papel; papel.setPapel("DESENVOLVEDOR");

        usuario.setEmail(email);
        usuario.setNome(nome);
        usuario.setSenha(senha);
        usuario.setPapel(papel);

        if (servicoCadastro->cadastrar(usuario)) {
            cout << "[SUCESSO] Usuario cadastrado no banco de dados!" << endl;
        } else {
            cout << "[FALHA] Nao foi possivel cadastrar. (O email ja existe?)" << endl;
        }

        cout << "\n--- Testando Autenticacao (MSA) ---" << endl;
        if (servicoAutenticacao->autenticar(email, senha)) {
            cout << "[SUCESSO] Autenticacao realizada com a senha correta!" << endl;
        } else {
            cout << "[FALHA] Autenticacao rejeitada." << endl;
        }

        Senha senhaIncorreta; senhaIncorreta.setSenha("X1y2Z3");
        if (!servicoAutenticacao->autenticar(email, senhaIncorreta)) {
            cout << "[SUCESSO] O sistema bloqueou o login com senha errada!" << endl;
        } else {
            cout << "[FALHA] O sistema aceitou uma senha errada." << endl;
        }

        cout << "\n--- Testando Cadastro de Projeto (MSP) ---" << endl;
        Projeto projeto;

        Codigo codProj; codProj.setCodigo("PR013");
        Nome nomeProj; nomeProj.setNome("Sentinela");
        Data dataIni; dataIni.setData("10/05/2026");
        Data dataFim; dataFim.setData("20/12/2026");

        projeto.setCodigo(codProj);
        projeto.setNome(nomeProj);
        projeto.setInicio(dataIni);
        projeto.setTermino(dataFim);

        if (servicoProjeto->cadastrarProjeto(projeto)) {
            cout << "[SUCESSO] Projeto salvo no banco de dados!" << endl;
        } else {
            cout << "[FALHA] Nao foi possivel salvar o projeto." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n[ERRO DE VALIDACAO] Os dados de teste sao invalidos: " << e.what() << endl;
    }

    delete servicoAutenticacao;
    delete servicoCadastro;
    delete servicoProjeto;
    delete mdPessoa;
    delete mdProjeto;

    cout << "\nTestes finalizados." << endl;
    return 0;
}
