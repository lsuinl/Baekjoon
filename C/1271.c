#include <stdio.h>

int main(void) {
	int money, people;
	scanf("%d %d", &money, &people);
	
	printf("%d \n%d", money/people, money%people);
}
