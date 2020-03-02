#include <stdio.h>

int main(void){
	int score;
	do{
		scanf("%d",&score);
	}
	while(score < 0 || 100 < score);
	printf("%d\n",score);
	return 0;
}
