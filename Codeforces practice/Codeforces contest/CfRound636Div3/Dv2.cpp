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
const ll N = 6e5 + 100;
const ll maxN = 1e16;
const ll oo = 1e18;
const ll mod  = 1e9 + 7;
 
ll n, k;
ll cnt[N];
ll maxn[N], minn[N];
ll a[N];
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
 
        ll n , k;
	 	cin >> n >> k;
        for(ll i=1;i<=n;i++)
            cin >> a[i];
        for(ll i=1;i<=n/2;i++){
            maxn[i] = max(a[i], a[n - i + 1]) + k, cnt[ a[i] + a[n - i + 1] ] ++;
            minn[i] = min(a[i], a[n - i + 1]);
        }
        sort(maxn + 1, maxn + n / 2 + 1);
        sort(minn + 1, minn + n / 2 + 1);
        ll ans = oo;
        for(ll i=1;i<=2*k;i++){
            ll val = i;
            ll pos1 = lower_bound(maxn + 1, maxn + n / 2 + 1, val) - maxn - 1;
            ll pos2 = lower_bound(minn + 1, minn + n / 2 + 1, val) - minn;
 
            pos2 = n / 2 - pos2 + 1;
 
            ll tmp = (pos1 + pos2) * 2 + (n / 2 - pos1 - pos2) - cnt[ val ];
            ans = min(ans, tmp);
        }
        for(ll i=1;i<=n/2;i++)
            cnt[ a[i] + a[n - i + 1] ] --;
        cout << ans << '\n';
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}