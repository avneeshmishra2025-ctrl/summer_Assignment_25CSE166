#include<stdio.h>
int main() {//print prime numbers in a range
    int i,j,n, prime;
    
    printf("enter the value of n for end point of range");
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        prime=1;
    
        for(j=2;j<i;j++){
           
            if(i%j==0){
                prime=0;
            
        }
    }if(prime==1)
    printf("%d\n",i);}
    return 0;


}