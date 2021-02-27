#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct RBNode;
typedef struct RBNode *RBTree;
typedef int ElementType;

typedef struct RBNode{
  	ElementType Element;
	int red;       /* red=1 when the node is red */
	RBTree left;
	RBTree right;
	RBTree parent;
}RBNode;

RBTree Insert(ElementType X,RBTree T);
RBTree delete(ElementType X, RBTree T);
RBTree SingleRotateWithLeft(RBTree K2);
RBTree SingleRotateWithRight(RBTree K2);
RBTree DoubleRotateWithLeft(RBTree K3);
RBTree DoubleRotateWithRight(RBTree K3);
void PrintLevelByLevel(RBTree T);
int sibColor(RBTree T);

int main(int argc,char* argv[])
{
	int i;
	RBTree T=NULL;

	FILE* fp = fopen("input.txt","rt");
	if(fp==NULL)
    {
        printf("File does not exist\n");
        return -1;
    }
    char input[100];
    
    ///insertion
    fgets(input,100,fp);
    char *token;
    int data;
    token=strtok(input," ");
    data =atoi(token);
    
    
    while(token!=NULL)
    {
    	T=Insert(data,T);
    	T->red=0;
    	PrintLevelByLevel(T);
    	printf("\n");
        token = strtok(NULL," ");
        if(!token)
            break;
        data = atoi(token);
        
    }
  
    ////deletion
    fgets(input, 100,fp);
    token =strtok(input, " ");
    data = atoi(token);
    while(token!=NULL)
    {
        T=delete(data,T);
        PrintLevelByLevel(T);
        printf("\n");
	token=strtok(NULL," ");
	if(!token)
            break;
        data = atoi(token);
    }
    


	fclose(fp);

	return 0;
}

RBTree delete(ElementType X,RBTree T)
{
	RBTree d=T;
	RBTree df=T;
	while(d){                            //  find key 
		if(d->Element>X){
			df=d;
			d=d->left;
		}
		else if(d->Element<X){
			df=d;
			d=d->right;
		}
		else
			break;
	}
	if(!d){
		printf("%d not exists\n",X);   // if not exist return 
		return T;
	}

	if(d->left&&d->right)                  // case A  the delete node with two children nodes   find left node's biggest node  
	{
		RBTree temp=d->left;
		if(!temp->right)
		{
			df=d;
			df->Element=temp->Element;
			d=df->left;
		}
		else{
			while(temp->right)
			{
				df=temp;
				temp=temp->right;
			}
			d->Element=temp->Element;
			d=df->right;
		}
	}

	if(d==df->left)                          //  node is on parent node's left
	
	{	

		if(d->left==NULL &&d->right==NULL)       // caseB  node is leaf
		{
			if(d->red==1)   //leaf node is red
				df->left=NULL;
			else   //  leaf node is black   we node to consider his bro node
			{
			
				if(df->red==0 &&df->right->red==1)//case1  only bro node is red
				{
					df=SingleRotateWithRight(df);
					df->parent->right=df;	//    we node reconnect the parent with new child
					df=df->left;					//	turn to case3_4_5
			
					if(df->red==1&&df->right->red==0)     //case3 bro node is black parent is red
					{
						df->red=0;
						df->right->red=1;
						df->left=NULL;
					}
					else if(df->right->red==0 &&df->right->left->red==1)    //case4 bro node is black with opposite direction red child
					{
						df=DoubleRotateWithRight(df);
						df->right->red=0;
						df->left=NULL;
                                       
                                        
                                	}
                                	else    //case5  bro node is black with same direction red child
                                	{
                                        	df=SingleRotateWithRight(df);
						df->left->red=0;
						df->left->left=NULL;
                                	}
					
				}
				else if(df->red==0&&df->right->red==0) //case2  d,df,bro nodes are   all black
				{
					df->right->red=1;
					df->left=NULL;
					df->parent->right->red=1;

				}
				else if(df->red=1&& df->right->red==0 ) //case3   metioned before
				{
					df->red=0;
					df->right->red=1;
					df->left=NULL;
				}
				else if(df->right->red==0 && df->right->left->red) //case4 metioned before
				
				{
				
					df=DoubleRotateWithRight(df);
					df->right->red=0;
					df->left=NULL;
				}
				else    //case5 metioned before
				{
					df=SingleRotateWithRight(df);
					df->left->red=0;
					df->left->left=NULL;
				}
			}
		}
	
	// case2 one child   node must be black and child must be red
		else 
		{
			if(d->left){
				d->Element=d->left->Element;
				df=d;
				d=d->left;
				df->left=NULL;
				d->parent=NULL;
			}
			else{
				d->Element=d->right->Element;
				df=d;
				d=d->right;
				df->right=NULL;
				d->parent=NULL;
			}

		}

	}
	
	else    // node is right
	
	{
                if(d->left==NULL &&d->right==NULL)
		{
                        if(d->red==1)   
                                df->right=NULL;
                        else   
                        {
                                if(df->red==0 &&df->left->red==1)
                                {
                                       df=SingleRotateWithLeft(df);
				       df->parent->right=df;
				       df=df->left;
                                       if(df->red==1&&df->left->red==0)
                                       {
                                                df->red=0;
                                                df->left->red=1;
						df->right=NULL;
                                       }
                                       else if(df->left->red==0 &&df->left->right->red==1)
                                       {
                                                df=DoubleRotateWithLeft(df);
						df->left->red=0;
						df->left=NULL;
                                       }
                                       else    
                                       {
                                                df=SingleRotateWithLeft(df);
						df->right->red=0;
						df->right->right=NULL;
                                       }

                                }
                                else if(df->red==0&&df->left->red==0)
                                {
                                        d->left->red=1;
					df->right=NULL;
					df->parent->left->red=1;
                                }
                                else if(df->red==1&&df->left->red==0) 
                                {
                                        df->red=0;
                                        df->left->red=1;
					df->right=NULL;
                                }
                                else if(df->left->red==0 && df->left->right->red==1) 
                                {
                                        df=DoubleRotateWithLeft(df);
					df->left->red=0;
					df->left=NULL;
                                }
                                else    
                                {
                                        df=SingleRotateWithLeft(df);
					df->right->red=0;
					df->right->right=NULL;
                                }
                        }
                }
	
        // case2 one child   node must be black and child must be red
                else {
                        if(d->left){
                                d->Element=d->left->Element;
                                df=d;
                                d=d->left;
                                df->left=NULL;
                        }
                        else{
                                d->Element=d->right->Element;
                                df=d;
                                d=d->right;
                                df->right=NULL;
                        }

                }

	}				
		
	
	free(d);
	
	return T;
}
int sibColor(RBTree T)
{
	int color=0;
	if (T==NULL)
		return color;
	color=sibColor(T->left);
	if (T->red ==1)
		return 1;
	color=sibColor(T->right);
	
	return 0;	
}
RBTree Insert(ElementType X,RBTree T)
{
	if(T==NULL)
	{
		T=malloc(sizeof(RBNode));
		if(T==NULL)
			printf("error\n");
		else{	
			T->red=1;
			T->Element=X;
			T->left=NULL;
			T->right=NULL;
			T->parent=NULL;
		}
	}
	else if(T->Element>X)
	{
		T->left=Insert(X,T->left);
		if(T->left->parent==NULL)
			T->left->parent=T;

		if((T->left->left==NULL&&T->left->right==NULL)||T->left->red==0)
			return T;
		else if(T->left->right==NULL)
		{
			if(T->left->left->red)
			{
				if(T->right==NULL)
					T=SingleRotateWithLeft(T); //LLb
				else if(T->right->red==0)
					T=SingleRotateWithLeft(T); //LLb
				else{
					T->red=1;
					T->left->red=0;
					T->right->red=0; //LLr
				}
			}
		} 
		else if(T->left->left==NULL)
		{
			if(T->left->right->red)
			{
				if(T->right==NULL)
					T=DoubleRotateWithLeft(T); //LRb
				else if(T->right->red==0)
					T=DoubleRotateWithLeft(T); //LRb
				else{
					T->red=1;
					T->left->red=0;
					T->right->red=0; //LRr
				}
			}
		}
		else
		{
			if(T->left->left->red)
			{
				if(T->right==NULL)
					T=SingleRotateWithLeft(T); //LLb
				else if(T->right->red==0)
					T=SingleRotateWithLeft(T); //LLb
				else{
					T->red=1;
					T->left->red=0;
					T->right->red=0; //LLr
				}
			}
			if(T->left->right->red)
			{
				if(T->right==NULL)
					T=DoubleRotateWithLeft(T); //LRb
				else if(T->right->red==0)
					T=DoubleRotateWithLeft(T); //LRb
				else{
					T->red=1;
					T->left->red=0;
					T->right->red=0; //LRr
				}
			}
		}
	}
	else if(T->Element<X)
	{
		T->right=Insert(X,T->right);
		if(T->right->parent==NULL)
			T->right->parent=T;

		if((T->right->left==NULL&&T->right->right==NULL)||T->right->red==0)
			return T;
		else if(T->right->right==NULL)
		{
			if(T->right->left->red)
			{
				if(T->left==NULL)
					T=DoubleRotateWithRight(T); //RLb
				else if(T->left->red==0)
					T=DoubleRotateWithRight(T); //RLb
				else{
					T->red=1;
					T->left->red=0;
					T->right->red=0; //RLr
				}
			}
		} 
		else if(T->right->left==NULL)
		{
			if(T->right->right->red)
			{
				if(T->left==NULL)
					T=SingleRotateWithRight(T); //RRb
				else if(T->left->red==0)
					T=SingleRotateWithRight(T); //RRb
				else{
					T->red=1;
					T->left->red=0;
					T->right->red=0; //RRr
				}

			}
		}
		else
		{
			if(T->right->left->red)
			{
				if(T->left==NULL)
					T=DoubleRotateWithRight(T); //RLb
				else if(T->left->red==0)
					T=DoubleRotateWithRight(T); //RLb
				else{
					T->red=1;
					T->left->red=0;
					T->right->red=0; //RLr
				}	
			}
			else if(T->right->right->red)
			{
				if(T->left==NULL)
					T=SingleRotateWithRight(T); //RRb
				else if(T->left->red==0)
					T=SingleRotateWithRight(T); //RRb
				else{
					T->red=1;
					T->left->red=0;
					T->right->red=0; //RRr
				}

			}
		}
	}
	else if(X==T->Element)
		printf("this key already exists\n");

	return T;
}

RBTree SingleRotateWithLeft( RBTree K2)
{
	RBTree K1;
	K1=K2->left;
	K1->parent=K2->parent;
	K2->parent=K1;
	K2->left=K1->right;
	K1->right=K2;
	K1->red=0;
	K2->red=1;

	return K1;
}
RBTree SingleRotateWithRight( RBTree K2)
{
	RBTree K1;
	K1=K2->right;
	K1->parent=K2->parent;
	K2->parent=K1;
	K2->right=K1->left;
	K1->left=K2;
	K1->red=0;
	K2->red=1;
	
	return K1;
}
RBTree DoubleRotateWithLeft(RBTree K3)
{
	K3->left=SingleRotateWithRight(K3->left);

	return SingleRotateWithLeft(K3);
}
RBTree DoubleRotateWithRight(RBTree K3)
{
	K3->right=SingleRotateWithLeft(K3->right);

	return SingleRotateWithRight(K3);
}
void PrintLevelByLevel(RBTree T)
{
	if(T!=NULL)
	{
		PrintLevelByLevel(T->left);
		if(T->red)
			printf("%d(r) ",T->Element);
		else
			printf("%d(b) ",T->Element);
		PrintLevelByLevel(T->right);
	}
}
