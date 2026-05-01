#include <string>
#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

using namespace std;

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

#endif // DOMINIOS_HPP_INCLUDED
