#include <string>
#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

using namespace std;

class Codigo{
    private:
        string valor;
        void validar(string valor);
    public:
        void setCodigo(string valor);
        string getCodigo();
};

inline string Codigo::getCodigo(){
    return valor;
}

class Data{
    private:
        string valor;
        void validar(string);
        bool isBissexto(int);
    public:
        void setData(string);
        string getData();
};

inline string Data::getData(){
    return valor;
}

class Email {
    private:
        string valor;
        void validar(string);
    public:
        void setEmail(string);
        string getEmail();
};

inline string Email::getEmail() {
    return valor;
}

class Estado{
    private:
        string valor;
        static const string A_FAZER;
        static const string FAZENDO;
        static const string FEITO;
        void validar(string);
    public:
        void setEstado(string);
        string getEstado();
};

inline string Estado::getEstado(){
    return valor;
}

class Nome{
    private:
        string valor;
        void validar(string valor);
    public:
        void setNome(string valor);
        string getNome();
};

inline string Nome::getNome(){
    return valor;
}


class Papel{
    private:
        string valor;
        static const string DESENVOLVEDOR;
        static const string MESTRE_SCRUM;
        static const string PROPRIETARIO_DE_PRODUTO;
        void validar(string);
    public:
        void setPapel(string);
        string getPapel();
};

inline string Papel::getPapel(){
    return valor;
}

class Prioridade{
    private:
        string valor;
        void validar(string valor);
    public:
        void setPrioridade(string valor);
        string getPrioridade();
};

inline string Prioridade::getPrioridade(){
    return valor;
}


class Senha {
    private:
        string valor;
        void validar(string);
    public:
        void setSenha(string);
        string getSenha();
};

inline string Senha::getSenha() {
    return valor;
}

class Tempo{
    private:
        int valor;
        void validar(int valor);
    public:
        void setTempo(int valor);
        int getTempo();
};

inline int Tempo::getTempo(){
    return valor;
}


class Texto{
    private:
        string valor;
        void validar(string valor);
    public:
        void setTexto(string valor);
        string getTexto();
};

inline string Texto::getTexto(){
    return valor;
}


#endif // DOMINIOS_HPP_INCLUDED
