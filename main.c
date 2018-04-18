#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 65
#define HEIGHT 21
#define N 100

//Struct que representa el snake.
typedef struct {
	char bodyPart;
	int x, y;
	int dx, dy;
} Snake;
//Arreglo de estructuras snake.
Snake snakeArr[N];

//Struct que representa la comida.
typedef struct {
	char rep; //representa el caracter de la comida.
	int x, y;
	
} Fruit;
Fruit fruitVar;

//Inicializar la pantalla en conjunto con el marco.
void readScreen(char gameScreen[HEIGHT][WIDTH]) {
	int i, k;
	
	for(i = 0; i < HEIGHT; i++) {
		for(k = 0; k < WIDTH; k++) {
			if (i == 0 || i == HEIGHT-1 || k == 0 || k == WIDTH - 1)
				gameScreen[i][k] = '*';
			else
				gameScreen[i][k] = ' ';
		}
	}
}

//Inicializar pantalla para el snake.
void readInput(char gameScreen[HEIGHT][WIDTH], int snakeSize) {
	int idx = 0;
	unsigned short int alter = 1;
	//Pasar coordenadas continuamente al cuerpo del snake
	for(idx = 1; idx < snakeSize; idx++) {
		snakeArr[idx].x = snakeArr[idx - 1].x - 1; // Pasar la coordenada anterior a otra parte del snake.
		snakeArr[idx].y = snakeArr[idx - 1].y;
		
		(alter == 1) ? (snakeArr[idx].bodyPart = '}') : (snakeArr[idx].bodyPart = '{');
		(alter == 1) ? (alter = 0) : (alter = 1);
	}
	
	snakeArr[0].bodyPart = 'O';
	
	for(idx = 0; idx < snakeSize; idx++) {
		gameScreen[snakeArr[idx].y][snakeArr[idx].x] = snakeArr[idx].bodyPart;
	}
	
	gameScreen[fruitVar.y][fruitVar.x] = '@';
}

void drawGame(char gameScreen[HEIGHT][WIDTH]) {
	int i, k;
	
	for(i = 0; i < HEIGHT; i++) {
		for(k = 0; k < WIDTH; k++) {
			printf("%c", gameScreen[i][k]);
		}
		printf("\n");
	}
}

int snakeCollision(int *snakeSize) {
	
	int isDead = 0, i = 1;
	
	for(i = 1; i < *snakeSize && isDead == 0; i++) {
		if (snakeArr[0].x == snakeArr[i].x && snakeArr[0].y == snakeArr[i].y)
			isDead = 1;
	}
	if (snakeArr[0].x == 0 || snakeArr[0].x == WIDTH - 1 || snakeArr[0].y == HEIGHT - 1 || snakeArr[0].y == 0)
		return 1;
	else
		return 0;
}

void eatCollision(int *snakeSize) {
	if (snakeArr[0].x == fruitVar.x && snakeArr[0].y == fruitVar.y) {
		
	}
}
void readKB(char gameScreen[HEIGHT][WIDTH], int *snakeSize, int *isDead) {
	
	*isDead = snakeCollision(snakeSize);
	
	
}

//Realiza el movimiento del snake.
void logicLoop(char gameScreen[HEIGHT][WIDTH], int snakeSize) {
	int isDead = 0;
	
	while(!isDead) {
		drawGame(gameScreen);
		readKB(gameScreen, &snakeSize, &isDead);
	}
}


void startGame(int *snakeSize, char gameScreen[HEIGHT][WIDTH]) {
	//Posiciona la cabeza del snake en estas coordenadas.
	snakeArr[0].x = 32;
	snakeArr[0].y = 10;
	
	//Configurar el tamanio de la serpiente.
	*snakeSize = 5;
	
	//Posicionar la comida del snake aleatoreamente.
	srand(time(NULL)); //Inicializar la funcion rand con el clock de la maquina (por default).
	
	fruitVar.x = rand() % (WIDTH-2) + 1;
	fruitVar.y = rand() % (WIDTH- 2) + 1;
	//Poner a correr el snake a la derecha.
	int idx;
	for(idx = 0; idx < *snakeSize; idx++) {
		snakeArr[idx].dx = 1; //Derecha, positivo en el plano.
		snakeArr[idx].dy = 0;
	}
	
	readScreen(gameScreen);
	readInput(gameScreen, *snakeSize);
}



int main(int argc, char *argv[]) {
	
	//Crear matriz del juego
	char gameScreen[HEIGHT][WIDTH];
	int snakeSize; //Tamanio de la serpiente.
	
	startGame(&snakeSize, gameScreen);
	
		
	return 0;
}
