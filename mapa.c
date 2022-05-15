#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "mapa.h"


void copiamapa (MAPA* destino, MAPA* origem){
	 int i;
	 int j;
	 destino->linhas = origem->linhas;
	 destino->colunas = origem->colunas;
	 
	 alocamapa(destino);
	 	for (i = 0; i < origem->linhas; i++){
		 	for (j = 0; j < origem->colunas; j++){
		 		// destino->matriz [i] [j] = origem->matriz [i] [j] (strcpy faz isso )
		 		strcpy (destino->matriz[i], origem->matriz[i]);
		 		
			 }
	 	}
}

void andanomapa(MAPA*a, int xorigem, int yorigem, int xdestino, int ydestino){
	
	char personagem = a->matriz[xorigem] [yorigem];
	a->matriz [xdestino] [ydestino] = personagem;
	a->matriz [xorigem] [yorigem] = VAZIO;
}

int ehvalida(MAPA*a, int x, int y){
 	 if (x >= a->linhas)
 	     return 0 ;
     if (y >= a->colunas)
	     return 0 ;
 	     
 	     
     return 1;
}

int ehvazia (MAPA*a, int x, int y){
     return	a->matriz[x] [y] == VAZIO;
}

int encontramapa(MAPA* a,POSICAO* p, char c){
     int i; 
	 int j;
	 int x;
	 int y;
	
 	for (i = 0; i < a->linhas; i++){
		for ( j = 0; j < a->colunas; j++){ 
		   if(a->matriz[i] [j] == c){
		 	p->x = i;
		 	p->y = j;
		 	return 1;
		   }
		}	
 	}
	return 0;
}

void liberamapa(MAPA*a){
 	int i;
 	
	 for (i = 0 ; i  < a->linhas; i++){
         free (a->matriz[i]);
      }
      free(a->matriz);
}
void alocamapa(MAPA*a){
	 int i;
	 
     a->matriz = malloc(sizeof(char*) * a->linhas);
         for ( i = 0; i < a->linhas; i++){
         a->matriz[i] = malloc(sizeof(char) * (a->linhas + 1));
       }
}

void lemapa(MAPA*a){
	 int i;
	 
	 FILE* f;
     f = fopen("mapa.txt","r");
         if ( f==0 ){
           printf("Erro na leitura do programa\n");
           exit(1);
       }
     fscanf (f, "%d %d", &(a->linhas), &(a->colunas));
       
     alocamapa(a);
        
         for (i = 0; i < a->linhas ; i++){
         fscanf(f,"%s", a->matriz[i]);
         }
         fclose(f);
}
	 
void imprimemapa(MAPA*a){
     int i;
    
     	for ( i = 0; i <5; i++){
         printf("%s\n", a->matriz[i]); 
         }
}

