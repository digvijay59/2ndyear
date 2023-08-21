#include<stdio.h>
int main()
{
    int insert(int *ptra,m){
        int i;
        int k;
        printf("enter the posotion");
        scanf("%d",&k);
        for (i=0;i<m;i++)
        {
            int j;
            printf("\n%d",*ptra);
            for ( j=1;j<=*ptra;j++)
            {
                
            }
            printf("number of times divisible =%d",cnt);
            if (cnt<=2)         
            {
                sum=sum+*ptra;
            }
            
            ptra++;
        return 0;
    }

    int del(){
        return 0;
    }

    int lsearch(){
        return 0;
    }

    int traverse(){
        return 0;
    }

    int exit(){
        return 0;
    }
    int n;
    printf("enter the length of array");
    scanf("%d",&n);
    int a[n];
    int i;
    printf("enter the elements");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int *ptr=&a[0];
    while(1)
    {
        int choice;
        printf("Press 1 to insert.\n");
        printf("Press 2 to delete\n");
        printf("Press 3 to lenear search\n");
        printf("Press 4 to traverse\n");
        printf("Press 5 to exit\n");
        scanf("%d", &choice);
        if (choice==1){
            insert(ptr,n);
        }
        else if (choice==2)
        {
            del(ptr,n);
        }
        else if (choice==3)
        {
            lsearch(ptr,n);
        }
        else if (choice==4)
        {
            traverse(ptr,n);
        }
        else if (choice==5)
        {
            exit();
        }
    }
    
}