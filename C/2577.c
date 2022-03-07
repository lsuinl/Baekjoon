//2577번 숫자의 개수
#include <stdio.h>

int main(void) {
	int a, b, c, result, i;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	int suin[10]={0,};
	result=a*b*c;
	while(result>0)
	{
		++suin[(result)%10];
		result/=10;
	}
	for(i=0; i<=9;i++){
		printf("%d \n", suin[i]);
	}
}
