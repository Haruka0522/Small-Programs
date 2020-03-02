#include <stdio.h>

int main(void){
	int No;
	scanf("%d",&No);
	switch(No){
		case 1:
			printf("野比のび太\n");
			break;
		case 2:
			printf("源静香\n");
			break;
		case 3:
			printf("剛田武\n");
			break;
		case 4:
			printf("骨川スネ夫\n");
			break;
		default:
			printf("そんな番号の人はいない\n");
			break;
	}
	return 0;
}
