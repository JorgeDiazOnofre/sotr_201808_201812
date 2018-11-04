#include<stdio.h>

int queue[10];
int i=0;
int input=0;
//Function declaration
int priority(int queue[10]);


void main(){
	
	while(1){
	printf("Introduce a number from 0 to 10 to be orginized when ready, introduce 20\n");
	scanf("%d",&input);
	
	if (input<=10 && input>=0){
		queue[i]=input;
		i++;
		
	} else if(input==20){
		priority(queue);

	} else{
		printf("Introduce a correct number\n");
	}
	}
}

int priority(int queue[10]){
	int x=0,m=0,counter=0,times=9,l=0;
	int nqueue=[10];
	for(int a=0;a<10;a++){
		x=queue[a];
		for(int j=0;j<10;j++){
			if(x<queue[j]){
				counter++;
			}
		}
		if(counter==times){
			nqueue[l]=x;
			times--;
			l++;	
		}
}
	return 0;
}
