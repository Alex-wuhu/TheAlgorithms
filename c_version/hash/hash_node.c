#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY 10
#define TABLE 13
typedef struct{
	char key[KEY];
} element;
typedef struct list{
	element item;
	struct list *link;
}list;
list*hash_table[TABLE];
void print(list*ht[]){
	list *node;
	int i;
	for(i=0;i<TABLE;i++){
		printf("[%d]-> ",i);
		for(node=ht[i];node;node=node->link){
			printf("%s->",node->item.key);
		}
		printf("\n");
	}
}
int transform(char *key){
	int number=0;
	while(*key)
		number+=*key++;
	return number;
}
int hash_function(char*key){ return transform(key)%TABLE;}

void hash_add(element item,list *ht[]){
	int hash_value=hash_function(item.key);
	list*p;
	list*node_before=NULL;
	list*node=ht[hash_value];
	for(;node;node_before=node,node=node->link)
	{
		if(!strcmp(node->item.key,item.key))
		{
			printf("%s already exists\n",item.key);
			return;
		}
	}
	p=(list*)malloc(sizeof(list));
	p->item=item;
	p->link=NULL;
	if(node_before)
		node_before->link=p;
	else
		ht[hash_value]=p;
}
void hash_find(element item,list *ht[]){
	list*node;
	int hash_value=hash_function(item.key);
	for(node=ht[hash_value];node;node=node->link){
		if(!strcmp(node->item.key,item.key)){
			printf("found\n");
			return;
		}
	}
	printf("not find\n");
}
void main(){
	element temp;
	strcpy(temp.key,"a");
	hash_add(temp,hash_table);
	strcpy(temp.key,"b");
	hash_add(temp,hash_table);
	strcpy(temp.key,"c");
        hash_add(temp,hash_table);
        strcpy(temp.key,"d");
        hash_add(temp,hash_table);
        strcpy(temp.key,"a");
        hash_add(temp,hash_table);
        strcpy(temp.key,"ai");
        hash_add(temp,hash_table);

	print(hash_table);
	
}

