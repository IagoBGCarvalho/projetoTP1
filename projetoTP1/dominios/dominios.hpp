#include <string>
#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

using namespace std;

class Estado{
    private:
        string estadoAtual;
        static const string AFAZER;
        static const string FAZENDO;
        static const string FEITO;
        bool validar(string);
    public:
        bool setEstado(string);
        string getEstado();
};

inline string Estado::getEstado(){
    return estadoAtual;
}

#endif // DOMINIOS_HPP_INCLUDED
