#include<stdio.h>
struct student
{
    char name;
    char desig;
    int bsal;
    int hra;
    int da;
    int gross;

};

void read(struct student *k)
{
   for (int i = 0; i < 5; i++)
   {
    int sum=(*(k+i)).m1+(*(k+i)).m2+(*(k+i)).m3;
    if ((sum/5)<50)
    {
        printf("%d\n",(*(k+i)).roll);
    }
   }
   
}

int main()
{
    printf("enter number of entries");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&s[i].roll);
        scanf("%d",&s[i].m1);
        scanf("%d",&s[i].m2);
        scanf("%d",&s[i].m3);
    }
    read(s);
}