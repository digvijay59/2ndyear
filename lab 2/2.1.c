#include<stdio.h>
#include<stdlib.h>
int main()
{
    int insert(int *ptra,int m)
    {
        int i;
        int k;
        int j;
        printf("\nenter the position");
        scanf("%d",&k);
        printf("enter the value");
        scanf("%d",&j);

        for (i=0;i<m;i++)
        {
            
            if (i==k)
            {
                
                *ptra=j;
                
            }
            ptra++;
        }
        return 0;
    }

    int del()
    {
        int i;
        int k;
        int j;
        printf("\nenter the position");
        scanf("%d",&k);
        printf("enter the value");
        scanf("%d",&j);

        for (i=0;i<m;i++)
        {
            
            if (i==k)
            {
                
                *ptra=j;
                
            }
            ptra++;
        }
        return 0;
    }

    int lsearch()
    {
        int i;
        int k;
        int j;
        printf("\nenter the position");
        scanf("%d",&k);
        printf("enter the value");
        scanf("%d",&j);

        for (i=0;i<m;i++)
        {
            
            if (j==*ptra)
            {
                printf("%d",*ptra);   
            }
            ptra++;
        }
        return 0;
    }

    int traverse(){
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
            break;
        }
    }
}