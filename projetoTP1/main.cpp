#include <iostream>
#include <string>
#include <stdexcept>
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

using namespace std;

int main()
{
    // TESTES DE DOMÍNIOS
    cout << "TESTES DE DOMÍNIOS\n";

    // Teste de Estado
    Estado *estado = new Estado();
    string estadoDigitado;

    cout << "\nDigite o estado para verificacao: ";
    getline(cin, estadoDigitado);

    try{
        estado->setEstado(estadoDigitado);
        cout << "Deu bom! O valor do estado foi armazenado: " << estado->getEstado() << "!!" << endl;
    }
    catch(const invalid_argument &ex){
        cout << ex.what();
    }

    delete estado;

    // Teste de Papel
    Papel *papel = new Papel();
    string papelDigitado;

    cout << "\nDigite o papel para verificacao: ";
    getline(cin, papelDigitado);

    try{
        papel->setPapel(papelDigitado);
        cout << "Deu bom! O valor do papel foi armazenado: " << papel->getPapel() << "!!" << endl;
    }
    catch(const invalid_argument &ex){
        cout << ex.what();
    }

    delete papel;

    // Teste de Data
    Data *data = new Data();
    string dataDigitada;

    cout << "\nDigite a data para verificacao (DD/MM/ANO): ";
    getline(cin, dataDigitada);

    try{
        data->setData(dataDigitada);
        cout << "Deu bom! O valor da data foi armazenado: " << data->getData() << "!!" << endl;
    }
    catch(const invalid_argument &ex){
        cout << ex.what() << endl;
    }

    delete data;

    // Teste de Email
    Email *email = new Email();
    string emailDigitado;

    cout << "\nDigite o email para verificacao (parte-local@domínio): ";
    getline(cin, emailDigitado);

    try{
        email->setEmail(emailDigitado);
        cout << "Deu bom! O valor do email foi armazenado: " << email->getEmail() << "!!" << endl;
    }
    catch(const invalid_argument &ex){
        cout << ex.what() << endl;
    }

    delete email;

    // Teste de Senha
    Senha *senha = new Senha();
    string senhaDigitada;

    cout << "\nDigite a senha para verificacao: ";
    getline(cin, senhaDigitada);

    try{
        senha->setSenha(senhaDigitada);
        cout << "Deu bom! O valor da senha foi armazenado: " << senha->getSenha() << "!!" << endl;
    }
    catch(const invalid_argument &ex){
        cout << ex.what() << endl;
    }

    delete senha;

    // Teste de prioridade
    Prioridade *prioridade = new Prioridade();
    string minhaPrioridade;

    cout << "\nDigite sua prioridade: ";
    getline(cin, minhaPrioridade);

    try {
        prioridade->setPrioridade(minhaPrioridade);
        cout << "Sucesso: " << prioridade->getPrioridade() << endl;
    }
    catch (const invalid_argument &ex) {
        cerr << "Erro de validacao: " << ex.what() << endl;
    }

    delete prioridade;

    //Teste de codigo
    Codigo *codigo = new Codigo();
    string meuCodigo;

    cout << "\nDigite seu codigo: ";
    getline(cin, meuCodigo);

    try {
        codigo->setCodigo(meuCodigo);
        cout << "Sucesso: " << codigo->getCodigo() << endl;
    }
    catch (const invalid_argument &ex) {
        cerr << "Erro de validacao: " << ex.what() << endl;
    }

    delete codigo;

    // Teste de nome
    Nome *nome = new Nome();
    string meuNome;

    cout << "\nDigite seu nome: ";
    getline(cin, meuNome);

    try {
        nome->setNome(meuNome);
        cout << "Sucesso: " << nome->getNome() << endl;
    }
    catch (const invalid_argument &ex) {
        cerr << "Erro de validacao: " << ex.what() << endl;
    }

    delete nome;

    // Teste de tempo
    Tempo *tempo = new Tempo();
    int meuTempo;

    cout << "\nDigite seu tempo: ";
    cin >> meuTempo;

    try {
        tempo->setTempo(meuTempo);
        cout << "Sucesso: " << tempo->getTempo() << endl;
    }
    catch (const invalid_argument &ex) {
        cerr << "Erro de validacao: " << ex.what() << endl;
    }

    delete tempo;

    // Teste de tempo
    Texto *texto = new Texto();
    string meuTexto;

    cout << "\nDigite seu texto: ";
    getline(cin >> ws, meuTexto);

    try {
        texto->setTexto(meuTexto);
        cout << "Sucesso: " << texto->getTexto() << endl;
    }
    catch (const invalid_argument &ex) {
        cerr << "Erro de validacao: " << ex.what() << endl;
    }

    delete texto;

    // TESTES DE ENTIDADES
    cout << "TESTES DE ENTIDADES\n";

    //TESTE ENTIDADE PROJETO
    Projeto *projeto = new Projeto();

    // Criando os domínios necessários para o projeto
    Codigo codigoProjeto;
    Nome nomeProjeto;
    Data inicioProjeto;
    Data terminoProjeto;

    try {
        // Simulando dados válidos
        codigoProjeto.setCodigo("PR013");
        nomeProjeto.setNome("Sentinela");
        inicioProjeto.setData("10/05/2026");
        terminoProjeto.setData("20/12/2026");

        // Associando os domínios à entidade Projeto
        projeto->setCodigo(codigoProjeto);
        projeto->setNome(nomeProjeto);
        projeto->setInicio(inicioProjeto);
        projeto->setTermino(terminoProjeto);

        cout << "\n[PROJETO] Criado com sucesso!" << endl;
        cout << "-> Codigo: " << projeto->getCodigo().getCodigo() << endl; // get: Entidade -> Dominio -> Tipo Primitivo
        cout << "-> Nome: " << projeto->getNome().getNome() << endl;
        cout << "-> Inicio: " << projeto->getInicio().getData() << endl;
        cout << "-> Termino: " << projeto->getTermino().getData() << endl;

    } catch (const invalid_argument &ex) {
        cout << "\nErro na validacao de dominio para o Projeto: " << ex.what() << endl;
    }

    delete projeto;

    //TESTE ENTIDADE HISTORIA DE USUARIO
    HistoriaDeUsuario *historia = new HistoriaDeUsuario();

    Codigo codHistoria;
    Texto tituloHistoria;
    Texto papelHistoria;
    Texto acaoHistoria;
    Texto valorHistoria;
    Tempo estimativaHistoria;
    Prioridade prioridadeHistoria;
    Estado estadoHistoria;

    try {
        codHistoria.setCodigo("HU001");
        tituloHistoria.setTexto("Login no Sistema");
        papelHistoria.setTexto("Administrador");
        acaoHistoria.setTexto("Autenticar com email e senha");
        valorHistoria.setTexto("Acessar dados restritos");
        estimativaHistoria.setTempo(5);
        prioridadeHistoria.setPrioridade("ALTA");
        estadoHistoria.setEstado("A FAZER");

        historia->setCodigo(codHistoria);
        historia->setTitulo(tituloHistoria);
        historia->setPapel(papelHistoria);
        historia->setAcao(acaoHistoria);
        historia->setValor(valorHistoria);
        historia->setEstimativa(estimativaHistoria);
        historia->setPrioridade(prioridadeHistoria);
        historia->setEstado(estadoHistoria);

        cout << "\n[HISTORIA DE USUARIO] Criada com sucesso!" << endl;
        cout << "-> Titulo: " << historia->getTitulo().getTexto() << endl;
        cout << "-> Papel: " << historia->getPapel().getTexto() << endl;
        cout << "-> Estado Atual: " << historia->getEstado().getEstado() << endl;
        cout << "-> Prioridade: " << historia->getPrioridade().getPrioridade() << endl;

    } catch (const invalid_argument &ex) {
        cout << "\nErro na validacao de dominio para a Historia: " << ex.what() << endl;
    }

    delete historia;

    //TESTE ENTIDADE PESSOA
    Pessoa *pessoa = new Pessoa();

    Email emailPessoa;
    Nome nomePessoa;
    Senha senhaPessoa;
    Papel papelPessoa;

    try {
        emailPessoa.setEmail("email.teste@unb.br");
        nomePessoa.setNome("Fulano");
        senhaPessoa.setSenha("A1b2C3"); 
        papelPessoa.setPapel("DESENVOLVEDOR");

        pessoa->setEmail(emailPessoa);
        pessoa->setNome(nomePessoa);
        pessoa->setSenha(senhaPessoa);
        pessoa->setPapel(papelPessoa);

        cout << "\n[PESSOA] Criada com sucesso!" << endl;
        cout << "-> Email: " << pessoa->getEmail().getEmail() << endl; 
        cout << "-> Nome: " << pessoa->getNome().getNome() << endl;
        cout << "-> Senha: " << pessoa->getSenha().getSenha() << endl;
        cout << "-> Papel: " << pessoa->getPapel().getPapel() << endl;

    } catch (const invalid_argument &ex) {
        cout << "\nErro na validacao de dominio para a Pessoa: " << ex.what() << endl;
    }

    delete pessoa;

    //TESTE ENTIDADE PLANO DE SPRINT
    PlanoDeSprint *plano = new PlanoDeSprint();

    Codigo codigoPlano;
    Texto objetivoPlano;
    Tempo capacidadePlano;

    try {
        codigoPlano.setCodigo("PL123"); 
        objetivoPlano.setTexto("Finalizar as classes de dominio");
        capacidadePlano.setTempo(14); 

        plano->setCodigo(codigoPlano);
        plano->setObjetivo(objetivoPlano);
        plano->setCapacidade(capacidadePlano);

        cout << "\n[PLANO DE SPRINT] Criado com sucesso!" << endl;
        cout << "-> Codigo: " << plano->getCodigo().getCodigo() << endl;
        cout << "-> Objetivo: " << plano->getObjetivo().getTexto() << endl;
        cout << "-> Capacidade: " << plano->getCapacidade().getTempo() << endl;

    } catch (const invalid_argument &ex) {
        cout << "\nErro na validacao de dominio para o Plano de Sprint: " << ex.what() << endl;
    }

    delete plano;

    return 0;
}
