#include <stdio.h>
#include <stdlib.h>

int traverse(int **ptra, int k)
{
    int i,j,count=0;
    for (i = 0; i < k; i++)
    {
        for(j=0;j<k;j++)
        {
            if(ptra[i][j]!=0)
            {
                count=count+1;
            }
        }
    }
    printf("no: of non zero ele=%d",count);
    return 0;
}

int upper(int **ptra, int k)
{
    int i,j;
    for (i = 0; i < k; i++)
    {
        for(j=0;j<k;j++)
        {
            if(i<j)
            {;
                printf("%d",ptra[i][j]);
            }
            else{
                printf(" ");
            }
            
        }
        printf("\n");
    }
    return 0;
}

int dia(int **ptra, int k)
{
    int i,j;
    for (i = 0; i < k; i++)
    {
        for(j=0;j<k;j++)
        {
            if(i-j==1||j-i==1)
            {
                printf("%d",ptra[i][j]);
            }
            else{
                printf(" ");
            }
            
        }
        printf("\n");
    }
    return 0;
}



int main()
{
    int n;
    printf("enter the order of matrix");
    scanf("%d", &n);
    int** ptr;
    ptr=(int**)malloc(n*(sizeof(int)));
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ptr[i]=(int*)malloc(n*(sizeof(int)));
        }
    }
    int i,j;
    printf("enter the elements");
    for (i = 0; i < n; i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &ptr[i][j]);
        }
    }
    while (1)
    {
        int choice;
        printf("\nPress 1 for no of non zero\n");
        printf("Press 2 for upper tri\n");
        printf("Press 3 for no of ele above and below diagonal\n");
        printf("Press 4 to exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            traverse(ptr, n);
        }
        if (choice == 2)
        {
            upper(ptr, n);
        }
        if (choice == 3)
        {
            dia(ptr, n);
        }
        else if (choice == 4)
        {
            break;
        }
    }
}