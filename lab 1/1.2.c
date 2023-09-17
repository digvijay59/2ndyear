#include<stdio.h>
#include<stdlib.h>
int addprime(int *ptra,int m)
{
    int i;
    int sum=0;
    for (i=0;i<m;i++)
    {
        int j;
        int cnt=0;
        for ( j=1;j<=ptra[i];j++)
        {
            if(ptra[i]%j==0)
            {
                cnt=cnt+1;

            }
        }
        if (cnt<=2 && cnt>1)         
        {
            sum=sum+ptra[i];
        }
        
    }
    printf("\nsum is %d",sum);
    return 0;
}
int main(){
    int n;
    printf("enter the length of array");
    scanf("%d",&n);
    int *ptr;
    ptr =(int*)malloc(n*sizeof(int));
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    addprime(ptr,n);
}