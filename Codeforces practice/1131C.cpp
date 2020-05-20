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
    ll t;
    cin>>t;
    while(t--){
 
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        ll a[26][n+7];
        memset(a, 0, sizeof(a));
        for(ll i=0;i<=25;i++){
            char c = (char)(i+'a');
            for(ll j=1;j<=n;j++){
                if(c == s[j-1]){
                    a[i][j] = a[i][j-1] + 1;
                }
                else{
                    a[i][j] = a[i][j-1];
                }
            }
        }
        ll p[m+7] = {0};
        for(ll i=0;i<m;i++){
            cin >> p[i];
        }
        for(ll i=0;i<26;i++){
            ll ans = 0;
            for(ll j=0;j<m;j++){
                ans+=(a[i][p[j]]);
            }
            ans+=a[i][s.length()];
            cout << ans << " ";
        }
        cout << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}