#include <stdio.h>
#include <stdlib.h>
struct complex
{
  int real;
  int img;
};
typedef struct complex cmp;
void sum(cmp a,cmp b,cmp c)
{ 
  c.real = a.real + b.real;
  c.img = a.img + b.img;

  if (c.img >= 0)
    printf("Sum of the complex numbers = %d + %di\n", c.real, c.img);
  else
    printf("Sum of the complex numbers = %d %di\n", c.real, c.img);
  return ;
}
void multi(cmp* ptra,cmp* ptrb,cmp* ptrc)
{
  ptrc->real = ptra->real*ptrb->real - ptra->real*ptrb->img;
  ptrc->img = ptra->img*ptrb->real + ptra->real*ptrb->img;

  if (ptrc->img >= 0)
    printf("Multiplication of the complex numbers = %d + %di\n", ptrc->real, ptrc->img);
  else
    printf("Multiplication of the complex numbers = %d %di\n", ptrc->real, ptrc->img);
}
int main()
{
  int choice;
  cmp a, b, c;
  cmp* ptra;
  cmp* ptrb;
  cmp* ptrc;
  ptra =&a;
  ptrb =&b;
  ptrc =&c;
  while(1)
  {
    printf("Press 1 to add two complex numbers.\n");
    printf("Press 2 to multiply two complex numbers\n");
    printf("Press 3 to exit\n");
    scanf("%d", &choice);
    

    if (choice>=1 && choice<=2)
    {
        printf("Enter a and b where a + ib is the first complex number.");
        printf("\na = ");
        scanf("%d", &a.real);
        printf("b = ");
        scanf("%d", &a.img);
        printf("Enter c and d where c + id is the second complex number.");
        printf("\nc = ");
        scanf("%d", &b.real);
        printf("d = ");
        scanf("%d", &b.img);
        if (choice == 1)
        {
          sum(a,b,c);
        }
        else if (choice == 2)
        {
          multi(ptra,ptrb,ptrc);
        }
    }
    
    else if (choice==3)
      exit(0);
  }
    
}