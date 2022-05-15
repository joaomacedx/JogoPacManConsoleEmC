#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

void move(char direcao);
void  fantasmas();
int acabou();
int ehdirecao(char direcao);
int paraondefantasmavai ( int xatual, int yatual, int* xdestino, int* ydestino );

