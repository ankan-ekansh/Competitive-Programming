#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return binaryExponentiation(x*x,n/2);
    else
        return x*binaryExponentiation(x*x,(n-1)/2);
}
ll GCD(ll A, ll B){
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
ll modinv(ll a , ll mod){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
ll modPrimeInverse(ll A,ll M){
    return modularExponentiation(A,M-2,M);
}
unordered_map<ll, ll> spf;
unordered_map<ll, map<ll, ll>> m;
ll N = 1e7+7;
void sieve(){
    spf[1] = 1;
    for(ll i = 2; i < N; i++){
        spf[i] = i;
    }
    for(ll i=4;i<N;i+=2){
        spf[i] = 2;
    }
    for(ll i=3;i*i<N;i++){
        if(spf[i] == i){
            for(ll j=i*i;j<N;j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}
void getFactorization(ll x){
    ll tmp = x;
    while(x != 1){
        m[tmp][spf[x]]++;
        x = x / spf[x];
    }
}
// vector<ll> getFactorization(ll x){ 
//     ll tmp = x;
//     vector<ll> ret; 
//     while (x != 1){ 
//         ret.push_back(spf[x]); 
//         m[tmp][spf[x]]++;
//         x = x / spf[x]; 
//     } 
//     return ret; 
// }
#define mod 1000000007
int main(){
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "rt", stdin);
        // freopen("output3.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    sieve();
    // getFactorization(42608);
    // for(auto p : m[42608]){
    //     cout << p.first << " ^ " << p.second << " * ";
    // }
    // vector<ll> v = getFactorization(42608);
    // for(auto x : v){
    //     cout << x << " ";
    // }
    // for(ll i=2;i<=100000;i++){
        // getFactorization(i);
        // cout << i << " : ";
        ll i = 100LL * 200LL * 300LL;
        getFactorization(i);
        ll ans = 1LL;
        for(auto p : m[i]){
            // cout << p.first << " ^ " << p.second << " * ";
            ans = (ans * (p.second + 1)%mod)%mod;
        }
        cout << ans << "\n";
    // }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}