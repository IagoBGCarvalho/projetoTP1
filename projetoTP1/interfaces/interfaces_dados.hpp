#ifndef INTERFACES_DADOS_HPP_INCLUDED
#define INTERFACES_DADOS_HPP_INCLUDED

#include <vector>

class Pessoa;
class Projeto;
class HistoriaDeUsuario;
class PlanoDeSprint;
class Email;
class Senha;
class Codigo;
class Estado;

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

        /**
         * @brief Associa uma História de Usuário a uma Pessoa.
         * @param codigoHistoria Código da história.
         * @param emailPessoa Email do usuário.
         * @return true Se inserido com sucesso.
         */
        virtual bool associarHistoriaPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) = 0;

        /**
         * @brief Remove a associação entre História e Pessoa.
         * @param codigoHistoria Código da história.
         * @param emailPessoa Email do usuário.
         * @return true Se removido com sucesso.
         */
        virtual bool desassociarHistoriaPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) = 0;

        /**
         * @brief Lista códigos de projetos associados a uma Pessoa.
         * @param emailPessoa Email da pessoa.
         * @param codigos Vetor para armazenar o resultado.
         * @return true Se a consulta foi executada.
         */
        virtual bool listarProjetosPorPessoa(const Email& emailPessoa, std::vector<Codigo>& codigos) = 0;

        /**
         * @brief Lista códigos de histórias associadas a um Projeto.
         * @param codigoProjeto Código do projeto.
         * @param codigos Vetor para armazenar o resultado.
         * @return true Se a consulta foi executada.
         */
        virtual bool listarHistoriasPorProjeto(const Codigo& codigoProjeto, std::vector<Codigo>& codigos) = 0;

        /**
         * @brief Lista códigos de sprints associados a um Projeto.
         * @param codigoProjeto Código do projeto.
         * @param codigos Vetor para armazenar o resultado.
         * @return true Se a consulta foi executada.
         */
        virtual bool listarSprintsPorProjeto(const Codigo& codigoProjeto, std::vector<Codigo>& codigos) = 0;

        /**
         * @brief Lista códigos de histórias associadas a um Sprint.
         * @param codigoSprint Código do sprint.
         * @param codigos Vetor para armazenar o resultado.
         * @return true Se a consulta foi executada.
         */
        virtual bool listarHistoriasPorSprint(const Codigo& codigoSprint, std::vector<Codigo>& codigos) = 0;

        /**
         * @brief Lista códigos de histórias associadas a uma Pessoa.
         * @param emailPessoa Email da pessoa.
         * @param codigos Vetor para armazenar o resultado.
         * @return true Se a consulta foi executada.
         */
        virtual bool listarHistoriasPorPessoa(const Email& emailPessoa, std::vector<Codigo>& codigos) = 0;

        /**
         * @brief Move uma história para um sprint específico.
         * @param codigoHistoria Código da história.
         * @param codigoSprint Código do sprint de destino.
         * @return true Se a atualização ocorreu com sucesso.
         */
        virtual bool moverHistoriaParaSprint(const Codigo& codigoHistoria, const Codigo& codigoSprint) = 0;

        /**
         * @brief Altera o estado de uma História de Usuário.
         * @param codigoHistoria Código da história a ser alterada.
         * @param novoEstado Novo estado a ser aplicado.
         * @return true Se atualizado com sucesso.
         */
        virtual bool alterarEstadoHistoria(const Codigo& codigoHistoria, const Estado& novoEstado) = 0;

        virtual ~IDPR() = default;
};

#endif // INTERFACES_DADOS_HPP_INCLUDED
