#include<stdio.h>

int main(void){
	int melody, result, avg;
	scanf("%d %d", &melody, &avg);
	result=melody*(avg-1)+1;
	printf("%d", result);
}
