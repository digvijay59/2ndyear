#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int info;
    struct NODE *next;
};
typedef struct NODE node;
void traverse(node *temp);
void insert(node *, int);
node *delete(node *temp);
int count(node *temp);

void traverse(node *temp)
{
    printf("the entered linked list is\n");
    while (temp != NULL)
    {
        printf("%d-->>", temp->info);
        temp = temp->next;
    }
}

void insert(node *temp, int count)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    int pos, val, cnt = 0;
    printf("enter the pos");
    scanf("%d", &pos);
    printf("enter the value");
    scanf("%d", &val);
    new->info = val;
    pos--;
    while (temp != NULL && pos < count)
    {
        cnt++;
        if (pos == cnt)
        {
            break;
        }
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
}

node *delete(node *head)
{
    node *temp = head;
    int val;
    printf("enter the value to be deleted");
    scanf("%d", &val);
    if (temp->info == val)
    {
        head = temp->next;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next->info == val)
            {
                break;
            }
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    return head;
}

int count(node *temp)
{
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{
    char a;
    node *head = NULL;
    node *new, *temp;
    new = (node *)malloc(sizeof(node));
    printf("Enter a value: ");
    scanf("%d", &(new->info));
    new->next = NULL;
    head = new;
    temp = new;
    printf("do you want to continue");
    scanf(" %c", &a);
    while (a == 'y')
    {
        new = (node *)malloc(sizeof(node));
        printf("Enter a value: ");
        scanf("%d", &new->info);
        new->next = NULL;
        temp->next = new;
        temp = temp->next;
        printf("do you want to continue");
        scanf(" %c", &a);
    }

    while (1)
    {
        int b;
        printf("\n1 to insert\n");
        printf("2 to delete\n");
        printf("3 to count\n");
        printf("4 to traverse\n");
        printf("5 to exit");
        scanf("%d", &b);

        if (b == 1)
        {
            insert(head, count(head));
        }
        else if (b == 2)
        {
            head = delete (head);
        }
        else if (b == 3)
        {
            printf("number of nodes=%d", count(head));
        }
        else if (b == 4)
        {
            traverse(head);
        }
        else if (b == 5)
        {
            break;
        }
        else
        {
            printf("invalid");
        }
    }
    return 0;
}