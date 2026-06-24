#include <string>
#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

using namespace std;

/**
 * @class Codigo
 * @brief Representa o domínio de Código.
 *
 * O código deve possuir exatamente 5 caracteres, sendo os dois primeiros
 * letras maiúsculas e os três últimos dígitos numéricos.
 */
class Codigo{
    private:
        string valor;
        /**
         * @brief Valida a regra de formatação do código.
         * @param valor String a ser validada.
         * @throw std::invalid_argument Se o formato for inválido.
         */
        void validar(string);
    public:
        /**
         * @brief Define o código se o valor fornecido for válido.
         * @param valor String representando o código.
         * @throw std::invalid_argument Se o valor fornecido for inválido.
         */
        void setCodigo(string);
        /**
         * @brief Retorna o código armazenado.
         * @return String contendo o código.
         */
        string getCodigo() const;
};

inline string Codigo::getCodigo() const{
    return valor;
}

/**
 * @class Data
 * @brief Representa o domínio de Data.
 *
 * A data deve seguir o formato DD/MM/ANO, onde o ano deve estar entre
 * 2000 e 2999. Valida a quantidade correta de dias do mês, incluindo
 * o cálculo matemático para anos bissextos.
 */
class Data{
    private:
        string valor;
        /**
         * @brief Valida o formato e a lógica temporal da data.
         * @param valor String a ser validada.
         * @throw std::invalid_argument Se o formato ou os valores temporais forem inválidos.
         */
        void validar(string);
        /**
         * @brief Verifica matematicamente se um ano é bissexto.
         * @param ano Inteiro representando o ano.
         * @return true se for bissexto, false caso contrário.
         */
        bool isBissexto(int);
    public:
        /**
         * @brief Define a data se o valor fornecido for válido.
         * @param valor String representando a data.
         * @throw std::invalid_argument Se a data for inválida.
         */
        void setData(string);
        /**
         * @brief Retorna a data armazenada.
         * @return String contendo a data.
         */
        string getData() const;
};

inline string Data::getData() const{
    return valor;
}

/**
 * @class Email
 * @brief Representa o domínio de Email.
 *
 * O e-mail deve obedecer ao formato parte-local@domínio, com regras
 * restritas para o uso de caracteres alfanuméricos, pontos e hifens,
 * além de validar o tamanho máximo de 64 caracteres na parte local
 * e 255 no domínio.
 */
class Email {
    private:
        string valor;
        /**
         * @brief Valida a formatação do e-mail.
         * @param valor String a ser validada.
         * @throw std::invalid_argument Se o formato do e-mail for inválido.
         */
        void validar(string);
    public:
        /**
         * @brief Define o e-mail se o valor fornecido for válido.
         * @param valor String representando o e-mail.
         * @throw std::invalid_argument Se o e-mail for inválido.
         */
        void setEmail(string);
        /**
         * @brief Retorna o e-mail armazenado.
         * @return String contendo o e-mail.
         */
        string getEmail() const;
};

inline string Email::getEmail() const{
    return valor;
}

/**
 * @class Estado
 * @brief Representa o domínio de Estado.
 *
 * Armazena o estado do ciclo de vida de uma entidade, permitindo
 * apenas os valores "A FAZER", "FAZENDO" ou "FEITO".
 */
class Estado{
    private:
        string valor;
        static const string A_FAZER;
        static const string FAZENDO;
        static const string FEITO;
        /**
         * @brief Valida se o estado corresponde aos valores permitidos.
         * @param valor String a ser validada.
         * @throw std::invalid_argument Se o estado for inválido.
         */
        void validar(string);
    public:
        /**
         * @brief Define o estado se o valor fornecido for válido.
         * @param valor String representando o estado.
         * @throw std::invalid_argument Se o estado for inválido.
         */
        void setEstado(string);
        /**
         * @brief Retorna o estado armazenado.
         * @return String contendo o estado.
         */
        string getEstado() const;
};

inline string Estado::getEstado() const{
    return valor;
}

/**
 * @class Nome
 * @brief Representa o domínio de Nome.
 *
 * Texto composto por letras e espaços, devendo ter entre 1 e 10
 * caracteres. Espaços não podem ser o primeiro nem o último caractere,
 * e um espaço deve ser sempre seguido de uma letra.
 */
class Nome{
    private:
        string valor;
        /**
         * @brief Valida a formatação e os caracteres do nome.
         * @param valor String a ser validada.
         * @throw std::invalid_argument Se o nome não obedecer às regras.
         */
        void validar(string);
    public:
        /**
         * @brief Define o nome se o valor fornecido for válido.
         * @param valor String representando o nome.
         * @throw std::invalid_argument Se o nome for inválido.
         */
        void setNome(string);
        /**
         * @brief Retorna o nome armazenado.
         * @return String contendo o nome.
         */
        string getNome() const;
};

inline string Nome::getNome() const{
    return valor;
}

/**
 * @class Papel
 * @brief Representa o domínio de Papel.
 *
 * Define o nível de atuação de um usuário no sistema, permitindo
 * apenas os valores "DESENVOLVEDOR", "MESTRE SCRUM" ou "PROPRIETARIO DE PRODUTO".
 */
class Papel{
    private:
        string valor;
        static const string DESENVOLVEDOR;
        static const string MESTRE_SCRUM;
        static const string PROPRIETARIO_DE_PRODUTO;
        /**
         * @brief Valida se o papel corresponde aos valores permitidos.
         * @param valor String a ser validada.
         * @throw std::invalid_argument Se o papel for inválido.
         */
        void validar(string);
    public:
        /**
         * @brief Define o papel se o valor fornecido for válido.
         * @param valor String representando o papel.
         * @throw std::invalid_argument Se o papel for inválido.
         */
        void setPapel(string);
        /**
         * @brief Retorna o papel armazenado.
         * @return String contendo o papel.
         */
        string getPapel() const;
};

inline string Papel::getPapel() const{
    return valor;
}

/**
 * @class Prioridade
 * @brief Representa o domínio de Prioridade.
 *
 * Estabelece a urgência de uma entidade no sistema, permitindo
 * apenas os valores "ALTA", "MEDIA" ou "BAIXA".
 */
class Prioridade{
    private:
        string valor;
        /**
         * @brief Valida se a prioridade corresponde aos valores permitidos.
         * @param valor String a ser validada.
         * @throw std::invalid_argument Se a prioridade for inválida.
         */
        void validar(string);
    public:
        /**
         * @brief Define a prioridade se o valor fornecido for válido.
         * @param valor String representando a prioridade.
         * @throw std::invalid_argument Se a prioridade for inválida.
         */
        void setPrioridade(string);
        /**
         * @brief Retorna a prioridade armazenada.
         * @return String contendo a prioridade.
         */
        string getPrioridade() const;
};

inline string Prioridade::getPrioridade() const{
    return valor;
}

/**
 * @class Senha
 * @brief Representa o domínio de Senha.
 *
 * A senha deve conter exatamente 6 caracteres alfanuméricos, exigindo
 * pelo menos uma letra maiúscula, uma minúscula e um dígito. Não permite
 * que letras sejam seguidas por letras ou dígitos por dígitos.
 */
class Senha{
    private:
        string valor;
        /**
         * @brief Valida a formatação e as regras de alternância da senha.
         * @param valor String a ser validada.
         * @throw std::invalid_argument Se a senha for inválida.
         */
        void validar(string);
    public:
        /**
         * @brief Define a senha se o valor fornecido for válido.
         * @param valor String representando a senha.
         * @throw std::invalid_argument Se a senha for inválida.
         */
        void setSenha(string);
        /**
         * @brief Retorna a senha armazenada.
         * @return String contendo a senha.
         */
        string getSenha() const;
};

inline string Senha::getSenha() const{
    return valor;
}

/**
 * @class Tempo
 * @brief Representa o domínio de Tempo.
 *
 * Modela a estimativa de tempo utilizando um valor numérico inteiro
 * que deve estar obrigatoriamente no intervalo de 1 a 365.
 */
class Tempo{
    private:
        int valor;
        /**
         * @brief Valida se o tempo está dentro dos limites numéricos.
         * @param valor Inteiro a ser validado.
         * @throw std::invalid_argument Se o tempo for menor que 1 ou maior que 365.
         */
        void validar(int);
    public:
        /**
         * @brief Define o tempo se o valor fornecido for válido.
         * @param valor Inteiro representando o tempo.
         * @throw std::invalid_argument Se o tempo for inválido.
         */
        void setTempo(int);
        /**
         * @brief Retorna o tempo armazenado.
         * @return Inteiro contendo o tempo.
         */
        int getTempo() const;
};

inline int Tempo::getTempo() const{
    return valor;
}

/**
 * @class Texto
 * @brief Representa o domínio de Texto.
 *
 * Texto geral com comprimento de 1 a 40 caracteres. Aceita letras,
 * dígitos, pontuação básica (vírgula e ponto) e espaços em branco, com
 * regras restritivas para caracteres consecutivos e posicionamento da pontuação.
 */
class Texto{
    private:
        string valor;
        /**
         * @brief Valida o comprimento e as regras de sequenciamento de caracteres.
         * @param valor String a ser validada.
         * @throw std::invalid_argument Se o texto desrespeitar as regras de formatação.
         */
        void validar(string);
    public:
        /**
         * @brief Define o texto se o valor fornecido for válido.
         * @param valor String representando o texto.
         * @throw std::invalid_argument Se o texto for inválido.
         */
        void setTexto(string);
        /**
         * @brief Retorna o texto armazenado.
         * @return String contendo o texto.
         */
        string getTexto() const;
};

inline string Texto::getTexto() const{
    return valor;
}

#endif // DOMINIOS_HPP_INCLUDED
