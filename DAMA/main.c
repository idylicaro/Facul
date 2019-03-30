#include <stdio.h>
#include <stdlib.h>
/*Modo de jogar:e Digitando a linha (VERTICAL) 0-7,
  Depois Digitar Coluna(HORIZONTAL) (0-7)!
  Usuario 1 PRETAS
  Usuario 2 Brancas
*/

char tabuleiro[8][8];
int pontos_pretos,pontos_brancos;
int linhaO,colunaO,linhaD,colunaD;
char usuarioAtual;

void montar() {
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
          if(i <= 2){
              //PRETO
              //par - impar - par
              if(i == 0 && j % 2 == 0){
                  tabuleiro[i][j] = 'P';
              }else if(i == 1 && j % 2 != 0){
                  tabuleiro[i][j] = 'P';
              }else if(i == 2 && j % 2 == 0){
                  tabuleiro[i][j] = 'P';
              } else{
                  tabuleiro[i][j] = '\xDB';
              }

          }else if(i >= 5 && i <= 7){
              //BRANCO
              //impar - par - impar
              if(i == 5 && j % 2 != 0){
                  tabuleiro[i][j] = 'B';
              }else if(i == 6 && j % 2 == 0){
                  tabuleiro[i][j] = 'B';
              }else if(i == 7  && j % 2 != 0){
                  tabuleiro[i][j] = 'B';
              } else{
                  tabuleiro[i][j] = '\xDB';
              }
          }else if(i == 3 && j % 2 == 0){
              //linhas vazias
              tabuleiro[i][j] = '\xDB';
          }
          else if(i == 4 && j % 2 != 0)
          {
              tabuleiro[i][j] = '\xDB';
          }
     }
    }
}

void mostrar() {
     for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
          printf("%c", tabuleiro[i][j]);
        }
         printf("\n");
     }
}
int estarDentroTabuleiro(int linha, int coluna){
    return (linha >= 0 && linha <= 7) &&
        (coluna >= 0 && coluna <= 7);
}
int verificarDiagonal(int linhaO, int colunaO, int linhaD, int colunaD){
    if(usuarioAtual == 'P'){
        int diferencaLdLo = linhaD - linhaO; // Positiva
        int diferencaCdCo = colunaD - colunaO;
        if(diferencaLdLo > 0){
            diferencaCdCo = abs(colunaD - colunaO);
            return diferencaLdLo == diferencaCdCo;
        }


    }else if(usuarioAtual == 'B'){
        int diferencaLdLo1 = linhaO - linhaD; // Positiva
        int diferencaCdCo1 = colunaO - colunaD;
        if(diferencaLdLo1 > 0){
            diferencaCdCo1 = abs(colunaO-colunaD);
            return diferencaLdLo1 == diferencaCdCo1;
        }
    }
    return 0;

}
void movimentacao_Preta(){
while((linhaD-linhaO)!=1){
    printf("Voce movimentou mais de uma casa !\n");
    printf("Usuario(P) Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);
}
if(tabuleiro[linhaD][colunaD] == 'B'){
        if(colunaD>colunaO){
        tabuleiro[linhaD+1][colunaD+1] = 'P';
        tabuleiro[linhaD][colunaD] = 0;
        tabuleiro[linhaO][colunaO] = 0;
        pontos_pretos++;
        }else if(colunaD<colunaO)
        tabuleiro[linhaD+1][colunaD-1] = 'P';
        tabuleiro[linhaD][colunaD] = 0;
        tabuleiro[linhaO][colunaO] = 0;
        pontos_pretos++;
        system("cls");
        mostrar();
}else if(tabuleiro[linhaD][colunaD] == 0){
    tabuleiro[linhaD][colunaD] = 'P';
        tabuleiro[linhaO][colunaO] = 0;
        system("cls");
        mostrar();
}

}

void movimentacao_Branca(){
    while((linhaO-linhaD)!=1){
    printf("Voce movimentou mais de uma casa !\n");
    printf("Usuario(P) Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);
}
    if(tabuleiro[linhaD][colunaD] == 'P'){
        if(colunaD>colunaO){
        tabuleiro[linhaD-1][colunaD+1] = 'B';
        tabuleiro[linhaD][colunaD] = 0;
        tabuleiro[linhaO][colunaO] = 0;
        pontos_brancos++;
        system("cls");
        mostrar();
}else if(colunaD<colunaO){
    tabuleiro[linhaD-1][colunaD-1] = 'B';
        tabuleiro[linhaD][colunaD] = 0;
        tabuleiro[linhaO][colunaO] = 0;
        pontos_brancos++;
        system("cls");
            mostrar();
}
}
else if(tabuleiro[linhaD][colunaD] == 0){
    tabuleiro[linhaD][colunaD] = 'B';
        tabuleiro[linhaO][colunaO] = 0;
        system("cls");
        mostrar();
}
}

int main()
{
montar();

    do{

    system("cls");
    mostrar();
usuarioAtual = 'P';
    printf("Jogador(P) Digite a linha e coluna da Peca\n");
    scanf("%i %i", &linhaO, &colunaO);

    printf("Usuario(P) Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);

    while(tabuleiro[linhaO][colunaO] == 'B')
        {
            printf("voce tentou movimentar as brancas!!! refaca a jogada!");
            printf("Jogador (P) Digite a linha e coluna da Peca\n");
    scanf("%i", &linhaO);
    scanf("%i", &colunaO);
    usuarioAtual = 'P';
    printf("Usuario(P) Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);
        }
    //3.0 - Veirificar se estar dentro do Tabuleiro
    if( estarDentroTabuleiro(linhaO, colunaO) &&
        estarDentroTabuleiro(linhaD, colunaD)){
        //3.1 - Vericar se é Diagonal
            while(verificarDiagonal(linhaO, colunaO, linhaD, colunaD)==0){
                printf("Movimento Invalido digite,Nao e DIAGONAL!!!\n");
                printf("Usuario(P) Digite a linha e coluna do Destino\n");
                    scanf("%i", &linhaD);
                    scanf("%i", &colunaD);
            }

        //verificar se o movimento nao esta obstruido
        while(tabuleiro[linhaD][colunaD] == 'P')
        {
            printf("ha uma peca preta impossibilitando sua jogada!!!\n");
            printf("Jogador(P) Digite a linha e coluna da Peca\n");
    scanf("%i", &linhaO);
    scanf("%i", &colunaO);
    usuarioAtual = 'P';
    printf("Usuario(P) Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);
        }
        //3.0 - Verificar se estar dentro do Tabuleiro
    if( estarDentroTabuleiro(linhaO, colunaO) &&
        estarDentroTabuleiro(linhaD, colunaD)){
        //3.1 - Vericar se é Diagonal
        while(verificarDiagonal(linhaO, colunaO, linhaD, colunaD)==0){
                printf("Movimento Invalido digite,Nao e DIAGONAL!!!\n");
                printf("Usuario(P) Digite a linha e coluna do Destino\n");
                    scanf("%i", &linhaD);
                    scanf("%i", &colunaD);
            }

        }else{
            printf("MOVIMENTACAO INVALIDA para o usuario: %c\n", usuarioAtual);
        }
        movimentacao_Preta();
    }
//----------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------

    usuarioAtual = 'B';
    printf("Jogador(B) Digite a linha e coluna da Peca\n");
    scanf("%i %i", &linhaO, &colunaO);

    printf("Usuario(B) Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);

    while(tabuleiro[linhaO][colunaO] == 'P')
        {
            printf("voce tentou movimentar as Pretas!!! refaca a jogada!");
            printf("Jogador (B) Digite a linha e coluna da Peca\n");
    scanf("%i", &linhaO);
    scanf("%i", &colunaO);
    usuarioAtual = 'B';
    printf("Usuario(B) Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);
        }
    //3.0 - Veirificar se estar dentro do Tabuleiro
    if( estarDentroTabuleiro(linhaO, colunaO) &&
        estarDentroTabuleiro(linhaD, colunaD)){
        //3.1 - Vericar se é Diagonal
        while(verificarDiagonal(linhaO, colunaO, linhaD, colunaD)==0){
                printf("Movimento Invalido digite,Nao e DIAGONAL!!!\n");
                printf("Usuario(B) Digite a linha e coluna do Destino\n");
                    scanf("%i", &linhaD);
                    scanf("%i", &colunaD);
            }
        //verificar se o movimento nao esta obstruido
        while(tabuleiro[linhaD][colunaD] == 'B')
        {
            printf("ha uma peca Branca impossibilitando sua jogada!!!\n");
            printf("Jogador(B) Digite a linha e coluna da Peca\n");
    scanf("%i", &linhaO);
    scanf("%i", &colunaO);
    usuarioAtual = 'B';
    printf("Usuario(B) Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);
    system("cls");
        }
        //3.0 - Verificar se estar dentro do Tabuleiro
    if( estarDentroTabuleiro(linhaO, colunaO) &&
        estarDentroTabuleiro(linhaD, colunaD)){
        //3.1 - Vericar se é Diagonal
        while(verificarDiagonal(linhaO, colunaO, linhaD, colunaD)==0){
                printf("Movimento Invalido digite,Nao e DIAGONAL!!!\n");
                printf("Usuario(B) Digite a linha e coluna do Destino\n");
                    scanf("%i", &linhaD);
                    scanf("%i", &colunaD);
            }
        }else{
            printf("MOVIMENTACAO INVALIDA para o usuario: %c\n", usuarioAtual);
        }
        movimentacao_Branca();
    }
    }while(pontos_brancos != 12 || pontos_pretos != 12);

    return 0;
}
