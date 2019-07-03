#include<stdio.h>
int main(){
    int a[100];
    int n;
    a[0]=1;
    a[1]=1;
    scanf("%d",&n);
    printf("1\n");
    for(int i=1;i<n;i++){
        a[i+1]=a[i]+a[i-1];
        for(int j=0;j<=i;j++){
            printf("%d ",a[j]);
        }
        printf("\n");
    }
    return 0;
}
