#include<bits/stdc++.h>
using namespace std;
int primes[100000];
int sieve(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*2;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    int k=0;
    for(int p=2;p<=n;p++)
        if(prime[p])
            primes[k++]=p;
    return k;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int flag=0;
        int c=0;
        int k=sieve(n);
        int sp[((k*k)-k)/2];
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(primes[i]*primes[j] <=n){
                        sp[c++]=primes[i]*primes[j];
                }
            }
        }
        sort(sp,sp+c);
        for(int i=0;i<c;i++){
            for(int j=i;j<c;j++){
                if(sp[i]+sp[j] == n){
                        flag=1;
                        break;
                }
            }
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
