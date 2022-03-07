#include <stdio.h>
#include <string.h>
 
//네이버봤음  

//strlen()=문자열의 길이를 반환하는 함수, <string.h> 필요  
//https://develop247.tistory.com/16

int main(void){
	int inp, i ,j, sum, score; //ㅁ 
	char suin[80];
	
	scanf("%d", &inp);
	
	for(i=0;i<inp;i++){
		sum=0;
		score=1;
		
		scanf("%s", suin);
		
		for(j=0;j<strlen(suin);j++){
			if(suin[j]=='O'){
				sum +=score;
				score++;
			}
			if(suin[j]=='X'){
				score=1;
			}
		}
		printf("%d \n", sum);
	}
}

