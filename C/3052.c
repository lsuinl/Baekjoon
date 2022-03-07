#include <stdio.h>


int main(void){
	int i,j, ip, count, result=0, suin[10];
	
	for(i=0;i<10;i++){
		scanf("%d", &ip);
		suin[i]=ip%42;
	}
	for(i=0;i<10;i++){
		count=0;
		for(j=i+1;j<10;j++){
			if(suin[i]==suin[j])
				count++;	
		}
		if(count==0)
			result++;
	}
	
	printf("%d", result);
}

