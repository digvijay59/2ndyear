#include<stdio.h>
int main(){
    int addprime(int *ptra,int m)
    {
        int i;
        /*printf("\n%d",*ptra);*/
        int sum=0;
        for (i=0;i<m;i++)
        {
            int j;
            int cnt=0;
            
            printf("\n%d",*ptra);
            for ( j=1;j<=*ptra;j++)
            {
                if(*ptra%j==0)
                {
                    cnt=cnt+1;

                }
            }
            printf("number of times divisible =%d",cnt);
            if (cnt<=2)         
            {
                sum=sum+*ptra;
            }
            
            ptra++;
        }
        printf("\nsum is %d",sum);
        return 0;
    }
    int n;
    printf("enter the length of array");
    scanf("%d",&n);
    int a[n];
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int *ptr=&a[0];
    addprime(ptr,n);
}