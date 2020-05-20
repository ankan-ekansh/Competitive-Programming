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
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, m, k;
    cin >> n >> m >> k;
    pair<ll, ll> chips[k], finalchips[k];
    for(ll i=0;i<k;i++){
        cin >> chips[i].first >> chips[i].second;
    }
    for(ll i=0;i<k;i++){
        cin >> finalchips[i].first >> finalchips[i].second;
    }
    string ans;
    ll ops = 0;
    for(ll i=0;i<n-1;i++){
        ans += "U";
        ops++;
    }
    for(ll i=0;i<m-1;i++){
        ans += "L";
        ops++;
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m-1;j++){
            if(i % 2 == 0){
                ans += "R";
                ops++;
            }
            else{
                ops++;
                ans += "L";
            }
        }
        if(i != n-1){
            ops++;
            ans += "D";
        }
    }
    if(ops <= 2*m*n){
        cout << ans.length() << "\n";
        cout << ans << "\n";
        }
    else
        cout << "-1\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}