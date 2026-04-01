#include <iostream>
#include <string>
#include "dominios/dominios.hpp"

using namespace std;

int main()
{
    Estado *estado = new Estado();
    string estadoDigitado;

    cout << "Digite o estado para verificacao: ";
    getline(cin, estadoDigitado);

    if(estado->setEstado(estadoDigitado)){
        cout << "Deu bom! O valor do estado foi armazenado: " << estado->getEstado() << "!!" << endl;
    } else {
        cout << "Cabouse pro betinha... Estado invalido e nao armazenado." << endl;
    }

    delete estado;

    return 0;
}
