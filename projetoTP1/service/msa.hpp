#ifndef MSA_HPP_INCLUDED
#define MSA_HPP_INCLUDED

#include "../interfaces/interfaces_servico.hpp"
#include "../interfaces/interfaces_dados.hpp"
#include "../entidades/entidades.hpp"

/**
 * @class MSA
 * @brief Módulo de Serviço de Autenticação.
 *
 * Implementa a regra de negócio para validar o acesso de um usuário.
 * Depende da interface IDPE para buscar os dados de persistência.
 */
class MSA : public ISA {
    private:
        IDPE* dadosPessoa; // Ponteiro para a interface de dados

    public:
        /**
         * @brief Injeta a dependência do módulo de acesso a dados de Pessoa.
         * @param dados Ponteiro para a instância concreta de IDPE (ex: MDPessoa).
         */
        void setDadosPessoa(IDPE* dados);

        bool autenticar(const Email& email, const Senha& senha) override;
};

#endif // MSA_HPP_INCLUDED
