#include <stdio.h>
#include <stdlib.h>
/*Modo de jogar:e Digitando a linha (VERTICAL) 0-7,
  Depois Digitar Coluna(HORIZONTAL) (0-7)!
  Usuario 1 PRETAS
  Usuario 2 Brancas
*/
struct Jogador{
    char Usuario;
    int Quantidades_pecas;
};
struct Jogador usuario1;
struct Jogador usuario2;



char tabuleiro[8][8];
char usuarioAtual; // 'P' ou 'B'

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
                  tabuleiro[i][j] = ' ';
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
                  tabuleiro[i][j] = ' ';
              }
          }else{
              //linhas vazias
              tabuleiro[i][j] = ' ';
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
int verificarDestino(int linhaDe ,int colunaDe){
    int recebe;
    if(tabuleiro[linhaDe][colunaDe]==0){
     recebe = 0;
    }else if(tabuleiro[linhaDe][colunaDe]=='B'){
        recebe = 1;
    }
    return recebe;
}
int verificarDestino2(int linhaDe ,int colunaDe){
    int recebe;
    if(tabuleiro[linhaDe][colunaDe]==0){
     recebe = 0;
    }else if(tabuleiro[linhaDe][colunaDe]=='P'){
        recebe = 1;
    }
    return recebe;
}

int verificarDiagonal(int linhaO, int colunaO, int linhaD, int colunaD){
    if(usuarioAtual == 'P'){
        int diferencaLdLo = linhaD - linhaO; // Positiva
        int diferencaCdCo = colunaD - colunaO;
        if(diferencaLdLo > 0){
            diferencaCdCo = abs(colunaD - colunaO);
            return diferencaLdLo == diferencaCdCo;
        }
    }
        return 0;
}
int verificarDiagonal2(int linhaO, int colunaO, int linhaD, int colunaD){
    if(usuarioAtual == 'B'){
        int diferencaLdLo = linhaD - linhaO; // Positiva
        int diferencaCdCo = colunaD - colunaO;
        if(diferencaLdLo > 0){
            diferencaCdCo = abs(colunaD - colunaO);
            return diferencaLdLo == diferencaCdCo;
        }
    }
        return 0;
}

int main()
{
usuario1.Quantidades_pecas = 12;
usuario2.Quantidades_pecas = 12;
montar();
usuario1.Usuario = 'P';
usuario2.Usuario = 'B';
    int linhaO;
    int colunaO;
    int linhaD;
    int colunaD;

    do
    {

    mostrar();

    printf("\nUsuario Atual: 'P'\n");

    usuarioAtual=usuario1.Usuario;


    printf("\n\t->Vez do Usuario (%c)<-\n",usuarioAtual);

    printf("Usuario Digite a linha e coluna da Peca\n");
    scanf("%i", &linhaO);
    scanf("%i", &colunaO);
    printf("Usuario Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);
    //3.0 - Veirificar se estar dentro do Tabuleiro
    if( estarDentroTabuleiro(linhaO, colunaO) &&
        estarDentroTabuleiro(linhaD, colunaD)){
        //3.1 - Vericar se é Diagonal
        if(verificarDiagonal(linhaO, colunaO, linhaD, colunaD)){
            printf("MOVIMENTACAO VALIDA: %c\n", usuarioAtual);
            //3.2 Verificar a Origem -> Nao tem motivo pra verificar a casa origem , apenas deixa ela vazia!


             //3.3 Verificar o movimento para o destino
             if(verificarDestino(linhaD,colunaD)==0 || verificarDestino(linhaD,colunaD)==1){
             if(verificarDestino(linhaD,colunaD)==1)
             usuario1.Quantidades_pecas -= 1 ;
             // Fazer a peça ocupar o espaço!
             tabuleiro[linhaD][colunaD] = usuario1.Usuario;
             tabuleiro[linhaO][colunaO] = 0;

             }else{
                printf("\n Essa casa n pode ser acessada!\n");
             }



        }else{
            printf("MOVIMENTACAO INVALIDA para o usuário: ");
        }
    }else{
        // Fora do Tabuleiro
        printf("Posição fora do Tabuleiro !!!\n");

    }


    usuarioAtual = 0;
    linhaD = 0;
    colunaD = 0;

//------------------------------------------------------------------------------------------------------

     mostrar();
     usuarioAtual=usuario2.Usuario;

    printf("\n Usuario Atual: 'B'\n");






    printf("\n\t->Vez do Usuario (%c)<-\n",usuarioAtual);

    printf("Usuario Digite a linha e coluna da Peca\n");
    scanf("%i", &linhaO);
    scanf("%i", &colunaO);
    printf("Usuario Digite a linha e coluna do Destino\n");
    scanf("%i", &linhaD);
    scanf("%i", &colunaD);
    //3.0 - Veirificar se estar dentro do Tabuleiro
    if( estarDentroTabuleiro(linhaO, colunaO) &&
        estarDentroTabuleiro(linhaD, colunaD)){
        //3.1 - Vericar se é Diagonal
        if(verificarDiagonal2(linhaO, colunaO, linhaD, colunaD)){
            printf("MOVIMENTACAO VALIDA: %c\n", usuarioAtual);
            //3.2 Verificar a Origem -> Nao tem motivo pra verificar a casa origem , apenas deixa ela vazia!


             //3.3 Verificar o movimento para o destino
             if(verificarDestino2(linhaD,colunaD)==0 || verificarDestino2(linhaD,colunaD)==1){
             if(verificarDestino2(linhaD,colunaD)==1)
             usuario2.Quantidades_pecas -= 1 ;
             // Fazer a peça ocupar o espaço!
             tabuleiro[linhaD][colunaD] = usuario2.Usuario;
             tabuleiro[linhaO][colunaO] = 0;

             }else{
                printf("\n Essa casa n pode ser acessada!\n");
             }



        }else{
            printf("MOVIMENTACAO INVALIDA para o usuário: %c", usuarioAtual);
        }
    }else{
        // Fora do Tabuleiro
        printf("Posição fora do Tabuleiro !!!\n");

    }


    usuarioAtual = 0;
    linhaD = 0;
    colunaD = 0;
    }while (usuario1.Quantidades_pecas != 0 || usuario2.Quantidades_pecas != 0);

    if(usuario1.Quantidades_pecas == 0){
        printf("\nUsuario 1 Ganhou\n");
    }else if(usuario2.Quantidades_pecas == 0){
        printf("\nUsuario 2 Ganhou\n");
    }

    return 0;
}
