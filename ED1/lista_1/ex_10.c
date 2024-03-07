#include <stdio.h>
#include <stdlib.h>

int main(){
   int i, acc=0,j;
    char a;
   for(i=1;i<10;i++){
        for(j=0;j<i;j++)
            acc-=1;
   }
   scanf("%d", &a);
   printf("%d", acc);

    switch(1) 
{
    case 1;
    printf("O valor eh 10 "); 
    break;
    case 2; 
   	printf("O valor eh 20 "); 
 	break; 
default; 
   	printf("O valor não eh 10 nem 20"); 
  	break;
} 

}