#ifndef MSC_HPP_INCLUDED
#define MSC_HPP_INCLUDED

#include "../interfaces/interfaces_servico.hpp"
#include "../interfaces/interfaces_dados.hpp"
#include "../entidades/entidades.hpp"

/**
 * @class MSC
 * @brief Módulo de Serviço de Cadastro.
 *
 * Intermedeia e aplica regras de negócio às operações de CRUD de Pessoa,
 * delegando a persistência à camada de dados via interface IDPE.
 */
class MSC : public ISC {
    private:
        IDPE* dadosPessoa;

    public:
        /**
         * @brief Injeta a dependência do módulo de acesso a dados de Pessoa.
         * @param dados Ponteiro para a instância de IDPE.
         */
        void setDadosPessoa(IDPE* dados);

        bool cadastrar(const Pessoa& pessoa) override;
        bool ler(const Email& email, Pessoa& pessoa) override;
        bool atualizar(const Pessoa& pessoa) override;
        bool excluir(const Email& email) override;
};

#endif // MSC_HPP_INCLUDED
