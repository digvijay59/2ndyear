#include<stdio.h>
int main(){
    int a;
    int b;
    printf("enter 2 numbers\n");
    scanf("%d",&a);
    scanf("%d",&b);
    int *aptr=&a;
    int *bptr=&b;
    int cba(int* cptr,int* dptr)
    {
        
        if (*cptr>*dptr)
        {
            printf("\n%d is greater than %d",*cptr,*dptr);
        }
        else{
            printf("\n%d is greater than %d",*dptr,*cptr);
        }
        
        return 0;
    }
    cba(aptr,bptr);
}