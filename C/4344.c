#include <stdio.h>


int main(void){
	int inp, student, i,j, grade[1000];
	double avg;
	
	scanf("%d", &inp);
	double result[inp];
	
	for(i=0;i<inp;i++){
		avg=0;
		result[i]=0;
		scanf("%d", &student);
		for(j=0;j<student;j++){
			scanf("%d", &grade[j]);
			avg+=grade[j];
		}
		avg/=student;
		for(j=0;j<student;j++){
			if(avg<grade[j]){
				result[i]++;
			}
		} 
		result[i]=(result[i]*100)/student;
		
	}
	for(i=0;i<inp;i++){
	printf("%.3lf%% \n", result[i]);
	}
	
}

