#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct poly_node *poly_pointer;
typedef struct poly_node
{
	int coef;
	int expon;
	poly_pointer link;
}poly_node;
poly_pointer creat_node(){
	poly_pointer temp;
	temp=(poly_node*)malloc(sizeof(poly_node));
        temp->coef=0;
        temp->expon=-1;
	temp->link=NULL;
	return temp;
}
poly_pointer Read(int n){
	int ceof;
	int expon;
	poly_pointer head=creat_node();
	poly_pointer temp;
	poly_pointer cur; 
       for(int i=1;i<=n;i++){
	       printf("enter the ceof for item%i: ",i);              
	       scanf("%i",&ceof);
	       printf("enter the expon for item%i: ",i);
	       scanf("%i",&expon);
	       temp=creat_node();
	       temp->coef=ceof;
	       temp->expon=expon;
	       if(i==1){
		       head->link=temp;
		       cur=temp;
	       }
	       else{
	       cur->link=temp;
	       cur=cur->link;
	       }
		
	    	
       }
       cur->link=head;
       return head;
}

void Write(poly_pointer header){
	poly_pointer head=header->link;
	while(head->expon!=-1){
		if(head->coef==0)
			printf("0");	
		else if(head->expon==0)
			printf("%d",head->coef);
		else if(head->coef==1)
			printf("x^%d",head->expon);
		else if(head->coef==-1)
			printf("-x^%d",head->expon);
		else
			printf("%dx^%d",head->coef,head->expon);
			
		head=head->link;
		
		if( head->coef>=0&& head->expon!=-1)
			printf("+");
		}
		
	printf("\n");
}
poly_pointer mul(poly_pointer a,poly_pointer b)
{
	poly_pointer cur;
	poly_pointer new_head=creat_node();
	poly_pointer bhead=b->link;poly_pointer m=bhead;
	poly_pointer ahead=a->link;poly_pointer n=ahead;
	poly_pointer temp;
	int i=0;
	int new_coef,new_expon;
	
	while(n->expon!=-1)
	{
		
		while(m->expon!=-1){
			 new_coef=n->coef*m->coef;
               		 new_expon=n->expon+m->expon;
			 temp=creat_node();
			 temp->coef=new_coef;
			 temp->expon=new_expon;
			 if(i==0){
				 new_head->link=temp;
				 i+=1;
				 cur=temp;
			 }
			 else{
				 cur->link=temp;
				 cur=cur->link;
			 }
			 m=m->link;


		}
		
		m=bhead;
		n=n->link;
		
	}
	cur->link=new_head;
	return new_head;
	
}

poly_pointer minus(poly_pointer a,poly_pointer b)
{
	poly_pointer new=creat_node();
	poly_pointer cura=a->link;
	poly_pointer curb=b->link;
	poly_pointer temp,cur;
	int i=0;
	while(cura->expon!=-1 || curb->expon!=-1){
		if(cura->expon==curb->expon){

			temp=creat_node();
			temp->coef=cura->coef-curb->coef;
			temp->expon=cura->expon;
			cura=cura->link;
			curb=curb->link;
			if(temp->coef==0)
				continue;
			if(i==0){
				new->link=temp;
				i+=1;
			}
		}
		else if(cura->expon>curb->expon){;
			temp=creat_node();
			temp->coef=cura->coef;
			temp->expon=cura->expon;
			if(i==0){
				new->link=temp;
				i+=1;
			}
			cura=cura->link;
		}
		else {
			temp=creat_node();
			temp->coef=curb->coef*-1;
			temp->expon=curb->expon;
			if(i==0){
				new->link=temp;
				i+=1;
			}
			curb=curb->link;
		}
		
		cur->link=temp;
		cur=cur->link;
	}
	if(cura->expon!=-1){
		while(cura->expon!=-1){
			temp=creat_node();
			temp->coef=cura->coef;
			temp->expon=cura->expon;
			cur->link=temp;
			cur=cur->link;
			cura=cura->link;
		}
	}
	else if(curb->expon!=-1){
		while(curb->expon!=-1){
			temp=creat_node();
			temp->coef=curb->coef*-1;
			temp->expon=curb->expon;
			cur->link=temp;
			cur=cur->link;
			curb=curb->link;
		}
	}
	
	cur->link=new;
	return new;
}



int divide(poly_pointer a,poly_pointer b,poly_pointer q,poly_pointer r)
{
	int qhead=0;
	poly_pointer x=a->link;
	poly_pointer y=b->link;
	poly_pointer temp,qcur;
	poly_pointer temp_head=creat_node();
	poly_pointer x_head=creat_node();
	if(x->expon<y->expon)
		return 0;
	else
	{
		while(x->expon>=y->expon){
			temp=creat_node();
			temp->coef=x->coef/y->coef;
			temp->expon=x->expon-y->expon;
			if(qhead==0){
				q->link=temp;
				qcur=temp;
				qhead+=1;
			}
			else{
				qcur->link=temp;
				qcur=qcur->link;
			}
			temp_head->link=temp;
			temp->link=temp_head;
			x_head->link=x;
			r=minus(x_head,mul(temp_head,b));
			x=r->link;
		}qcur->link=q;
	}
	printf("a/b result:\n");
	printf("que:");
	Write(q);
	printf("remainder:");
	Write(r);
	return 1;
}

void evalt(poly_pointer eva,double f){
	int j;
	double sum1=0;
	double sum2=1;
	double temp;
	printf(" for polynomial a: ");
	Write(eva);
	
	poly_pointer cal=eva->link;

	while(cal->expon!=-1){
		for(j=1;j<=cal->expon;j++){
			sum2=f*sum2;
		}
		temp=cal->coef*sum2;
		sum2=1;
		sum1+=temp;
		cal=cal->link;
	}
	printf("the f(%2.lf)=%.2lf \n ",f,sum1);
}

void main(){
	int n,m,test,choice=0;
	double x;
	poly_pointer a;
	poly_pointer b;
	poly_pointer mult;
	poly_pointer quotient=creat_node();
	poly_pointer remainder;

	printf("how many items for a: ");
	scanf("%i",&n);
	a=Read(n);

	printf("how many items for b: ");
	scanf("%i",&m);
	b=Read(m);

	printf("a is :"); 
	Write(a);//       print a
	
	printf("b is :");
	Write(b);//       print  b
	while(choice!=99){
	printf("Enter 1: multiple\n");
	printf("Enter 2: dividle\n");
	printf("Enter 3: evalte\n");
	printf("Enter 99: break\n");
	printf("Enter a number for chioce:");
        scanf("%d",&choice);

	if (choice==1){	
		mult=mul(a,b);
		printf("product :");
		Write(mult);//    print a*b
	}
	else if(choice==2){
	test=divide(a,b,quotient,remainder);//  print a/b
	if(test==0)
		printf("cant divide\n");
	}
	else if(choice==3){
	printf("Enter the x for polynomail a to evalte: ");
        scanf("%lf",&x);
        evalt(a,x);                        //  printf f(x)
	}
	else if(choice==4)
		break;
	else 
		printf("plz enter the right number\n");
	}


}

	


