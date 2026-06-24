#ifndef INTERFACES_DADOS_HPP_INCLUDED
#define INTERFACES_DADOS_HPP_INCLUDED

#include "../entidades/entidades.hpp"

/**
 * @class IDPE
 * @brief Interface de Dados de Pessoa.
 *
 * Contrato obrigatório para as operações de persistência (CRUD)
 * da entidade Pessoa no banco de dados.
 */
class IDPE {
    public:
        virtual bool cadastrar(const Pessoa& pessoa) = 0;
        virtual bool ler(const Email& email, Pessoa& pessoa) = 0;
        virtual bool atualizar(const Pessoa& pessoa) = 0;
        virtual bool excluir(const Email& email) = 0;
        virtual ~IDPE() = default;
};

/**
 * @class IDPR
 * @brief Interface de Dados de Projeto.
 *
 * Contrato obrigatório para as operações de persistência (CRUD)
 * das entidades Projeto, HistoriaDeUsuario e PlanoDeSprint.
 */
class IDPR {
    public:
        // CRUD Projeto
        virtual bool cadastrarProjeto(const Projeto& projeto) = 0;
        virtual bool lerProjeto(const Codigo& codigo, Projeto& projeto) = 0;
        virtual bool atualizarProjeto(const Projeto& projeto) = 0;
        virtual bool excluirProjeto(const Codigo& codigo) = 0;

        // CRUD HistoriaDeUsuario
        virtual bool cadastrarHistoria(const HistoriaDeUsuario& historia) = 0;
        virtual bool lerHistoria(const Codigo& codigo, HistoriaDeUsuario& historia) = 0;
        virtual bool atualizarHistoria(const HistoriaDeUsuario& historia) = 0;
        virtual bool excluirHistoria(const Codigo& codigo) = 0;

        // CRUD PlanoDeSprint
        virtual bool cadastrarSprint(const PlanoDeSprint& sprint) = 0;
        virtual bool lerSprint(const Codigo& codigo, PlanoDeSprint& sprint) = 0;
        virtual bool atualizarSprint(const PlanoDeSprint& sprint) = 0;
        virtual bool excluirSprint(const Codigo& codigo) = 0;

        virtual ~IDPR() = default;
};

#endif // INTERFACES_DADOS_HPP_INCLUDED
