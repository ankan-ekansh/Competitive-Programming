#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
long long power(long long m, long long n){
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return m;
    }
    else{
        long long x = power(m, n/2);
        if(n % 2 == 0){
            return ((x%M)*(x%M))%M;
        }
        else{
            return ((( (x%M)*(m%M)) % M ) * (x%M) ) % M;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
 
        long long k;
        cin>>k;
        long long ans = (10*power(2,k-1))%M;
        cout<<ans<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}