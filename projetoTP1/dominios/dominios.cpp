#include <string>
#include "dominios.hpp"

// Constantes da classe ESTADO
const string Estado::AFAZER = "A FAZER";
const string Estado::FAZENDO = "FAZENDO";
const string Estado::FEITO = "FEITO";

bool Estado::validar(string estadoFornecido){
    if(estadoFornecido == AFAZER || estadoFornecido == FAZENDO || estadoFornecido == FEITO)
        return true;
    return false;
}

bool Estado::setEstado(string estadoFornecido){
    if(!validar(estadoFornecido))
       return false;

    this->estadoAtual = estadoFornecido;
    return true;
}
