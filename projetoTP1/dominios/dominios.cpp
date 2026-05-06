#include <string>
#include <stdexcept>
#include <cctype>
#include <regex>
#include "dominios.hpp"

// CODIGO
void Codigo::validar(string codigoFornecido){
    if (codigoFornecido.length() != 5) {
        throw invalid_argument("Código deve ter 5 caracteres.");
    }

    for (int i = 0; i < 2; i++) {
        if (!isupper(codigoFornecido[i])) {
            throw invalid_argument("Os dois primeiros caracteres devem ser letras maiuscular");
        }
    }

    for (int i = 2; i < 5; i++) {
        if (!isdigit(codigoFornecido[i])) {
            throw invalid_argument("Os tres ultimos caracteres devem ser numeros.");
        }
    }
}

void Codigo::setCodigo(string codigoFornecido) {
    validar(codigoFornecido);
    this->valor = codigoFornecido;
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

// NOME
void Nome::validar(string nomeFornecido){
    if (nomeFornecido.length() == 0 || nomeFornecido.length() > 10) {
        throw invalid_argument("O nome deve ter entre 1 e 10 caracteres.");
    }

    if (nomeFornecido[0] == ' ') {
        throw invalid_argument("O primeiro digito nao pode ser espaco.");
    }

    if (nomeFornecido[nomeFornecido.length() - 1] == ' ') {
        throw invalid_argument("O ultimo caractere nao pode ser espaco");
    }

    for (size_t i = 0; i < nomeFornecido.length(); i++) {
        if (!isalpha(nomeFornecido[i]) && nomeFornecido[i] != ' ') {
            throw invalid_argument("Caracter pode ser letra maiuscula (A-Z), letra minuscula (a-z) ou espaco em branco");
        }

        if (nomeFornecido[i] == ' ') {
            if (i < nomeFornecido.length() - 1){
                if (!isalpha(nomeFornecido[i + 1])) {
                    throw invalid_argument("Espaco em branco deve ser seguido por letra.");
                }
            }
        }
    }
}

void Nome::setNome(string nomeFornecido){
    validar(nomeFornecido);
    this->valor = nomeFornecido;
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

//Class Prioridade
void Prioridade::validar(string prioridadeFornecida){
    if (prioridadeFornecida != "ALTA" && prioridadeFornecida != "MEDIA" && prioridadeFornecida != "BAIXA"){
        throw invalid_argument("Prioridade invalida. Use ALTA, MEDIA ou BAIXA.");
    }
}

void Prioridade::setPrioridade(string prioridadeFornecida){
    validar(prioridadeFornecida);
    this->valor = valor;
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

//CLASS TEMPO
void Tempo::validar(int tempoFornecido) {
    if (tempoFornecido < 1 || tempoFornecido > 365) {
        throw invalid_argument("O valor deve ser entre 1 a 365.");
    }
}

void Tempo::setTempo(int valor) {
    validar(valor);
    this->valor = valor;
}


//CLASS TEXTO
void Texto::validar(string textoFornecido) {
    if (textoFornecido.length() == 0 || textoFornecido.length() > 40) {
        throw invalid_argument("O texto deve ter entre 1 a 40 caracteres.");
    }

    if (textoFornecido[0] == ',' || textoFornecido[0] =='.' || textoFornecido[0] == ' ') {
        throw invalid_argument("Primeiro caracter nao pode ser virgula, ponto ou espaco em branco.");
    }

    if (textoFornecido[textoFornecido.length() - 1] == ',' || textoFornecido[textoFornecido.length() - 1] == '.' || textoFornecido[textoFornecido.length() - 1] == ' ') {
        throw invalid_argument("Ultimo caracter nao pode ser virgula, ponto ou espaco em branco.");
    }

    for (size_t i = 0; i < textoFornecido.length(); i++) {
        if (!isalnum(textoFornecido[i]) && textoFornecido[i] != ',' && textoFornecido[i] != '.' && textoFornecido[i] != ' ') {
            throw invalid_argument("Caracter pode ser letra (a-z ou A-Z), digito(0-9), virgula, ponto ou espaco em branco.");
        }

        if (i < textoFornecido.length() - 1){
            if (textoFornecido[i] == ',' || textoFornecido[i] == '.') {
                if(textoFornecido[i + 1] == ',' || textoFornecido[i + 1] == '.') {
                    throw invalid_argument("Vírgula não pode ser seguida por vírgula ou ponto e ponto não pode ser seguido por vírgula ou ponto.");
                }
            }

            if (textoFornecido[i] == ' ') {
                if (!isalnum(textoFornecido[i + 1])) {
                    throw invalid_argument("Espaco em branco deve ser seguido por letra ou digito.");
                }
            }
        }
    }
}

void Texto::setTexto(string textoFornecido) {
    validar(textoFornecido);
    this->valor = valor;
}
