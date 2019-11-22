#include <iostream>

using namespace std;


double potencia (float x,int indice);
double raiz(int indice,double numero);

int main()
{
    int indice;
    double radicando;
    cout <<"\nDigite o indice da raiz:";
    cin  >>indice;
    cout <<"\nDigite o radicando:";
    cin  >>radicando;


        cout <<"\n A raiz de "<< radicando << " e: " << raiz(indice,radicando) <<endl;
    return 0;
}

double raiz(int indice,double numero)
{
    double aux;
    aux = numero;
    aux = aux/indice;

    for(int i =0;i<100000000;i++)
    {
        //aux = aux/2;

        if(potencia(aux,indice)>numero)
        {
            aux = (aux)-0.0001;
        }
        else
        {
            //potencia < numero;
            aux = aux + 0.0001;
        }
        if(potencia(aux,indice)==numero)
            return aux;
    }
    return aux;
}
double potencia (float x,int indice)
{
    int a=0;
    float xAux=1;
    while(a!=indice)
    {
        xAux = xAux *x;
        a++;
    }
    return xAux;
}


