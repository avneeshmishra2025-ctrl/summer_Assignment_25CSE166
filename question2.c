#include<stdio.h>
intmain(){
    int n,i;
    printf("enter a no");
    scanf("%d",&n);
    printf("multiplication table of %d:\n",n);
    for(i=1;i<=10;i++){
        printf("%d*%d=%d\n",n,i,n*i);
    }
    return 0;
}