#include <stdio.h>
#include <stdlib.h>


int somar(int v[], int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return v[0];
	}
	else{
		return v[n-1]+somar(v, n-1);
	}
}

int main(){
	int v[5] = {7, 3, 9, 8, 6}, res;
	res=somar(v , 5);
	
	printf("\nValor da soma %d", res);
	return 0;
}
