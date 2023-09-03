#include <stdio.h>
#include <stdlib.h>
void enter(int rows, int cols);
void formatting(int **ptr1, int rows, int cols, int nz);
void printing(int **ptr2, int nz);

void enter(int rows, int cols)
{
    int nz = 0;
    int **ptr1 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        ptr1[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("enter a sparce matrix");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &ptr1[i][j]);
            if (ptr1[i][j] != 0)
            {
                nz++;
            }
        }
    }
    formatting(ptr1, rows, cols, nz);
}

void formatting(int **ptr1, int rows, int cols, int nz)
{
    /*printf("entered matrix is\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d", ptr1[i][j]);
        }
        printf("\n");
    }*/

    int **ptr2 = (int **)malloc((nz + 1) * sizeof(int *));
    for (int i = 0; i < nz + 1; i++)
    {
        ptr2[i] = (int *)malloc(3 * sizeof(int));
    }
    ptr2[0][0] = rows;
    ptr2[0][1] = cols;
    ptr2[0][2] = nz;
    int s = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (ptr1[i][j] != 0)
            {
                ptr2[s][0] = i;
                ptr2[s][1] = j;
                ptr2[s][2] = ptr1[i][j];
                s++;
            }
        }
    }
    printing(ptr2, nz);
}

void printing(int **ptr2, int nz)
{
    printf("sparse matrix in 3-tuple format\n");
    for (int i = 0; i < nz + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%5d", ptr2[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows, cols;
    printf("enter the number of rows\n");
    scanf("%d", &rows);
    printf("enter the number of columns\n");
    scanf("%d", &cols);
    enter(rows, cols);
}