#ifndef MD_PESSOA_HPP_INCLUDED
#define MD_PESSOA_HPP_INCLUDED

#include "../interfaces/interfaces_dados.hpp"
#include <sqlite3.h>
#include <string>

/**
 * @class MDPessoa
 * @brief Classe concreta do módulo de dados para Pessoa utilizando SQLite.
 */
class MDPessoa : public IDPE {
    private:
        sqlite3* db;
        const std::string dbName = "banco.db";

        /**
         * @brief Executa o DDL para criar a tabela se não existir.
         */
        void inicializarBanco();

    public:
        MDPessoa();
        ~MDPessoa();

        bool cadastrar(const Pessoa& pessoa) override;
        bool ler(const Email& email, Pessoa& pessoa) override;
        bool atualizar(const Pessoa& pessoa) override;
        bool excluir(const Email& email) override;
};

#endif // MD_PESSOA_HPP_INCLUDED
