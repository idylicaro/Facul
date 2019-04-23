#include <stdio.h>
#include <stdlib.h>



int main()
{
void entrada(int &h, int &m);
char conversao(int &h, int &m);
void saida(int ht,int mt,char tp);

    int hora,minutos;
    char z;

    entrada(hora,minutos);
    z=conversao(hora,minutos);
    saida(hora,minutos,z);






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
void saida(int ht,int mt,char tp){
    if(tp=='A'){
        printf("\nA hora e: %i:%i A.M\n",ht,mt);
    }else if(tp=='P'){
        printf("\nA hora e: %i:%i P.M\n",ht,mt);
    }

}


