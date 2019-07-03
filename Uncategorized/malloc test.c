#include<stdio.h>
int main(){
    int n,size;
    scanf("%d",&n);
    size=n*sizeof(int);
    int* a=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",(a+i));
    }
    for(int i=0;i<n;i++){
          printf("%d",*(a+i));
    }

    return 0;
}
