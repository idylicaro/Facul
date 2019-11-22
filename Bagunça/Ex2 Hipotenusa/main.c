#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");

    double calcHipotenusa(double a,double b);

    int n;
    double catetoA,catetoB,hipotenusa;
    double xa,ya,xb,yb;


    do
    {
        printf("Digite o cateto (Xa) e (Ya):\n");
        scanf("%lf %lf",&xa,&ya);

        printf("Digite o cateto (Xb) e (Yb):\n");
        scanf("%lf %lf",&xb,&yb);

        catetoA = (xb-xa);
        catetoB = (yb-ya);

        hipotenusa = calcHipotenusa(catetoA,catetoB);

        printf("A Distancia é  :%.2lf\n",hipotenusa);

        printf("Quer fazer outro calculo ?\n (1)Sim (0)Não\n");
        scanf("%i",&n);

    }
    while(n==1);

    return 0;
}

double calcHipotenusa(double a,double b)
{
    double resultado;

    resultado = (a*a)+(b*b);

    return sqrt(resultado);

}
