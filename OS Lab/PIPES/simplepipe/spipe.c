#include<stdio.h>
#include<unistd.h>
int main(){
	int pipfd[2];
	int returnstat;
	char s1[20]="os pipe";
	char s2[20]="program";
	char r1[20],r2[20];
	returnstat = pipe(pipfd);
	if(returnstat==-1){
		printf("unable to create the pipe");
	}
	write(pipfd[1],s1,sizeof(s1));
	read(pipfd[0],r1,sizeof(s1));
	printf("%s",r1);
	write(pipfd[1],s2,sizeof(s1));
	read(pipfd[0],r2,sizeof(r2));
	printf("%s",r2);
	return 0;
}
