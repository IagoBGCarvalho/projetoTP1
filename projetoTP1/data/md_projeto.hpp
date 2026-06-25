#ifndef MD_PROJETO_HPP_INCLUDED
#define MD_PROJETO_HPP_INCLUDED

#include "../interfaces/interfaces_dados.hpp"
#include "../sqlite3.h"
#include <string>
#include <vector>

/**
 * @class MDProjeto
 * @brief Módulo de dados para operações de Projeto, História e Sprint utilizando SQLite.
 */
class MDProjeto : public IDPR {
    private:
        sqlite3* db;
        const std::string dbName = "banco.db";

        /**
         * @brief Executa o DDL para criar a tabela se não existir.
         */
        void inicializarBanco();

    public:
        MDProjeto();
        ~MDProjeto();

        bool cadastrarProjeto(const Projeto& projeto) override;
        bool lerProjeto(const Codigo& codigo, Projeto& projeto) override;
        bool atualizarProjeto(const Projeto& projeto) override;
        bool excluirProjeto(const Codigo& codigo) override;

        bool cadastrarHistoria(const HistoriaDeUsuario& historia) override;
        bool lerHistoria(const Codigo& codigo, HistoriaDeUsuario& historia) override;
        bool atualizarHistoria(const HistoriaDeUsuario& historia) override;
        bool excluirHistoria(const Codigo& codigo) override;

        bool cadastrarSprint(const PlanoDeSprint& sprint) override;
        bool lerSprint(const Codigo& codigo, PlanoDeSprint& sprint) override;
        bool atualizarSprint(const PlanoDeSprint& sprint) override;
        bool excluirSprint(const Codigo& codigo) override;

        bool associarHistoriaPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) override;
        bool desassociarHistoriaPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) override;
        bool listarProjetosPorPessoa(const Email& emailPessoa, std::vector<Codigo>& codigos) override;
        bool listarHistoriasPorProjeto(const Codigo& codigoProjeto, std::vector<Codigo>& codigos) override;
        bool listarSprintsPorProjeto(const Codigo& codigoProjeto, std::vector<Codigo>& codigos) override;
        bool listarHistoriasPorSprint(const Codigo& codigoSprint, std::vector<Codigo>& codigos) override;
        bool listarHistoriasPorPessoa(const Email& emailPessoa, std::vector<Codigo>& codigos) override;
        bool moverHistoriaParaSprint(const Codigo& codigoHistoria, const Codigo& codigoSprint) override;
        bool alterarEstadoHistoria(const Codigo& codigoHistoria, const Estado& novoEstado) override;
};

#endif // MD_PROJETO_HPP_INCLUDED
