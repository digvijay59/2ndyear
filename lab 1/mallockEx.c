#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char title[10];
    char author[30];
    char publication[30];
    float price;
};

typedef struct book BOOK;

int main()
{
    BOOK *ptr;
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);

    ptr = (BOOK *)malloc(n * sizeof(BOOK));

    for (int i = 0; i < n; i++)
    {
        char c;
        printf("Enter the title: ");
        scanf("%s%c", ptr[i].title, &c);

        printf("Enter the author: ");
        scanf("%s%c", ptr[i].author, &c);

        printf("Enter the publication: ");
        scanf("%s%c", ptr[i].publication, &c);

        printf("Enter the price: ");
        scanf("%f", &ptr[i].price);
    }

    char particular_author[30];
    printf("Enter the particular author name: ");
    scanf("%s", particular_author);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(ptr[i].author, particular_author) == 0)
        {
            printf("\n\nDisplaying data of %s\n--\n", particular_author);

            printf("Title: %s\n", ptr[i].title);
            printf("Author: %s\n", ptr[i].author);
            printf("Publication: %s\n", ptr[i].publication);
            printf("Price: %f\n", ptr[i].price);
        }
    }
    return 0;
}