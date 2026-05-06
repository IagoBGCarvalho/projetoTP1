#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "../dominios/dominios.hpp"

using namespace std;

class Projeto{
    private:
        Codigo codigo; //PK
        Nome nome;
        Data inicio;
        Data termino;
    public:
        void setCodigo(Codigo);
        Codigo getCodigo() const;

        void setNome(Nome);
        Nome getNome() const;

        void setInicio(Data);
        Data getInicio() const;

        void setTermino(Data);
        Data getTermino() const;
};

inline Codigo Projeto::getCodigo() const{
    return codigo;
}

inline Nome Projeto::getNome() const{
    return nome;
}

inline Data Projeto::getInicio() const{
    return inicio;
}

inline Data Projeto::getTermino() const{
    return termino;
}

class HistoriaDeUsuario{
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
        Codigo getCodigo() const;

        void setTitulo(Texto);
        Texto getTitulo() const;

        void setPapel(Texto);
        Texto getPapel() const;

        void setAcao(Texto);
        Texto getAcao() const;

        void setValor(Texto);
        Texto getValor() const;

        void setEstimativa(Tempo);
        Tempo getEstimativa() const;

        void setPrioridade(Prioridade);
        Prioridade getPrioridade() const;

        void setEstado(Estado);
        Estado getEstado() const;
};

inline Codigo HistoriaDeUsuario::getCodigo() const{
    return codigo;
}

inline Texto HistoriaDeUsuario::getTitulo() const{
    return titulo;
}

inline Texto HistoriaDeUsuario::getPapel() const{
    return papel;
}

inline Texto HistoriaDeUsuario::getAcao() const{
    return acao;
}

inline Texto HistoriaDeUsuario::getValor() const{
    return valor;
}

inline Tempo HistoriaDeUsuario::getEstimativa() const{
    return estimativa;
}

inline Prioridade HistoriaDeUsuario::getPrioridade() const{
    return prioridade;
}

inline Estado HistoriaDeUsuario::getEstado() const{
    return estado;
}

#endif // ENTIDADES_HPP_INCLUDED
