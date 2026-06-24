#ifndef INTERFACES_SERVICO_HPP_INCLUDED
#define INTERFACES_SERVICO_HPP_INCLUDED

#pragma once

//Entidades
class Pessoa;
class Projeto;
class HistoriaDeUsuario;
class PlanoDeSprint;

//Dominios usados como parâmetros
class Email;
class Senha;
class Codigo;

/**
 * @class ISA
 * @brief Interface de Serviço de Autenticação.
 *
 * Declara o contrato para a camada de serviço responsável por validar
 * as credenciais de acesso do utilizador no sistema.
 */
class ISA {
    public:
        /**
         * @brief Autentica um utilizador no sistema.
         * * @param email Referência constante para o objeto do domínio Email.
         * @param senha Referência constante para o objeto do domínio Senha.
         * @return true Se as credenciais estiverem corretas.
         * @return false Se as credenciais forem inválidas.
         */
        virtual bool autenticar(const Email& email, const Senha& senha) = 0;

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~ISA() = default;
};

/**
 * @class ISC
 * @brief Interface de Serviço de Cadastro.
 *
 * Declara o contrato para a gestão de contas (registo, leitura,
 * atualização e remoção de dados de utilizadores).
 */
class ISC {
    public:
        /**
         * @brief Cadastra uma nova pessoa no sistema.
         * @param pessoa Referência constante para a entidade Pessoa a ser criada.
         * @return true Se o cadastro for bem-sucedido.
         * @return false Se ocorrer um erro (ex: email já registado).
         */
        virtual bool cadastrar(const Pessoa& pessoa) = 0;

        /**
         * @brief Lê os dados de uma pessoa existente.
         * @param email Email que identifica a pessoa.
         * @param pessoa Objeto onde os dados recuperados serão guardados.
         * @return true Se a pessoa for encontrada.
         * @return false Se a pessoa não existir na base de dados.
         */
        virtual bool ler(const Email& email, Pessoa& pessoa) = 0;

        /**
         * @brief Atualiza os dados de uma pessoa.
         * @param pessoa Referência constante para a entidade Pessoa com os novos dados.
         * @return true Se a atualização for bem-sucedida.
         * @return false Se a pessoa não for encontrada.
         */
        virtual bool atualizar(const Pessoa& pessoa) = 0;

        /**
         * @brief Exclui a conta de uma pessoa.
         * @param email Email que identifica a pessoa a ser removida.
         * @return true Se a exclusão for bem-sucedida.
         * @return false Se a pessoa não for encontrada.
         */
        virtual bool excluir(const Email& email) = 0;

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~ISC() = default;
};

/**
 * @class ISP
 * @brief Interface de Serviço de Projeto.
 *
 * Declara o contrato para a gestão de Projetos, Histórias de Utilizador e Sprints,
 * permitindo operações de CRUD para cada uma destas entidades.
 */
class ISP {
    public:
        // CRUD de Projeto

        /**
         * @brief Cria um novo projeto no sistema.
         * @param projeto Referência constante para a entidade Projeto.
         * @return true Se o projeto for criado com sucesso.
         * @return false Caso ocorra um erro na criação.
         */
        virtual bool cadastrarProjeto(const Projeto& projeto) = 0;

        /**
         * @brief Lê os dados de um projeto específico.
         * @param codigo Código que identifica o projeto.
         * @param projeto Objeto onde os dados serão guardados.
         * @return true Se o projeto for encontrado.
         * @return false Se o projeto não for encontrado.
         */
        virtual bool lerProjeto(const Codigo& codigo, Projeto& projeto) = 0;

        /**
         * @brief Atualiza os dados de um projeto.
         * @param projeto Referência constante para o Projeto modificado.
         * @return true Se atualizado com sucesso.
         * @return false Caso não seja possível atualizar.
         */
        virtual bool atualizarProjeto(const Projeto& projeto) = 0;

        /**
         * @brief Exclui um projeto do sistema.
         * @param codigo Código identificador do projeto a remover.
         * @return true Se excluído com sucesso.
         * @return false Se o projeto não for encontrado.
         */
        virtual bool excluirProjeto(const Codigo& codigo) = 0;

        // CRUD de Historia

        /**
         * @brief Cria uma nova História de Utilizador.
         * @param historia Referência constante para a entidade Historia.
         * @return true Se criada com sucesso.
         * @return false Em caso de falha.
         */
        virtual bool cadastrarHistoria(const HistoriaDeUsuario& historia) = 0;

        /**
         * @brief Lê os dados de uma História de Utilizador.
         * @param codigo Código identificador da História.
         * @param historia Objeto onde os dados serão armazenados.
         * @return true Se encontrada.
         * @return false Caso não exista.
         */
        virtual bool lerHistoria(const Codigo& codigo, HistoriaDeUsuario& historia) = 0;

        /**
         * @brief Atualiza uma História de Utilizador.
         * @param historia Referência constante para a História modificada.
         * @return true Se a atualização for bem-sucedida.
         * @return false Se ocorrer um erro.
         */
        virtual bool atualizarHistoria(const HistoriaDeUsuario& historia) = 0;

        /**
         * @brief Exclui uma História de Utilizador.
         * @param codigo Código identificador da História a remover.
         * @return true Se removida com sucesso.
         * @return false Se a História não for encontrada.
         */
        virtual bool excluirHistoria(const Codigo& codigo) = 0;

        // CRUD de PlanoDeSprint

        /**
         * @brief Cria um novo Sprint.
         * @param sprint Referência constante para a entidade Sprint.
         * @return true Se criado com sucesso.
         * @return false Caso contrário.
         */
        virtual bool cadastrarSprint(const PlanoDeSprint& sprint) = 0;

        /**
         * @brief Lê os dados de um Sprint.
         * @param codigo Código identificador do Sprint.
         * @param sprint Objeto onde os dados serão armazenados.
         * @return true Se encontrado.
         * @return false Se não existir.
         */
        virtual bool lerSprint(const Codigo& codigo, PlanoDeSprint& sprint) = 0;

        /**
         * @brief Atualiza os dados de um Sprint.
         * @param sprint Referência constante para o Sprint modificado.
         * @return true Se atualizado com sucesso.
         * @return false Em caso de falha.
         */
        virtual bool atualizarSprint(const PlanoDeSprint& sprint) = 0;

        /**
         * @brief Exclui um Sprint.
         * @param codigo Código identificador do Sprint a remover.
         * @return true Se a remoção for bem-sucedida.
         * @return false Se o Sprint não for encontrado.
         */
        virtual bool excluirSprint(const Codigo& codigo) = 0;

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~ISP() = default;
};

#endif // INTERFACES_SERVICO_HPP_INCLUDED
