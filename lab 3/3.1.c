#include <stdio.h>
#include <stdlib.h>

void transpose(int **ptr, int **transposePtr, int rows, int cols, int nz)
{

    transposePtr[0][0] = cols;
    transposePtr[0][1] = rows;
    transposePtr[0][2] = nz;

    int *rowSize = (int *)calloc(cols, sizeof(int));

    for (int i = 1; i <= nz; i++)
    {
        int col = ptr[i][1];
        rowSize[col]++;
    }

    int *rowStart = (int *)calloc(cols, sizeof(int));
    int *rowIndex = (int *)malloc(cols * sizeof(int));

    rowStart[0] = 1;
    rowIndex[0] = 1;

    for (int i = 1; i < cols; i++)
    {
        rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        rowIndex[i] = rowStart[i];
    }

    // Populate the transpose matrix with the values from the original matrix
    for (int i = 1; i <= nz; i++)
    {
        int col = ptr[i][1];
        int index = rowIndex[col];
        transposePtr[index][0] = ptr[i][1];
        transposePtr[index][1] = ptr[i][0];
        transposePtr[index][2] = ptr[i][2];
        rowIndex[col]++;
    }

    free(rowSize);
    free(rowStart);
    free(rowIndex);
}

void printMatrix(int **ptr, int rows)
{
    printf("    R   C  ELEMENT\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%5d", ptr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows, cols, nz;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &nz);

    int **ptr = (int **)malloc((nz + 1) * sizeof(int *));
    int **transposePtr = (int **)malloc((nz + 1) * sizeof(int *));

    for (int i = 0; i <= nz; i++)
    {
        ptr[i] = (int *)malloc(3 * sizeof(int));
        transposePtr[i] = (int *)malloc(3 * sizeof(int));
    }
    ptr[0][0] = rows;
    ptr[0][1] = cols;
    ptr[0][2] = nz;

    printf("Enter the sparse matrix:\n");
    for (int i = 1; i <= nz; i++)
    {
        scanf("%d %d %d", &ptr[i][0], &ptr[i][1], &ptr[i][2]);
    }

    transpose(ptr, transposePtr, rows, cols, nz);

    printf("\nOriginal Matrix:\n");
    printMatrix(ptr, nz + 1);

    printf("\nTranspose Matrix:\n");
    printMatrix(transposePtr, nz + 1);
}