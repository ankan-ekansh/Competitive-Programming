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
int gcd3(int a, int b, int c){
    return __gcd(a, __gcd(b, c));
}
int gcd4(int a, int b, int c, int d){
    return __gcd(a, __gcd(b, __gcd(c, d)));
}
int lcm2(int a, int b){
    return (a*b)/__gcd(a,b);
}
int lcm3(int a, int b, int c){
    return lcm2(a, lcm2(b, c));
}
int lcm4(int a, int b, int c, int d){
    return lcm2(lcm2(a, b), lcm2(c, d));
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    int n1 = d/k + d/l + d/m + d/n;
    int n2 = d/lcm2(k, l) + d/lcm2(l, m) + d/lcm2(m, n) + d/lcm2(n, k) + d/lcm2(k, m) + d/lcm2(l, n);
    int n3 = d/lcm3(k, l, m) + d/lcm3(l, m, n) + d/lcm3(m, n, k) + d/lcm3(n, k, l);
    int n4 = d/lcm4(k, l, m, n);
    int ans = n1 - n2 + n3 - n4;
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}