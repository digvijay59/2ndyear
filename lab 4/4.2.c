#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int info;
    struct NODE *next;
};
typedef struct NODE node;
void traverse(node *temp);
void insert(node *temp, int);
node *delete(node *temp);
int count(node *temp);
void search(node *temp);
node *reverse(node *head);
node *sort(node *head);

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

void search(node *temp)
{
    int val;
    printf("enter value to serach for");
    scanf("%d", &val);
    while (temp != NULL)
    {
        if (temp->info == val)
        {
            printf("%d is found", temp->info);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("not found");
    }
}

node *sort(node *head)
{
    node *temp1;
    node *temp2;
    temp1 = head;
    int res;
    while (temp1 != NULL)
    {
        temp2 = head;
        while (temp2->next != NULL)
        {
            if (temp2->info > temp2->next->info)
            {
                res = temp2->info;
                temp2->info = temp2->next->info;
                temp2->next->info = res;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head;
}

node *reverse(node *head)
{
    node *temp1;
    node *temp2;
    node *temp3;
    temp1 = head;
    temp2 = temp1->next;
    temp3 = temp2->next;
    temp1->next = NULL;
    while (temp3 != NULL)
    {
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
    }
    temp2->next = temp1;
    head = temp2;
    return head;
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
        scanf("%d", &(new->info));
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
        printf("5 to search\n");
        printf("6 to sort\n");
        printf("7 to reverse\n");
        printf("8 to exit\n");
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
            search(head);
        }
        else if (b == 6)
        {
            head = sort(head);
        }
        else if (b == 7)
        {
            head = reverse(head);
        }
        else if (b == 8)
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