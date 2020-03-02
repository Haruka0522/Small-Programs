#include <stdio.h>

int main(void){
	for(int i = 1;i<=9;i++){
		for(int j = 1;j<=9;j++){
			if(j==9){
				printf("%3d\n",i*j);
			}else{
				printf("%3d",i*j);
			}
		}
	}
	return 0;
}

