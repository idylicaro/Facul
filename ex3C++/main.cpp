#include <stdio.h>
#include <stdlib.h>



int main()
{
void entrada(int &h, int &m);
char conversao(int &h, int &m);
    int hora,minutos;
    char z;

    entrada(hora,minutos);
    z=conversao(hora,minutos);




    return 0;
}

void entrada(int &h, int &m){
    printf("\nDigite a hora e os minutos no formato (HH MM)!\n");
    scanf("%i %i",&h,&m);

    if(h>24 || h<0){
    printf("Error hora invalida!\n");
    exit(1);
    }
}
char conversao(int &h, int &m){

    if(0<h && h<12){return 'A';}
    else if(12<h && h<24){
    h-=12;
    return 'P';
    }


}
