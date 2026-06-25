#ifndef MAA_HPP_INCLUDED
#define MAA_HPP_INCLUDED
#include "../interfaces/interfaces_apresentacao.hpp"
#include "../interfaces/interfaces_servico.hpp"
#include "../dominios/dominios.hpp"

/**
 * @class MAA
 * @brief Classe responsável pela Apresentação do Módulo de Autenticação (MAA).
 * Gerencia a tela de login via terminal e interage com a interface ISA.
 */
class MAA : public IAA {
private:
    ISA* servicoAutenticacao;
    Email emailLogado;

public:
    /**
     * @brief Construtor padrão do módulo MAA.
     */
    MAA() : servicoAutenticacao(nullptr) {}

    /**
     * @brief Executa a interação de login no terminal.
     */
    bool executar() override;

    /**
     * @brief Injeta a dependência do serviço de autenticação.
     * @param servico Ponteiro para a implementação concreta do serviço.
     */
    void setServicoAutenticacao(ISA* servico) override {
        this->servicoAutenticacao = servico;
    }

    Email getEmailLogado() const;
};

#endif // MAA_HPP_INCLUDED
