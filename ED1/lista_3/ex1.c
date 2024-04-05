#include <stdio.h>
#include <math.h>

int distancia(int xi, int xf, int yi, int yf);

int main(){
	
	printf("\nDis: %d", distancia(1, 1, 1, 4));
	return 0;
}

int distancia(int xi, int xf, int yi, int yf){
	int dif_x =0, dif_y=0;
	dif_x = xf - xi;
	dif_y = yf - yi;
	int resposta = 0;
	resposta = sqrt(pow(dif_x,2)+pow(dif_y, 2));
	return resposta;
}

