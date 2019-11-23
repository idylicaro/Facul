#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
using namespace std;

#include "listaSencadeada.h"
#include "InputBackend.h"
int main()
{
    setlocale ( LC_ALL,"");
    cout << "PROCESSANDO..." <<endl;
    ifstream arquivo("acidentes.txt");
    if(arquivo.is_open())
    {
        TLista lista;
        TInfo item;

        criaLista(lista);

        getAtributos(lista);

        Imprime(lista);
        system("pause");

    }
    else
    {
        cout << "ARQUIVO INVALIDO" <<endl;
    }

    return 0;
}
