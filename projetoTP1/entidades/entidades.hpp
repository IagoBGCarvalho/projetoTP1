#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "../dominios/dominios.hpp"

using namespace std;

/**
 * @class Projeto
 * @brief Entidade que representa um Projeto no sistema.
 *
 * Agrupa as informações fundamentais de um projeto, sendo unicamente
 * identificado por um Código (Chave Primária). Comporta também o Nome
 * do projeto e o seu período de duração (Data de início e Data de término).
 */
class Projeto{
    private:
        Codigo codigo; //PK
        Nome nome;
        Data inicio;
        Data termino;
    public:
        /**
         * @brief Define o código identificador do projeto.
         * @param codigo Instância válida do domínio Codigo.
         */
        void setCodigo(Codigo);
        /**
         * @brief Retorna o código identificador do projeto.
         * @return Instância do domínio Codigo armazenada.
         */
        Codigo getCodigo() const;

        /**
         * @brief Define o nome do projeto.
         * @param nome Instância válida do domínio Nome.
         */
        void setNome(Nome);
        /**
         * @brief Retorna o nome do projeto.
         * @return Instância do domínio Nome armazenada.
         */
        Nome getNome() const;

        /**
         * @brief Define a data de início do projeto.
         * @param inicio Instância válida do domínio Data.
         */
        void setInicio(Data);
        /**
         * @brief Retorna a data de início do projeto.
         * @return Instância do domínio Data armazenada.
         */
        Data getInicio() const;

        /**
         * @brief Define a data de término do projeto.
         * @param termino Instância válida do domínio Data.
         */
        void setTermino(Data);
        /**
         * @brief Retorna a data de término do projeto.
         * @return Instância do domínio Data armazenada.
         */
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

/**
 * @class HistoriaDeUsuario
 * @brief Entidade que representa uma História de Usuário.
 *
 * Uma História de Usuário documenta um requisito ou funcionalidade do
 * sistema. É unicamente identificada por um Código e detalha o título, 
 * o papel de quem executa a ação, a ação em si, o valor agregado, 
 * a estimativa de tempo, o nível de prioridade e o estado atual de 
 * desenvolvimento.
 */
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
        /**
         * @brief Define o código identificador da história de usuário.
         * @param codigo Instância válida do domínio Codigo.
         */
        void setCodigo(Codigo);
        /**
         * @brief Retorna o código da história de usuário.
         * @return Instância do domínio Codigo armazenada.
         */
        Codigo getCodigo() const;

        /**
         * @brief Define o título da história de usuário.
         * @param titulo Instância válida do domínio Texto.
         */
        void setTitulo(Texto);
        /**
         * @brief Retorna o título da história de usuário.
         * @return Instância do domínio Texto armazenada.
         */
        Texto getTitulo() const;

        /**
         * @brief Define o papel associado à história de usuário.
         * @param papel Instância válida do domínio Texto.
         */
        void setPapel(Texto);
        /**
         * @brief Retorna o papel da história de usuário.
         * @return Instância do domínio Texto armazenada.
         */
        Texto getPapel() const;

        /**
         * @brief Define a ação descrita na história de usuário.
         * @param acao Instância válida do domínio Texto.
         */
        void setAcao(Texto);
        /**
         * @brief Retorna a ação da história de usuário.
         * @return Instância do domínio Texto armazenada.
         */
        Texto getAcao() const;

        /**
         * @brief Define o valor ou benefício da história de usuário.
         * @param valor Instância válida do domínio Texto.
         */
        void setValor(Texto);
        /**
         * @brief Retorna o valor da história de usuário.
         * @return Instância do domínio Texto armazenada.
         */
        Texto getValor() const;

        /**
         * @brief Define a estimativa de tempo para a história de usuário.
         * @param estimativa Instância válida do domínio Tempo.
         */
        void setEstimativa(Tempo);
        /**
         * @brief Retorna a estimativa de tempo da história de usuário.
         * @return Instância do domínio Tempo armazenada.
         */
        Tempo getEstimativa() const;

        /**
         * @brief Define a prioridade da história de usuário.
         * @param prioridade Instância válida do domínio Prioridade.
         */
        void setPrioridade(Prioridade);
        /**
         * @brief Retorna a prioridade da história de usuário.
         * @return Instância do domínio Prioridade armazenada.
         */
        Prioridade getPrioridade() const;

        /**
         * @brief Define o estado atual da história de usuário.
         * @param estado Instância válida do domínio Estado.
         */
        void setEstado(Estado);
        /**
         * @brief Retorna o estado atual da história de usuário.
         * @return Instância do domínio Estado armazenada.
         */
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
