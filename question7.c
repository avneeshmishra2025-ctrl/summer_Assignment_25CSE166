#include<stdio.h>
int main()
{int product=1, num,x;
    printf("enter a number");
    scanf("%d",&num);
    while(num!=0)
{x=num%10;
num=num/10;
product=product*x;
}
printf("product=%d",product);
    return 0;
}