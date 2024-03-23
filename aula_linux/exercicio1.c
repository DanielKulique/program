#include <stdlib.h>
#include <stdio.h>

int main()
{
	int num=5;
	int *p;

	//parte1	
	p=&num;
	printf("\nAntes: %d", *p); // conteudo do endereço contido em p = 5
	*p = 10;
	printf("\nDepois: %d", *p);	

	//parte2
	
	int num2=10, num3=5, num4= 1;
	char ch, ch2;
	
	if(num2 > num3)
	{
		printf("\nMemoria de num2 %ld", &num2); 
		printf("\nMemoria de num3 %ld", &num3);
		printf("\nMemoria de num4 %ld", &num4);
		printf("\nMemoria de char %ld", &ch);
		printf("\nMemoria de char2 %ld", &ch2);
	}
	else 
	{
		printf("\nMemoria de num3 %p", &num3);
		printf("\nMemoria de num2 %p", &num2);
	}
}
