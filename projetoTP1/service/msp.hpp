#ifndef MSP_HPP_INCLUDED
#define MSP_HPP_INCLUDED

#include "../interfaces/interfaces_servico.hpp"
#include "../interfaces/interfaces_dados.hpp"
#include "../entidades/entidades.hpp"

/**
 * @class MSP
 * @brief Módulo de Serviço de Projeto.
 *
 * Gerencia as regras de negócio atreladas aos Projetos, Histórias de Usuário
 * e Sprints. Depende da interface IDPR.
 */
class MSP : public ISP {
    private:
        IDPR* dadosProjeto;

    public:
        /**
         * @brief Injeta a dependência do módulo de acesso a dados de Projeto.
         * @param dados Ponteiro para a instância de IDPR.
         */
        void setDadosProjeto(IDPR* dados);

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
};

#endif // MSP_HPP_INCLUDED
