#ifndef INTERFACES_SERVICO_HPP_INCLUDED
#define INTERFACES_SERVICO_HPP_INCLUDED

#pragma once

#include <vector>

/// @file interfaces_servico.hpp
/// @brief Declara as interfaces de servico do sistema de gestao Scrum.
///
/// Este arquivo contem as classes abstratas que definem os contratos
/// entre a camada de apresentacao e a camada de servico, cobrindo
/// os 25 requisitos funcionais especificados.

class Pessoa;
class Projeto;
class HistoriaDeUsuario;
class PlanoDeSprint;
class Email;
class Senha;
class Codigo;
class Estado;

// ---------------------------------------------------------------------------

/**
 * @class ISA
 * @brief Interface de Servico de Autenticacao.
 *
 * Declara o contrato para a camada de servico responsavel por validar
 * as credenciais de acesso do usuario no sistema.
 */
class ISA {
    public:
        /**
         * @brief Autentica um usuario no sistema.
         *
         * Verifica se o par email/senha corresponde a uma conta cadastrada.
         *
         * @param email Referencia constante para o objeto do dominio Email.
         * @param senha Referencia constante para o objeto do dominio Senha.
         * @return true  Se as credenciais estiverem corretas.
         * @return false Se as credenciais forem invalidas ou a conta nao existir.
         */
        virtual bool autenticar(const Email& email, const Senha& senha) = 0;

        /**
         * @brief Destrutor virtual padrao.
         */
        virtual ~ISA() = default;
};

// ---------------------------------------------------------------------------

/**
 * @class ISC
 * @brief Interface de Servico de Cadastro.
 *
 * Declara o contrato para a gestao de contas de usuarios (Pessoa),
 * cobrindo os requisitos funcionais 1 a 4 (criar, ler, atualizar e
 * excluir pessoa).
 */
class ISC {
    public:
        /**
         * @brief Cadastra uma nova pessoa no sistema (RF 01).
         *
         * Registra um novo usuario com email, nome, senha e papel.
         * Falha se o email informado ja estiver em uso.
         *
         * @param pessoa Referencia constante para a entidade Pessoa a ser criada.
         * @return true  Se o cadastro for bem-sucedido.
         * @return false Se o email ja estiver cadastrado ou ocorrer outro erro.
         */
        virtual bool cadastrar(const Pessoa& pessoa) = 0;

        /**
         * @brief Le os dados de uma pessoa existente (RF 02).
         *
         * Recupera todos os atributos da pessoa identificada pelo email.
         *
         * @param email  Email que identifica univocamente a pessoa.
         * @param pessoa Objeto Pessoa onde os dados recuperados serao armazenados.
         * @return true  Se a pessoa for encontrada.
         * @return false Se nenhuma pessoa com o email fornecido existir.
         */
        virtual bool ler(const Email& email, Pessoa& pessoa) = 0;

        /**
         * @brief Atualiza os dados de uma pessoa (RF 03).
         *
         * Permite alterar nome, senha e papel. O email (chave primaria)
         * nao pode ser modificado.
         *
         * @param pessoa Referencia constante para a entidade Pessoa com os novos dados.
         * @return true  Se a atualizacao for bem-sucedida.
         * @return false Se a pessoa nao for encontrada.
         */
        virtual bool atualizar(const Pessoa& pessoa) = 0;

        /**
         * @brief Exclui a conta de uma pessoa (RF 04).
         *
         * Remove o registro da pessoa do sistema. A operacao falha se
         * a exclusao resultar em inconsistencias (ex.: pessoa associada
         * a historias ou projetos que ainda existem).
         *
         * @param email Email que identifica a pessoa a ser removida.
         * @return true  Se a exclusao for bem-sucedida.
         * @return false Se a pessoa nao for encontrada ou a exclusao gerar inconsistencia.
         */
        virtual bool excluir(const Email& email) = 0;

        /**
         * @brief Destrutor virtual padrao.
         */
        virtual ~ISC() = default;
};

// ---------------------------------------------------------------------------

/**
 * @class ISP
 * @brief Interface de Servico de Projeto.
 *
 * Declara o contrato para a gestao de Projetos, Historias de Usuario
 * e Planos de Sprint, cobrindo os requisitos funcionais 5 a 25.
 * Inclui operacoes de CRUD, associacoes entre entidades, listagens
 * filtradas, movimentacao de historias e alteracao de estado.
 */
class ISP {
    public:
        /**
         * @brief Cria um novo projeto no sistema (RF 05).
         *
         * Apenas o Proprietario de Produto pode criar projetos. Ao criar,
         * o projeto deve ser associado a um Mestre Scrum. A soma das
         * capacidades dos sprints do projeto nao pode exceder o numero de
         * dias entre as datas de inicio e termino.
         *
         * @param projeto Referencia constante para a entidade Projeto a ser criada.
         * @return true  Se o projeto for criado com sucesso.
         * @return false Se o codigo ja existir ou as restricoes de negocio forem violadas.
         */
        virtual bool cadastrarProjeto(const Projeto& projeto) = 0;

        /**
         * @brief Le os dados de um projeto especifico (RF 06).
         *
         * Recupera todos os atributos do projeto identificado pelo codigo.
         *
         * @param codigo  Codigo que identifica o projeto.
         * @param projeto Objeto Projeto onde os dados recuperados serao armazenados.
         * @return true  Se o projeto for encontrado.
         * @return false Se nenhum projeto com o codigo fornecido existir.
         */
        virtual bool lerProjeto(const Codigo& codigo, Projeto& projeto) = 0;

        /**
         * @brief Atualiza os dados de um projeto (RF 07).
         *
         * Permite alterar nome, datas e Mestre Scrum associado. O codigo
         * (chave primaria) nao pode ser modificado.
         *
         * @param projeto Referencia constante para o Projeto com os dados atualizados.
         * @return true  Se a atualizacao for bem-sucedida.
         * @return false Se o projeto nao for encontrado ou restricoes forem violadas.
         */
        virtual bool atualizarProjeto(const Projeto& projeto) = 0;

        /**
         * @brief Exclui um projeto do sistema (RF 08).
         *
         * A operacao falha se a exclusao resultar em inconsistencias
         * (ex.: projeto com historias ou sprints associados).
         *
         * @param codigo Codigo identificador do projeto a ser removido.
         * @return true  Se excluido com sucesso.
         * @return false Se o projeto nao for encontrado ou a exclusao gerar inconsistencia.
         */
        virtual bool excluirProjeto(const Codigo& codigo) = 0;


        /**
         * @brief Cria um novo Plano de Sprint (RF 09).
         *
         * Apenas o Mestre Scrum pode criar sprints. O sprint deve ser
         * associado a um projeto existente. A soma das capacidades de
         * todos os sprints do projeto nao pode exceder o intervalo de
         * datas do projeto.
         *
         * @param sprint Referencia constante para a entidade PlanoDeSprint a ser criada.
         * @return true  Se o sprint for criado com sucesso.
         * @return false Se restricoes de capacidade ou de existencia forem violadas.
         */
        virtual bool cadastrarSprint(const PlanoDeSprint& sprint) = 0;

        /**
         * @brief Le os dados de um Plano de Sprint especifico (RF 10).
         *
         * @param codigo Codigo identificador do Plano de Sprint.
         * @param sprint Objeto PlanoDeSprint onde os dados recuperados serao armazenados.
         * @return true  Se o sprint for encontrado.
         * @return false Se nenhum sprint com o codigo fornecido existir.
         */
        virtual bool lerSprint(const Codigo& codigo, PlanoDeSprint& sprint) = 0;

        /**
         * @brief Atualiza os dados de um Plano de Sprint (RF 11).
         *
         * Permite alterar objetivo e capacidade. O codigo (chave primaria)
         * nao pode ser modificado. A capacidade atualizada nao pode violar
         * a restricao total do projeto.
         *
         * @param sprint Referencia constante para o PlanoDeSprint com os dados atualizados.
         * @return true  Se a atualizacao for bem-sucedida.
         * @return false Se o sprint nao for encontrado ou restricoes forem violadas.
         */
        virtual bool atualizarSprint(const PlanoDeSprint& sprint) = 0;

        /**
         * @brief Exclui um Plano de Sprint (RF 12).
         *
         * A operacao falha se o sprint possuir historias associadas,
         * para evitar inconsistencias.
         *
         * @param codigo Codigo identificador do sprint a ser removido.
         * @return true  Se removido com sucesso.
         * @return false Se o sprint nao for encontrado ou tiver historias associadas.
         */
        virtual bool excluirSprint(const Codigo& codigo) = 0;


        /**
         * @brief Cria uma nova Historia de Usuario (RF 13).
         *
         * Apenas o Proprietario de Produto pode criar historias. A historia
         * deve ser associada a um projeto e criada com estado "A FAZER".
         * A descricao deve seguir o formato: papel (como...), acao
         * (eu quero...) e valor (para...).
         *
         * @param historia Referencia constante para a entidade HistoriaDeUsuario a ser criada.
         * @return true  Se criada com sucesso.
         * @return false Se o codigo ja existir ou o projeto associado nao existir.
         */
        virtual bool cadastrarHistoria(const HistoriaDeUsuario& historia) = 0;

        /**
         * @brief Le os dados de uma Historia de Usuario (RF 14).
         *
         * @param codigo  Codigo identificador da Historia de Usuario.
         * @param historia Objeto HistoriaDeUsuario onde os dados serao armazenados.
         * @return true  Se encontrada.
         * @return false Se nenhuma historia com o codigo fornecido existir.
         */
        virtual bool lerHistoria(const Codigo& codigo, HistoriaDeUsuario& historia) = 0;

        /**
         * @brief Atualiza uma Historia de Usuario (RF 15).
         *
         * Permite alterar titulo, acao, valor, estimativa e prioridade.
         * O codigo (chave primaria) nao pode ser modificado.
         *
         * @param historia Referencia constante para a HistoriaDeUsuario com dados atualizados.
         * @return true  Se a atualizacao for bem-sucedida.
         * @return false Se a historia nao for encontrada.
         */
        virtual bool atualizarHistoria(const HistoriaDeUsuario& historia) = 0;

        /**
         * @brief Exclui uma Historia de Usuario (RF 16).
         *
         * Remove a historia e todas as suas associacoes com pessoas.
         *
         * @param codigo Codigo identificador da Historia de Usuario a ser removida.
         * @return true  Se removida com sucesso.
         * @return false Se a historia nao for encontrada.
         */
        virtual bool excluirHistoria(const Codigo& codigo) = 0;

        /**
         * @brief Estabelece associacao entre uma Historia de Usuario e uma Pessoa (RF 17).
         *
         * Apenas o Mestre Scrum pode realizar esta operacao.
         * Vincula a pessoa (desenvolvedor) responsavel pela historia.
         *
         * @param codigoHistoria Codigo da Historia de Usuario.
         * @param emailPessoa    Email da Pessoa a ser associada.
         * @return true  Se a associacao for criada com sucesso.
         * @return false Se a historia ou a pessoa nao existirem, ou se a associacao ja existir.
         */
        virtual bool associarHistoriaPessoa(const Codigo& codigoHistoria,
                                            const Email&  emailPessoa) = 0;

        /**
         * @brief Remove a associacao entre uma Historia de Usuario e uma Pessoa (RF 18).
         *
         * Apenas o Mestre Scrum pode realizar esta operacao.
         *
         * @param codigoHistoria Codigo da Historia de Usuario.
         * @param emailPessoa    Email da Pessoa cuja associacao sera removida.
         * @return true  Se a associacao for removida com sucesso.
         * @return false Se a historia, a pessoa ou a associacao nao existirem.
         */
        virtual bool desassociarHistoriaPessoa(const Codigo& codigoHistoria,
                                               const Email&  emailPessoa) = 0;


        /**
         * @brief Lista os codigos dos projetos associados a uma pessoa (RF 19).
         *
         * Retorna os codigos de todos os projetos nos quais a pessoa
         * participa (como Proprietario de Produto ou Mestre Scrum).
         *
         * @param emailPessoa Email da pessoa cujos projetos serao listados.
         * @param codigos     Vetor onde os codigos dos projetos serao inseridos.
         * @return true  Se a operacao for bem-sucedida (mesmo que a lista esteja vazia).
         * @return false Se a pessoa nao existir.
         */
        virtual bool listarProjetosPorPessoa(const Email&         emailPessoa,
                                             std::vector<Codigo>& codigos) = 0;

        /**
         * @brief Lista os codigos das historias associadas a um projeto (RF 20).
         *
         * Retorna os codigos de todas as Historias de Usuario vinculadas
         * diretamente ao projeto (ainda nao movidas para um sprint).
         *
         * @param codigoProjeto Codigo do projeto.
         * @param codigos       Vetor onde os codigos das historias serao inseridos.
         * @return true  Se a operacao for bem-sucedida.
         * @return false Se o projeto nao existir.
         */
        virtual bool listarHistoriasPorProjeto(const Codigo&        codigoProjeto,
                                               std::vector<Codigo>& codigos) = 0;

        /**
         * @brief Lista os codigos dos sprints associados a um projeto (RF 21).
         *
         * @param codigoProjeto Codigo do projeto.
         * @param codigos       Vetor onde os codigos dos sprints serao inseridos.
         * @return true  Se a operacao for bem-sucedida.
         * @return false Se o projeto nao existir.
         */
        virtual bool listarSprintsPorProjeto(const Codigo&        codigoProjeto,
                                             std::vector<Codigo>& codigos) = 0;

        /**
         * @brief Lista os codigos das historias associadas a um Plano de Sprint (RF 22).
         *
         * A soma das estimativas das historias retornadas nao excede a
         * capacidade do sprint.
         *
         * @param codigoSprint Codigo do Plano de Sprint.
         * @param codigos      Vetor onde os codigos das historias serao inseridos.
         * @return true  Se a operacao for bem-sucedida.
         * @return false Se o sprint nao existir.
         */
        virtual bool listarHistoriasPorSprint(const Codigo&        codigoSprint,
                                              std::vector<Codigo>& codigos) = 0;

        /**
         * @brief Lista os codigos das historias associadas a uma pessoa (RF 23).
         *
         * Retorna os codigos de todas as Historias de Usuario as quais
         * a pessoa esta vinculada como responsavel.
         *
         * @param emailPessoa Email da pessoa.
         * @param codigos     Vetor onde os codigos das historias serao inseridos.
         * @return true  Se a operacao for bem-sucedida.
         * @return false Se a pessoa nao existir.
         */
        virtual bool listarHistoriasPorPessoa(const Email&         emailPessoa,
                                              std::vector<Codigo>& codigos) = 0;


        /**
         * @brief Move uma Historia de Usuario do backlog do projeto para um Sprint (RF 24).
         *
         * Apenas o Mestre Scrum pode realizar esta operacao. A historia
         * deve estar atualmente associada ao projeto (e nao a outro sprint).
         * A estimativa da historia somada as estimativas ja existentes no
         * sprint nao pode exceder a capacidade do sprint.
         *
         * @param codigoHistoria Codigo da Historia de Usuario a ser movida.
         * @param codigoSprint   Codigo do Plano de Sprint de destino.
         * @return true  Se a movimentacao for bem-sucedida.
         * @return false Se a historia ou o sprint nao existirem, ou se a
         *              capacidade do sprint for excedida.
         */
        virtual bool moverHistoriaParaSprint(const Codigo& codigoHistoria,
                                             const Codigo& codigoSprint) = 0;

        /**
         * @brief Altera o estado de uma Historia de Usuario (RF 25).
         *
         * Proprietario de Produto e Mestre Scrum podem realizar esta
         * operacao. Os estados validos sao: A FAZER, FAZENDO e FEITO.
         *
         * @param codigoHistoria Codigo da Historia de Usuario.
         * @param novoEstado     Novo estado a ser atribuido a historia.
         * @return true  Se o estado for alterado com sucesso.
         * @return false Se a historia nao for encontrada ou o estado for invalido.
         */
        virtual bool alterarEstadoHistoria(const Codigo& codigoHistoria,
                                           const Estado& novoEstado) = 0;

        /**
         * @brief Destrutor virtual padrao.
         */
        virtual ~ISP() = default;
};

#endif // INTERFACES_SERVICO_HPP_INCLUDED
