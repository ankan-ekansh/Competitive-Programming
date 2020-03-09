#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int64_t fact[2000007];
void factorial(){
    fact[0] = 1;
    fact[1] = 1;
    for(int64_t i=2;i<=2000000;i++){
        fact[i]=(fact[i-1] * i) % mod;
    }
}
int64_t power(int64_t a, int64_t b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a % mod;
    }
    else if(a == 1){
        return 1;
    }
    else{
        int64_t x = power(a, b/2);
        if(b % 2 == 0){
            return ((x % mod) * (x % mod)) % mod;
        }        
        else{
            return ((((x % mod) * (x % mod)) % mod) * (a % mod)) % mod;
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
    factorial();
    int t;
    cin>>t;
    while(t--){
 
        int64_t x, y;
        cin >> x >> y;
        cout << ((((fact[x + y]) * power(fact[x], mod - 2))  % mod) * power(fact[y], mod - 2)) % mod << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}