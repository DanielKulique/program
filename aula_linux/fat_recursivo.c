#include <stdio.h>
#include <stdlib.h>

int FAT(int num){
	if(num == 0)
		return 1;
	if(num == 1){
		return 1;
	}
	else
		return num * (FAT(num-1));
};



int main(){
	int number, fat;
	
	fat = FAT(5);
	
	printf("\nFATORIAL > %d\n", fat);
	
	return 0;
};
