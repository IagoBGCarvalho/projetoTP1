#include <string>
#include <stdexcept>
#include <cctype>
#include <regex>
#include "dominios.hpp"

// ESTADO
const string Estado::A_FAZER = "A FAZER";
const string Estado::FAZENDO = "FAZENDO";
const string Estado::FEITO = "FEITO";

void Estado::validar(string estadoFornecido){
    if((estadoFornecido != A_FAZER) && (estadoFornecido != FAZENDO) && (estadoFornecido != FEITO)){
        throw invalid_argument("Argumento invalido para ESTADO");
    }
}

void Estado::setEstado(string estadoFornecido){
    validar(estadoFornecido);
    this->valor = estadoFornecido;
}

// PAPEL
const string Papel::DESENVOLVEDOR = "DESENVOLVEDOR";
const string Papel::MESTRE_SCRUM = "MESTRE SCRUM";
const string Papel::PROPRIETARIO_DE_PRODUTO = "PROPRIETARIO DE PRODUTO";

void Papel::validar(string papelFornecido){
    if((papelFornecido != DESENVOLVEDOR) && (papelFornecido != MESTRE_SCRUM) && (papelFornecido != PROPRIETARIO_DE_PRODUTO)){
        throw invalid_argument("Argumento invalido para PAPEL");
    }
}

void Papel::setPapel(string papelFornecido){
    validar(papelFornecido);
    this->valor = papelFornecido;
}

// DATA
bool Data::isBissexto(int ano){
    if(ano % 400 == 0) return true;
    if(ano % 100 == 0) return false;
    return (ano % 4 == 0);
}

void Data::validar(string dataFornecida){
    // Tamanho
    if(dataFornecida.length() != 10){
        throw invalid_argument("Formato de data invalido");
    }

    // Formatacao
    if(dataFornecida[2] != '/' || dataFornecida[5] != '/'){
        throw invalid_argument("Formato de data invalido");
    }

    // Digitos
    for(int i = 0; i < 10; i++){
        if(i == 2 || i == 5) continue; // Pula as barras
        if(!isdigit(dataFornecida[i])){
            throw invalid_argument("Formato de data invalido");
        }
    }

    int dia = stoi(dataFornecida.substr(0,2));
    int mes = stoi(dataFornecida.substr(3,2));
    int ano = stoi(dataFornecida.substr(6,4));

    // Limites de ano e mes
    if(ano < 2000 || ano > 2999){
        throw invalid_argument("Ano fora do limite permitido (2000-2999)");
    }
    if(mes < 1 || mes > 12){
        throw invalid_argument("Mes invalido");
    }

    int diasNoMes[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isBissexto(ano)) {
        // Atualiza fevereiro
        diasNoMes[2] = 29;
    }

    if (dia < 1 || dia > diasNoMes[mes]) {
        throw invalid_argument("Dia invalido para o mes/ano especificado");
    }
}

void Data::setData(string dataFornecida) {
    validar(dataFornecida);
    this->valor = dataFornecida;
}

// EMAIL
void Email::validar(string emailFornecido) {
    int posArroba = emailFornecido.find('@');
    if (posArroba == string::npos || emailFornecido.find('@', posArroba + 1) != string::npos) {
        throw invalid_argument("Email invalido: deve conter exatamente um @.");
    }

    string parteLocal = emailFornecido.substr(0, posArroba);
    string dominio = emailFornecido.substr(posArroba + 1);

    if (parteLocal.length() == 0 || parteLocal.length() > 64) {
        throw invalid_argument("Email invalido: parte local deve ter entre 1 e 64 caracteres.");
    }
    if (dominio.length() == 0 || dominio.length() > 255) {
        throw invalid_argument("Email invalido: dominio deve ter entre 1 e 255 caracteres.");
    }

    // Parte local: a-z, 0-9, . e - (nao inicia/termina com . ou -, sem consecutivos)
    regex padraoLocal("^[a-z0-9]+([.-][a-z0-9]+)*$");
    if (!regex_match(parteLocal, padraoLocal)) {
        throw invalid_argument("Email invalido: formato da parte local incorreto.");
    }

    // Dominio: partes separadas por ponto, contendo a-z, 0-9 e - (nao inicia/termina com hifen)
    regex padraoDominio("^[a-z0-9]+(-[a-z0-9]+)*(\\.[a-z0-9]+(-[a-z0-9]+)*)*$");
    if (!regex_match(dominio, padraoDominio)) {
        throw invalid_argument("Email invalido: formato do dominio incorreto.");
    }
}

void Email::setEmail(string emailFornecido) {
    validar(emailFornecido);
    this->valor = emailFornecido;
}

// SENHA
void Senha::validar(string senhaFornecida) {
    // Tamanho
    if (senhaFornecida.length() != 6) {
        throw invalid_argument("Senha invalida: deve conter exatamente 6 caracteres.");
    }

    bool temMaiuscula = false;
    bool temMinuscula = false;
    bool temDigito = false;

    for (int i = 0; i < 6; i++) {
        char c = senhaFornecida[i];

        // Alfanumerico?
        if (!isalnum(c)) {
            throw invalid_argument("Senha invalida: contem caracteres nao permitidos.");
        }

        if (isupper(c)) temMaiuscula = true;
        if (islower(c)) temMinuscula = true;
        if (isdigit(c)) temDigito = true;

        // Alternancia
        if (i < 5) {
            char proximo = senhaFornecida[i + 1];

            if (isalpha(c) && isalpha(proximo)) {
                throw invalid_argument("Senha invalida: uma letra nao pode ser seguida por outra letra.");
            }
            if (isdigit(c) && isdigit(proximo)) {
                throw invalid_argument("Senha invalida: um digito nao pode ser seguido por outro digito.");
            }
        }
    }

    // Obrigatoriedades
    if (!temMaiuscula || !temMinuscula || !temDigito) {
        throw invalid_argument("Senha invalida: deve conter pelo menos uma maiuscula, uma minuscula e um digito.");
    }
}

void Senha::setSenha(string senhaFornecida) {
    validar(senhaFornecida);
    this->valor = senhaFornecida;
}
