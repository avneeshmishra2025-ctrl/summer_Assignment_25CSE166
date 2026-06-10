#include<stdio.h>
int main(){
    int x ,sum=0,num;
    printf("enter the number");
    scanf("%d",&num);
    while(num!=0){
    x=num%10;
    num=num/10;
    sum=sum+x;}
    printf("sum=%d",sum);
    return 0;
}