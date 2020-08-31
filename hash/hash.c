#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int ElementType;
struct HashTable{
	int TableSize;
	ElementType* TheLists;
};

void print(struct HashTable *h){
	int i;
	for(i=0;i<h->TableSize;i++){
		printf("[%d]-> ",i);
		if(h->TheLists[i])
			printf("[%d]",h->TheLists[i]);
		printf("\n");
	}
}
int  find(struct HashTable*h,ElementType key){
        for(int i=0;i<h->TableSize;i++){
                if(h->TheLists[i]==key)
                        return 1;
        }
        return 0;

}

int Hash(int key,struct HashTable *h){ return  key%h->TableSize;}
void Insert(ElementType  key,struct HashTable *h){
	int value=Hash(key,h);
	int check=0;
	if(find(h,key)){
		printf("Duplicated value[%d]\n",key);
		return;
	}
	while(1){
		if (h->TheLists[value]){
			value++;
			check++;
			if(value==h->TableSize-1)
				value=0;
		}
		else{
			h->TheLists[value]=key;
			break;
		}
	}
	if(check!=0)
		printf("Collision for key[%d] occured\n",key);

}

void main(){
	struct HashTable *h=(struct HashTable*)malloc(sizeof(struct HashTable));
	int size,key,i;
	FILE*fp;
	char temp[100];
	int count=1;
	char ch;
	long  po;
	if((fp=fopen("input.txt","r"))==NULL)
		printf("can't open");
	fscanf(fp,"%d",&size);
	ch=getc(fp);
	po=ftell(fp);
	h->TableSize=size;
	h->TheLists=(int*)malloc(sizeof(int)*size);
	fgets(temp,100,fp);    				 //   get a line data
	for(i=0;i<strlen(temp);i++)
	{
		if (temp[i]==' ')
			count++;
	}
	fseek(fp,po,SEEK_SET);   			 //  file pointer back to begainning
	  						 //  file pointer pass size key
	for(i=0;i<count;i++)
	{    
		fscanf(fp,"%d",&key);
		Insert(key,h);
	}
	while(fscanf(fp,"%d",&key)==1)
	{
		if(find(h,key))
			printf("The key[%d] exists in the list\n",key);
		else
			printf("The key[%d] doesn't exist\n",key);
	}

	printf("/ HashTable / \n");
	print(h);
	
	fclose(fp);
}

