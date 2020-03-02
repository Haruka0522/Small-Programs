#include <stdio.h>

int main(void){
	int nums[10];
	for(int i = 0;i<10;i++){
		printf("%d番目の数値を入力しろや",i);
		scanf("%d",&nums[i]);
	}

	for(int i = 0;i<10;i++){
		printf("%d\n",nums[9-i]);
	}

	return 0;
}
