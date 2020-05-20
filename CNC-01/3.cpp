#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int64_t mul(int64_t a, int64_t b){
    return ((a % mod) * (b % mod)) % mod;
}
int64_t power(int64_t a, int64_t b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a % mod;
    }
    else{
        int64_t x = power(a, b/2);
        if(b % 2 == 0){
            return (x%mod) * (x%mod);
        }
        else{
            return ((((x%mod) * (x%mod))%mod) * (a%mod))%mod;
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
    int t;
    cin>>t;
    while(t--){
 
        int64_t n;
        cin >> n;
        int64_t mod_inv = power(4, mod-2);
        if((n/4)%2 == 0){
            cout << (((power(2, n) + power(2, (n/2) + 1))%mod) * (mod_inv))%mod << "\n";
        }
        else{
            cout << (((power(2, n) - power(2, (n/2) + 1))%mod) * (mod_inv))%mod << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}