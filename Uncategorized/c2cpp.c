#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    long long int a,b,c,mod;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&mod);
        printf("%lld\n",(a + b*c - d)%mod);
    }
}
