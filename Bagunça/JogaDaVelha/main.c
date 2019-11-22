#include <stdio.h>
#include <stdlib.h>



void mostrar(char casas2[3][3]){
    system("cls");
    printf("\n\n\t 1    2    3\n");
    printf("\t1 %c | %c | %c\n",casas2[0][0],casas2[0][1],casas2[0][2]);
    printf("\t -----------\n");
    printf("\t2 %c | %c | %c\n",casas2[1][0],casas2[1][1],casas2[1][2]);
    printf("\t -----------\n");
    printf("\t3 %c | %c | %c \n",casas2[2][0],casas2[2][1],casas2[2][2]);
}


int main()
{
    char casas[3][3]={0,0,0,
                      0,0,0,
                      0,0,0};

    char repit;
    int cont_jogadas,l,c,vez = 0;




    do{
            cont_jogadas = 1;

        /*Limpando a matriz*/
        int i,j;
        for(i = 0;i<=2;i++){
            for(j=0;j<=2;j++){
                casas[i][j] = ' ';
            }
        }
        do{
            mostrar(casas);
            /*Verificaçao de quem e a jogada!*/
            if(vez%2==0){
                printf("\nJogador X\n");
            }else{
                printf("\nJogador O\n");
            }

            printf("digite a linha/coluna\n");
            scanf("%i %i",&l,&c);
            /*Verificaçao pra ver se ta dentro do tabuleiro*/
            if(l<1 || c<1 || l>3 || c>3){
                l=0;
                c=0;
            }else if(casas[l-1][c-1] != ' '){
                l=0;
                c=0;
            }else{
                if(vez % 2 ==0){
                    casas[l-1][c-1] = 'X';
                }else{
                    casas[l-1][c-1] = 'O';
                }
                vez++;
                cont_jogadas++;
            }
                /*verifiacçoes de vitoria*/
            if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){cont_jogadas = 11;}
            if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){cont_jogadas = 11;}
            if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[1][2] == 'X'){cont_jogadas = 11;}
            if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
            if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){cont_jogadas = 11;}
            if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
            if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
            if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}

            if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){cont_jogadas = 12;}
            if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){cont_jogadas = 12;}
            if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[1][2] == 'O'){cont_jogadas = 12;}
            if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}
            if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){cont_jogadas = 12;}
            if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
            if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
            if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}

        }while(cont_jogadas <= 9);
         mostrar(casas);

        if(cont_jogadas==10){
            printf("Jogo Empatou!\n");
        }else if(cont_jogadas==11){
            printf(" -> X <-GANHOU!\n");
        }else if(cont_jogadas==12){
            printf(" -> O <-GANHOU!\n");
        }







    }while(scanf("%c",&repit)!= 's');


    return 0;
}
