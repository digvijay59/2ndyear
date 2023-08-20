#include<stdio.h>
#include<stdlib.h>
struct employee
{
    char name[30];
    char desig[30];
    int bsal;
    float hra;
    float da;
    float gross;
};
typedef struct employee emp;
int main()
{
    emp *ptr;
    int n;
    float grs;
    printf("enter number of employees");
    scanf("%d", &n);
    ptr = (emp *)malloc(n * sizeof(emp));
    for (int i = 0; i < n; i++)
    {   
        printf("details of employee %d",i+1);
        
        printf("\nEnter name: ");
        scanf("%s", ptr[i].name);

        printf("Enter the designation: ");
        scanf("%s", ptr[i].desig);

        printf("Enter base salary: ");
        scanf("%d", &ptr[i].bsal);

        printf("Enter the hra: ");
        scanf("%f%%", &ptr[i].hra);

        printf("Enter the da: ");
        scanf("%f%%", &ptr[i].da);

        grs=(ptr[i].bsal+(((ptr[i].hra/100)*(ptr[i].bsal))+((ptr[i].da/100)*ptr[i].bsal)));
        ptr[i].gross=grs;

    }
        printf("employee information");
    for (int i = 0; i < n; i++)
    {
        printf("\nname is %s",ptr[i].name);
        printf("\ndesig is %s",ptr[i].desig);
        printf("\nbase sal is %d",ptr[i].bsal);
        printf("\nhra is %f",ptr[i].hra);
        printf("\nda is %f",ptr[i].da);
        printf("\nhra value is %f",((ptr[i].hra/100)*(ptr[i].bsal)));
        printf("\nda value is %f",((ptr[i].da/100)*ptr[i].bsal));
        printf("\ngross is %f\n",ptr[i].gross);
    }
}
