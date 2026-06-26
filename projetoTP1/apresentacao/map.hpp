#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED
#include "../interfaces/interfaces_apresentacao.hpp"
#include "../interfaces/interfaces_servico.hpp"
#include "../dominios/dominios.hpp"
#include "../entidades/entidades.hpp"

/**
 * @class MAP
 * @brief Classe responsável pela Apresentação do Módulo de Projeto (MAP).
 * Gerencia o menu de criação e visualização de projetos via terminal.
 */
class MAP : public IAP {
private:
    ISP* servicoProjeto;
    ISC* servicoCadastro;
    void menuProjetos(const Email& emailUsuarioLogado);
    void menuSprints(const Email& emailUsuarioLogado);
    void menuHistorias(const Email& emailUsuarioLogado);
    bool menuPessoa(const Email& emailUsuarioLogado);

public:
    /**
     * @brief Construtor padrão do módulo MAP.
     */
    MAP() : servicoProjeto(nullptr) {}

    /**
     * @brief Executa o menu de projetos no terminal.
     */
    bool executar(const Email& emailUsuarioLogado) override;

    /**
     * @brief Injeta a dependência do serviço de projeto.
     * @param servico Ponteiro para a implementação concreta do serviço.
     */
    void setServicoProjeto(ISP* servico) override {
        this->servicoProjeto = servico;
    }

    void setServicoCadastro(ISC* servico) override {
        this->servicoCadastro = servico;
    }
};

#endif // MAP_HPP_INCLUDED
