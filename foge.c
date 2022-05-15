#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "foge.h"
#include "mapa.h"

MAPA a;
POSICAO heroi;

int paraondefantasmavai ( int xatual, int yatual, int* xdestino, int* ydestino ){
	 int i;
	 int j;
	 int opcoes [4] [2] = {
	 	{xatual, yatual +1},
	 	{xatual +1, yatual},
	 	{xatual, yatual -1},
	 	{xatual -1, yatual}
	 	
	 };
	 srand(time(0));
	 for(i = 0; i < 10; i++){
	 	 int posicao = rand() %4;
	 	
	 	 if(ehvalida(&a, opcoes[posicao][0], opcoes[posicao] [1]) && ehvazia(&a, opcoes[posicao][0], opcoes[posicao] [1])){
	 	 	*xdestino = opcoes[posicao] [0];
	 	 	*ydestino = opcoes[posicao] [1];
	 	 	return 1;
		  }
		 return 0;
	 }
	
}

void  fantasmas(){
	 MAPA copia; 
	 int i; 
	 int j;
	 copiamapa(&copia, &a);
	     for (i = 0; i < a.linhas; i++){
	    	 for ( j = 0; j < a.colunas; j++){
	    	 	
	    	   	if (copia.matriz [i] [j] == FANTASMA){
	    	   		int xdestino;
	    	   		int ydestino;
	    	   		int encontrou = paraondefantasmavai( i, j, &xdestino, &ydestino);
	    	   			if(encontrou){
	    	   				andanomapa(&a, i, j, xdestino, ydestino);	
					 }
	    	   		
				   }
	    	   
	    	   
			 } 
		 }
	 liberamapa(&copia);
}

int acabou(){
	 POSICAO pos;
	 int fogenomapa = encontramapa (&a, &pos, HEROI);
	 return !fogenomapa;
}

int ehdirecao(char direcao){
 	return direcao == 'a' ||
	 direcao ==  'w'||
	 direcao ==  's'||
	 direcao ==  'd';
}

void move(char direcao){
	 if	(!ehdirecao(direcao)){
	 	printf("PARA MOVER O HEROI DIGITE: A, W, S OU D !!\n");
	 	return;
	 }
	
	
     int proximox = heroi.x;
     int proximoy = heroi.y;
 	
 	switch(direcao){
	  	case ESQUERDA:
		 	 proximoy--;
			 break;
	     case CIMA:
	         proximox--;
			 break;
	     case BAIXO:
	         proximox++;
			 break;
	     case DIREITA:
	         proximoy++;
			 break;
	 }
	     if(!ehvalida(&a, proximox, proximoy))
	     	return;
		 
	 	if (!ehvazia(&a, proximox, proximoy))
	     	return;
	     
     andanomapa(&a, heroi.x, heroi.y, proximox, proximoy);
     heroi.x = proximox;
     heroi.y = proximoy;
}
	
int main (){
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@ | BEM-VINDO AO NOSSO JOGO FOGE | @@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! | INSTRUCOES | !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!PARA MOVER O HEROI DIGITE OS DIRECIONAIS:!!!!!!!!!!!!!!!!!!\n");
	printf("!| W=> MOVE P/CIMA, A=> MOVE P/ESQUERDA, S=> MOVE P/BAIXO , D=> MOVE P/DIREITA| !\n"); 
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
	
     lemapa(&a);
     encontramapa(&a, &heroi,HEROI);
     do {
     	
     	imprimemapa(&a);
     	
     	char comando;
     	scanf(" %c", &comando);
     	
     	move(comando);
     	fantasmas();
     	
       }while (!acabou());
       
         liberamapa(&a);
      
        }

