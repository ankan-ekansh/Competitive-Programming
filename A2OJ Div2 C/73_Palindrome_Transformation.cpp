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
    
    ll n, p;
    cin >> n >> p;
    p--;
    string s;
    cin >> s;
    if(p >= n/2){
        reverse(s.begin(), s.end());
        p = n - 1 - p;
    }
    ll l=p, r=p;
    ll changes = 0;
    for(ll i=0;i<n/2;i++){
        // cout << i << "\n";
        if(s[i] != s[n-i-1]){
            l = min(l, i);
            r = max(r, i);
            // changes+=abs((s[i] - s[n-i-1] - 26));
            changes+=min((s[i] - s[n-i-1] + 26)%26, (s[n-i-1] - s[i] + 26)%26);
        }
    }
    // cout << l << " " << r << " : " << p << "\n";
    // cout << changes << "\n";
    // cout << abs(p-l) + r - l << " " << abs(r-p) + r - l << "\n";
    cout << min(abs(p-l) + r - l, abs(r-p) + r - l) + changes << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}