#include "dominios/dominios.hpp"
#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

using namespace std;

class Projeto{
    private:
        Codigo codigo; //PK
        Nome nome;
        Data inicio;
        Data termino;
    public:
        void setCodigo(Codigo);
        Codigo getCodigo();

        void setNome(Nome);
        Nome getNome();

        void setInicio(Data);
        Data getInicio();

        void setTermino(Data);
        Data getTermino();
};

inline string Projeto::getCodigo(){
    return codigo.getCodigo();
}

inline string Projeto::getNome(){
    return nome.getNome();
}

inline string Projeto::getInicio(){
    return inicio.getData();
}

inline string Projeto::getTermino(){
    return termino.getData();
}

class HistoriaDeUsuario(){
    private:
        Codigo codigo; // PK
        Texto titulo;
        Texto papel;
        Texto acao;
        Texto valor;
        Tempo estimativa;
        Prioridade prioridade;
        Estado estado;
    public:
        void setCodigo(Codigo);
        Codigo getCodigo();

        void setTitulo(Texto);
        Texto getTitulo();

        void setPapel(Texto);
        Texto getPapel();

        void setAcao(Texto);
        Texto getAcao();

        void setValor(Texto);
        Texto getValor();

        void setTempo(Tempo);
        Tempo getTempo();

        void setPrioridade(Prioridade);
        Prioridade getPrioridade();

        void setEstado(Estado);
        Estado getEstado();
};

inline string HistoriaDeUsuario::getCodigo(){
    return codigo.getCodigo();
}

inline string HistoriaDeUsuario::getTitulo(){
    return titulo.getTexto();
}

inline string HistoriaDeUsuario::getPapel(){
    return papel.getTexto();
}

inline string HistoriaDeUsuario::getAcao(){
    return acao.getTexto();
}

inline string HistoriaDeUsuario::getValor(){
    return valor.getTexto();
}

inline string HistoriaDeUsuario::getTempo(){
    return tempo.getTempo();
}

inline string HistoriaDeUsuario::getPrioridade(){
    return prioridade.getPrioridade();
}

inline string HistoriaDeUsuario::getEstado(){
    return estado.getEstado();
}

#endif // ENTIDADES_HPP_INCLUDED
