#include <stdio.h>
#include <stdlib.h>



int main()
{
void entrada();
    int hora,minutos;

    entrada();

    printf("%i %i \n",hora,minutos);



    return 0;
}

void entrada(int &h, int &m){
    printf("\nDigite a hora e os minutos no formato (HH MM)!\n");
    scanf("%i %i",&hora,&minutos);
}
