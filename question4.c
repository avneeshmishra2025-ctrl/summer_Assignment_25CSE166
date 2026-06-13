#include <stdio.h>
int main(){
    int n,count=0;
    printf("enter a no");
    scanf("%d",&n);
    while(n!=0){
        n=n/10;
        count++;
    }
    printf("no of digit=%d\n",count);
    return 0;
}
