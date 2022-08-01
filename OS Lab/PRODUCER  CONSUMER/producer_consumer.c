#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=10,x=0;
void producer(){
	--mutex;
	++full;
	--empty;
	x++;
	printf("Producer produced %d\n",x);
	--x;
	++mutex;
}
void consumer(){
	--mutex;
	++full;
	--empty;
	x++;
	printf("Consumer consumed %d\n",x);
	--x;
	++mutex;
}
int main(){
	int n,i;
	printf("\n1 Press 1 for producer\n2 press 2 for consumer\n3 press 3 for exit\n");
	for(i=1;i>0;i++){
		printf("Enter your choice");
		scanf("%d",&n);
		switch(n){
		case 1:
		if((mutex==1)&&(empty!=0)){
			producer();
		}
		else{
			printf("Buffer is full\n");
		}
		break;
		case 2:
		if((mutex==1)&&(full!=0)){
			consumer();
		}
		else{
			printf("Buffer is empty\n");
		}
		break;
		case 3:
		exit(0);
		break;
		}
	}
}
