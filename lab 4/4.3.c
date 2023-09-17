#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int co;
    int expo;
    struct NODE *next;
};
typedef struct NODE node;

node *poly(node *);
node *add(node *, node *);

node *poly(node *head)
{
    node *temp, *new;
    int mp;
    printf("enter the maximum power");
    scanf("%d", &mp);
    while (mp >= 0)
    {
        new = (node *)malloc(sizeof(node));
        printf("enter the coeff of x^%d", mp);
        scanf("%d", &(new->co));
        new->expo = mp;
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            temp = head;
        }
        else
        {
            temp->next = new;
            temp = temp->next;
        }
        mp--;
    }
    return head;
}

node *add(node *head1, node *head2)
{
    node *head3, *temp1, *temp2, *new, *temp3;
    head3 = NULL;
    temp1 = head1;
    temp2 = head2;
    while ((temp1->next != NULL) || (temp2->next != NULL))
    {
        new = (node *)malloc(sizeof(node));
        if (head3 == NULL)
        {
            head3 = new;
            temp3 = head3;
        }
        if (temp1->expo > temp2->expo)
        {
            new->co = temp1->co;
            new->expo = temp1->expo;
            new->next = NULL;
            temp1 = temp1->next;
            temp3->next = new;
            temp3 = temp3->next;
        }
        else if (temp2->expo > temp1->expo)
        {
            new->co = temp2->co;
            new->expo = temp2->expo;
            new->next = NULL;
            temp2 = temp2->next;
            temp3->next = new;
            temp3 = temp3->next;
        }
        else
        {
            new->co = temp2->co + temp1->co;
            new->expo = temp2->expo;
            new->next = NULL;
            temp2 = temp2->next;
            temp1 = temp1->next;
            temp3->next = new;
            temp3 = temp3->next;
        }
    }
    if (temp1->next == NULL)
    {
        new = (node *)malloc(sizeof(node));
        new->co = temp2->co + temp1->co;
        new->expo = temp2->expo;
        new->next = NULL;
        temp2 = temp2->next;
        temp1 = temp1->next;
        temp3->next = new;
        temp3 = temp3->next;
        return head3;
    }
    if (temp2->next == NULL)
    {
        new = (node *)malloc(sizeof(node));
        new->co = temp2->co + temp1->co;
        new->expo = temp2->expo;
        new->next = NULL;
        temp2 = temp2->next;
        temp1 = temp1->next;
        temp3->next = new;
        temp3 = temp3->next;
        return head3;
    }
    return 0;
}

void traverse(node *temp)
{
    while (temp != NULL)
    {
        if (temp->co < 0)
        {
            printf("%dx^%d", temp->co, temp->expo);
            temp = temp->next;
        }
        else
        {
            printf("+%dx^%d", temp->co, temp->expo);
            temp = temp->next;
        }
    }
}
int main()
{
    node *head1, *head2;
    head1 = NULL;
    head2 = NULL;

    printf("polynomial 1\n");
    head1 = poly(head1);
    printf("polynomial 2\n");
    head2 = poly(head2);
    node *head3 = add(head1, head2);
    printf("sum is\n");
    traverse(head3);
}