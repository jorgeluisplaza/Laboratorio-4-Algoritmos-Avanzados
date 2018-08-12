#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculoColonia(char * l);
void lecturaArchivo();
int calculoTotal(int a, int b, int c);
int minTres(int a, int b, int c);
int minDos(int a, int b);

int matriz[9999][9999];

int main(){
	lecturaArchivo();
	return 0;
}

void lecturaArchivo(){
	FILE * archivoEntrada;
	archivoEntrada = fopen("entrada.in", "r");
	char * linea = (char*)malloc(sizeof(char)*512);
	fgets(linea, 512, archivoEntrada);
	char * auxiliar;
	auxiliar = strtok(linea, "\n");
	calculoColonia(auxiliar);
}

void calculoColonia(char * l){
	int n = strlen(l);
	int contador[3];
	int i, j;
	for(i = 0; i < 3; i++){
		contador[i] = 0;
	}
	for(i = 0; i < n; i++){
		if(l[i] == '1'){
			contador[0]++;
		}
		if(l[i] == '2'){
			contador[1]++;
		}
		if(l[i] == '3'){
			contador[2]++;
		}
	}
	for(i = 0; i < contador[0]+5; i++){
		for(j = 0; j < contador[1]+5; j++){
			matriz[i][j] = -1;
		}
	}
	printf("El numero de unos es %i\n", contador[0]);
	printf("El numero de dos es %i\n", contador[1]);
	printf("El numero de tres es %i\n", contador[2]);
	printf("%i\n", matriz[2][1]);
	int final = calculoTotal(contador[0], contador[1], contador[2]);
	printf("El numero final es %i\n", final);


}

int calculoTotal(int a, int b, int c){
	printf("wtf\n");
	if(matriz[a][b] != -1){
		printf("Hello\n");
		return matriz[a][b];
	}
	if(a == 0 && b == 0){
		return (matriz[a][b] = c);
	}
	if(b == 0 && c == 0){
		return (matriz[a][b] = a);
	}
	if(a == 0 && c == 0){
		return (matriz[a][b] = b);
	}
	if(a == 0){
		return (matriz[a][b] = calculoTotal(a + 1, b - 1, c - 1));
	}
	if(b == 0){
		return (matriz[a][b] = calculoTotal(a - 1, b + 1, c - 1));
	}
	if(c == 0){
		return (matriz[a][b] = calculoTotal(a - 1, b - 1, c + 1));
	}
	return (matriz[a][b] = minDos(calculoTotal(a - 1, b - 1, c + 1), minDos(calculoTotal(a - 1, b + 1, c - 1), calculoTotal(a + 1, b - 1, c - 1))));
}

int minTres(int a, int b, int c){
	if(a < b && a < c){
		return a;
	}
	if(b < a && b < c){
		return b;
	}
	return c;
}

int minDos(int a, int b){
	if (a < b){
		return a;
	}
	return b;
}