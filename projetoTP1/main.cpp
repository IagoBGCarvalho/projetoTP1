#include <iostream>
#include <string>
#include <stdexcept>
#include "dominios/dominios.hpp"

using namespace std;

int main()
{
    // Teste de Estado
    Estado *estado = new Estado();
    string estadoDigitado;

    cout << "\nDigite o estado para verificacao: ";
    getline(cin, estadoDigitado);

    try{
        estado->setEstado(estadoDigitado);
        cout << "Deu bom! O valor do estado foi armazenado: " << estado->getEstado() << "!!" << endl;
    }
    catch(invalid_argument &ex){
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
    catch(invalid_argument &ex){
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
    catch(invalid_argument &ex){
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
    catch(invalid_argument &ex){
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
    catch(invalid_argument &ex){
        cout << ex.what() << endl;
    }

    delete senha;

    Prioridade prioridade;
    Codigo codigo;
    Nome nome;
    Tempo tempo;
    Texto texto;

    string minhaPrioridade;
    string meuCodigo;
    string meuNome;
    int meuTempo;
    string meuTexto;

    cout << "Digite sua prioridade: ";
    cin >> minhaPrioridade;

    cout << "Digite seu codigo: ";
    cin >> meuCodigo;

    cout << "Digite seu nome: ";
    getline(cin >> ws, meuNome);

    cout << "Digite seu tempo: ";
    cin >> meuTempo;

    cout << "Digite seu texto: ";
    getline(cin >> ws, meuTexto);

    //CLASS PRIORIDADE - TESTE UNITARIO
    try {
        prioridade.setPrioridade(minhaPrioridade);
        cout << "Sucesso: " << prioridade.getPrioridade() << endl;
    }
    catch (const  invalid_argument& e) {
        cerr << "Erro de validacao: " << e.what() << endl;
    }

    //CLASS CODIGO - TESTE UNITARIO
    try {
        codigo.setCodigo(meuCodigo);
        cout << "Sucesso: " << codigo.getCodigo() << endl;
    }
    catch (const  invalid_argument& e) {
        cerr << "Erro de validacao: " << e.what() << endl;
    }

    //CLASS NOME - TESTE UNITARIO
    try {
        nome.setNome(meuNome);
        cout << "Sucesso: " << nome.getNome() << endl;
    }
    catch (const  invalid_argument& e) {
        cerr << "Erro de validacao: " << e.what() << endl;
    }

    //CLASS TEMPO - TESTE UNITARIO
        try {
            tempo.setTempo(meuTempo);
            cout << "Sucesso: " << tempo.getTempo() << endl;
        }
        catch (const  invalid_argument& e) {
            cerr << "Erro de validacao: " << e.what() << endl;
        }

    //CLASS TEXTO - TESTE UNITARIO
        try {
            texto.setTexto(meuTexto);
            cout << "Sucesso: " << texto.getTexto() << endl;
        }
        catch (const  invalid_argument& e) {
            cerr << "Erro de validacao: " << e.what() << endl;
        }

    return 0;
}
