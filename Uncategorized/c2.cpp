#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int ar[100];
    int k=0;
    unsigned int a,b,c,d,mod;
    scanf("%d",&t);
    while(t--){
        scanf("%lu %lu %lu %lu %lu",&a,&b,&c,&d,&mod);
        ar[k++]=((a%mod)+(b%mod)*(c%mod)-(d%mod))%mod;
    }
    for(int i=0;i<k;i++){
        printf("%ld",ar[i]);
        if(i!=(k-1))
            printf("\n");
    }
    return 0;
}
