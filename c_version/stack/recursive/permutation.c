#include<stdio.h>
#include<string.h>
void swap(char *a ,char*b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void perm(char *list,int i,int n){
	int j;
	if(i==n){
		for(j=0;j<=n;j++){
			printf("%c",list[j]);
		}
	       	printf("\n");
	}
	else{
		for(j=i;j<=n;j++){
			char *pi=&list[i];
			char*pj=&list[j];
			swap(pi,pj);
			perm(list, i+1,n);
			swap(pi,pj);
			}
		}
}
int  main(){

	char list[50];
	scanf("%s",list);
	int i=0;
	perm(list,i,strlen(list)-1);
	return 0;
}

