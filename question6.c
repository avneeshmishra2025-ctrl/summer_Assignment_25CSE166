#include<stdio.h>
int main(){//program to reverse a number
    int num,x ,sum=0;
    printf("enter a num");
    scanf("%d",&num);
    while(num!=0){
        x=num%10;
        num=num/10;
        sum=sum*10+x;

    }
    printf("sum=%d",sum);

    return 0;
}