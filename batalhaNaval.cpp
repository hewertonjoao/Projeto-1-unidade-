#include <iostream>
#include <conio.h>
using namespace std;
int TAM = 11;



#include <stdio.h>
#include <stdlib.h>

                                        // MAPA JOGADOR 1
char mapa1[11][11] = {'*' , '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9',
                     '0' , '*', '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '1' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '2' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*', 
                     '3' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*', 
                     '4' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                    '5' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '6' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '7' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '8' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '9' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*'};  
                     
                                        // MAPA JOGADOR 2
char mapa2[11][11] = {'*' , '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9',
                     '0' , '*', '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '1' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '2' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*', 
                     '3' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*', 
                     '4' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '5' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '6' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '7' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '8' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '9' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*'};  


char mapa3[11][11] = {'*' , '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9',
                     '0' , '*', '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '1' , '*' , '1' , '*' , '*' , '*' , '*' , '*' , '*' , '5' , '*',
                     '2' , '*' , '1' , '*' , '3' , '3' , '3' , '*' , '*' , '5' , '*', 
                     '3' , '*' , '1' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*', 
                     '4' , '*' , '1' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '5' , '*' , '1' , '*' , '*' , '*' , '*' , '4' , '4' , '4' , '*',
                     '6' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '7' , '*' , '*' , '*' , '2' , '2' , '2' , '2' , '*' , '*' , '*',
                     '8' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                     '9' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*'}; 
int **AlocandoMatriz(int m, int n){
  int **v;  
  int   i;    
  v = (int **) calloc (m, sizeof(int *));	
  if (v == NULL) {
     printf ("** Erro: Memoria Insuficiente **");
     return (NULL);
     }
  
  for ( i = 0; i < m; i++ ) {
      v[i] = (int*) calloc (n, sizeof(int));	
      if (v[i] == NULL) {
         printf ("** Erro: Memoria Insuficiente **");
         return (NULL);
         }
      }
  return (v); 
}


void cabecalho(){
  system("cls");
  cout << "\n\n\n\n";
  cout << "|  ****************************************************************  |" << endl;
  cout << "|  ********************** BATALHA NAVAL ***************************  |" << endl;
  cout << "|  ****************************************************************  |" << endl;
  }

/* 
   5 unidades - PORTA AVIOS - 1
   4 unidades - NAVIO DE GUERRA -2
   3 UNIDADES - O CRUZADOR - 3
   3 UNIDADES - O SUBMARINO - 4
   2 UNIDADES - O DESTRUIDOR - 5
*/

void AlocandoNavios(int ** d){
  int P = 5, N = 4 , C = 3 , S = 3 , D = 2;
  int p = 1, n = 1 , c = 1 , s = 1 , de = 1;
  int x,y,dir,ver=1;
  while( ver !=0 ){
    x = rand() % 10;
    y = rand() % 10;
    cout << x << " " << y << endl;
    d[x][y] = 1;
    dir = rand() % 4 + 1;  // 1 ESQUERDA , 2 CIMA , 3 DIREITA, 4 Baixo
    cout << dir << endl;
    if (dir == 1 || P < x){
      for (int i=y-1; i>y-5 ; i--){
        d[x][i] = 1;
      }
      ver=0;       
    }
    else if (dir == 2 || P < y){
      for (int i = x-1; i>x-5 ; i--){
        d[i][y] = 1;
      }      
      ver=0;        
    }   
    else if (dir == 3 || P > y){
      for (int i = y+1; i<y+5; i++){
        d[x][i] = 1;
      }
      ver=0;       
    }   
    else if (dir == 4 || P > x){
      for (int i = x+1; i<x+5; i++){
        d[i][y] = 1;
      }   
      ver=0;          
    }      
  }     
  }
   

int main (){
  int **camp; 
  int **camp1;
  int i, j;
  
  camp = AlocandoMatriz (TAM, TAM);
  camp1 = AlocandoMatriz (TAM, TAM);
  int valendo = 1;
  int x1,x2;
 
  

  for(;;){
    cabecalho();
    cout << "|                          [1] PLAY                                  |" << endl;
    cout << "|                          [2] SAIR                                  |" << endl;
    cout << "|DIGITE ALGUMA DAS OPCOES = ";

    int inicio;
    cin >> inicio;
    switch (inicio)
    {
      case 1:
      system("cls");
      cabecalho();
        
          for(int i=0;i<TAM;i++){
            for(int j=0;j<TAM;j++){
              cout << mapa1[i][j] << " ";
            }
            cout << endl;
          }
          cout << "QUAL POSICAO DESEJA DERRUBAR (X) = ";
          cin >> x1;
          cout << " (Y) = ";
          cin >> x2;
          system("pause");
        
        break;
      
      case 2:
        cout << "SAINDO..." << endl;
        getch();
        exit(0);
    
    default:
      break;
    }
    
    
    
    

}
}