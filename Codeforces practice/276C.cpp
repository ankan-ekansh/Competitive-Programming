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
    
    ll n, q;
    cin >> n >> q;
    ll a[n+1];
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<pair<ll, ll>> vq;
    ll b[n+1] = {0};
    for(ll i=0;i<q;i++){
        ll l, r;
        cin >> l >> r;
        vq.push_back({l, r});
        b[l]++;
        b[r+1]--;
    }
    for(ll i=2;i<=n;i++){
        b[i]+=b[i-1];
    }
    // sort(b+1, b+n+1, greater<ll>());
    vector<pair<ll, ll>> v;
    for(ll i=1;i<=n;i++){
        // cout << b[i] << " ";
        v.push_back({b[i], i});
    }
    // cout << "\n";
    sort(v.begin(), v.end());
    ll c[n+1];
    sort(a+1, a+n+1, greater<ll>());
    ll j = 1;
    for(ll i=v.size()-1;i>=0;i--){
        c[v[i].second] = a[j++];
    }
    ll s[n+1] = {0};
    s[1] = c[1];
    for(ll i=2;i<=n;i++){
        s[i]+=s[i-1]+c[i];
    }
    ll ans = 0;
    for(ll i=0;i<vq.size();i++){
        ll x = vq[i].first;
        ll y = vq[i].second;
        ans+=(s[y] - s[x-1]);
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}