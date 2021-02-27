#include<stdio.h>
int fio(int num){
        switch(num){
        case 0:
                return 0;
        case 1:
                return 1;
        default:
                return(fio(num-1)+fio(num-2));
        }

}

int main(void){
        int num;
        printf("n= ");
        scanf("%d",&num);
        for(int i=0;i<=num;i++){
                printf("p%d=%d\n",i,fio(i));
        }

        return 0;
}

