#ifndef INTERFACES_APRESENTACAO_H_INCLUDED
#define INTERFACES_APRESENTACAO_H_INCLUDED

#pragma once
#include "interfaces_servico.hpp"
#include "../dominios/dominios.hpp"

class Email;

/**
 * @class IAA
 * @brief Interface de Apresentação de Autenticação.
 *
 * Responsável por declarar o contrato para a interação com o utilizador
 * no ecrã de login/autenticação.
 */
class IAA {
    public:
        /**
         * @brief Inicia o fluxo de interação com o utilizador para autenticação.
         * @return true Se o utilizador for autenticado com sucesso.
         * @return false Se o utilizador cancelar ou falhar a autenticação.
         */
        virtual bool executar() = 0;

        /**
         * @brief Estabelece a ligação (injeção de dependência) com a camada de serviço.
         * @param servico Ponteiro para a instância do Serviço de Autenticação (ISA).
         */
        virtual void setServicoAutenticacao(ISA* servico) = 0;

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~IAA() = default;
};

/**
 * @class IAC
 * @brief Interface de Apresentação de Cadastro.
 *
 * Responsável por declarar o contrato para a interação com o utilizador
 * nos ecrãs de registo e gestão de conta.
 */
class IAC {
    public:
        /**
         * @brief Inicia o fluxo de interação do menu de gestão de utilizadores.
         */
        virtual bool executar() = 0;

        /**
         * @brief Estabelece a ligação (injeção de dependência) com a camada de serviço.
         * @param servico Ponteiro para a instância do Serviço de Cadastro (ISC).
         */
        virtual void setServicoCadastro(ISC* servico) = 0;

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~IAC() = default;
};

/**
 * @class IAP
 * @brief Interface de Apresentação de Projeto.
 *
 * Responsável por declarar o contrato para a interação com o utilizador
 * nos ecrãs de manipulação de Projetos, Histórias e Sprints.
 */
class IAP {
    public:
        /**
         * @brief Inicia o fluxo de interação do menu de projetos.
         * @param emailUsuarioLogado Referência para o email do utilizador atual,
         * permitindo filtrar e gerir apenas os projetos associados a este.
         */
        virtual bool executar(const Email& emailUsuarioLogado) = 0;

        /**
         * @brief Estabelece a ligação (injeção de dependência) com a camada de serviço.
         * @param servico Ponteiro para a instância do Serviço de Projeto (ISP).
         */
        virtual void setServicoProjeto(ISP* servico) = 0;
        virtual void setServicoCadastro(ISC* servico) = 0;

        /**
         * @brief Destrutor virtual padrão.
         */
        virtual ~IAP() = default;
};

#endif // INTERFACES_APRESENTACAO_H_INCLUDED
