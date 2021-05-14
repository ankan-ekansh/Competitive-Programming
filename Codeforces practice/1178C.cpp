/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
const ll mod = 998244353;
using namespace std;
ll power(ll a, ll b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a % mod;
    }
    ll x = power(a, b/2);
    if(b % 2 == 0){
        return (x % mod * x % mod) % mod;
    }
    else{
        return ((x % mod * a % mod) * (x % mod)) % mod;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll w, h;
    cin >> w >> h;
    ll n = w+h;
    cout << power(2, n) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}