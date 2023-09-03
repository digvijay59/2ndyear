#include <stdio.h>
#include <stdlib.h>

void insert(int *ptra, int *m)
{
    int i;
    int loc, elem;
    int n = *m;
    printf("\nenter the position");
    scanf("%d", &loc);

    printf("enter the value");
    scanf("%d", &elem);

    if(loc<=n)
    {
        n = *m+1;
        for (i = n - 1; i > loc; i--)
            *(ptra+i) = *(ptra + i - 1);

        *(ptra+loc) = elem;
        
        for (i = 0; i < n; i++)
            printf("%d ", *(ptra++));
        
        printf("\n");        
    }
    else
    {
        printf("invalid");
    }


}

int del(int *ptra, int *m)
{
    int i;
    int j, p;
    printf("enter index to del");
    scanf("%d", &j);
    if (j <= *m)
    {
        for (i = (j - 1); i < *m; i++)
        {
            p = i + 1;
            *(ptra + i) = *(ptra + p);
        }
        *m = *m - 1;
        printf("deleted");
    }
    else
    {
        printf("\ninvalid");
    }
    return 0;
}

int lsearch(int *ptra, int *m)
{
    int i;
    int j;
    printf("enter the value");
    scanf("%d", &j);

    for (i = 0; i < *m; i++)
    {

        if (j == *ptra)
        {
            printf("\nthe element exists at position %d is the %dth element\n", i, i + 1);
        }
        ptra++;
    }
    return 0;
}

int traverse(int *ptra, int *m)
{
    int i;
    for (i = 0; i < *m; i++)
    {

        printf("\n%d", *ptra);
        ptra++;
    }
    return 0;
}



int main()
{
    int n;
    printf("enter the length of array");
    scanf("%d", &n);
    int a[n];

    int i;
    printf("enter the elements");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int *ptr = &a[0];
    int *q = &n;
    while (1)
    {
        int choice;
        printf("\nPress 1 to insert.\n");
        printf("Press 2 to delete\n");
        printf("Press 3 to lenear search\n");
        printf("Press 4 to traverse\n");
        printf("Press 5 to exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert(ptr, q);
        }
        else if (choice == 2)
        {
            del(ptr, q);
        }
        else if (choice == 3)
        {
            lsearch(ptr, q);
        }
        else if (choice == 4)
        {
            traverse(ptr, q);
        }
        else if (choice == 5)
        {
            break;
        }
    }
}