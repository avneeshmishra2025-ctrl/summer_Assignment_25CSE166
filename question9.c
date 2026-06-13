#include<stdio.h>
int main(){
    int x,i,n;
    printf("enter the number");
    scanf("%d",&n);
    for(i=2;i<n;i++){
       x=n%i;
    }
if(x==0){
printf("no is not prime");} 
else{
printf("no is  prime");}
return 0;
}