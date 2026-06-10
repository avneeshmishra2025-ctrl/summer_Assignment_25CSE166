#include<stdio.h>
int main()
{int num,x, reverse=0;
printf("enter a number");
scanf("%d",&num);
int original=num;
while (num!=0){
    x=num%10;
    num=num/10;
    reverse=reverse*10 +x;
}
if(original==reverse) 
printf("no is palindrome");
else
printf("no is not palindrome");
return 0;
}