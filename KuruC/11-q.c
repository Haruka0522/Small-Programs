#include <stdio.h>

int OlympicCheck(int year){
	if(year % 2 == 0){
		if(year % 4 == 0){
			return 1;
		}else{
			return 2;
		}
	}else{
		return 3;
	}
}

int main(void){
	int year;
	printf("年を西暦で入力してください");
	scanf("%d",&year);
	if(OlympicCheck(year)==1){
		printf("%d年には夏季オリンピックがあります\n",year);
	}else if(OlympicCheck(year)==2){
		printf("%d年には冬季オリンピックがあります\n",year);
	}else{
		printf("%d年にはオリンピックはありません\n",year);
	}
}
