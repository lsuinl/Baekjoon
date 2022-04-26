#include <stdio.h>
#include <string.h>
 
//���̹�����  

//strlen()=���ڿ��� ���̸� ��ȯ�ϴ� �Լ�, <string.h> �ʿ�  
//https://develop247.tistory.com/16

int main(void){
	int inp, i ,j, sum, score; //�� 
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

