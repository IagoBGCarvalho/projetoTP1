#ifndef MAC_HPP_INCLUDED
#define MAC_HPP_INCLUDED
#include "../interfaces/interfaces_apresentacao.hpp"
#include "../interfaces/interfaces_servico.hpp"

/**
 * @class MAC
 * @brief Classe respons�vel pela Apresenta��o do M�dulo de Cadastro (MAC).
 * Coleta os dados do terminal para criar uma nova conta de usu�rio.
 */
class MAC : public IAC {
private:
    ISC* servicoCadastro;

public:
    /**
     * @brief Construtor padr�o do m�dulo MAC.
     */
    MAC() : servicoCadastro(nullptr) {}

    /**
     * @brief Executa o menu de cria��o de conta no terminal.
     */
    bool executar() override;

    /**
     * @brief Injeta a depend�ncia do servi�o de cadastro.
     * @param servico Ponteiro para a implementa��o concreta do servi�o.
     */
    void setServicoCadastro(ISC* servico) override {
        this->servicoCadastro = servico;
    }
};

#endif // MAC_HPP_INCLUDED
