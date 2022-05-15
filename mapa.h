#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAl'-'





struct mapa {
 	char** matriz;  
     int linhas;
     int colunas;  
};

typedef struct mapa MAPA;

struct posicao{
	 int x;
     int y;
};

typedef struct posicao POSICAO;


void liberamapa(MAPA*m);
void lemapa(MAPA*m);
void alocamapa(MAPA*m);
void imprimemapa(MAPA*m);
void encontramapa(MAPA* a,POSICAO* p, char c);
int ehvalida(MAPA*a, int x, int y);
int ehvazia (MAPA*a, int x, int y);
void andanomapa(MAPA*a, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa (MAPA* destino, MAPA* origem);


