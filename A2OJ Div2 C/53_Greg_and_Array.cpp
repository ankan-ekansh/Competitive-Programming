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
    ll a[n+7] = {0}, b[n+7] = {0};
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<pair<pair<ll, ll>, pair<ll, ll>>> v(m+7);
    for(ll i=1;i<=m;i++){
        ll l, r, d;
        cin >> l >> r >> d;
        v[i] = {{l, d}, {r+1, d}};
    }
    // for(ll i=1;i<=m;i++){
    //     cout << "operation " << i << " makes " << v[i].first.first << " increase by " << v[i].first.second << " & " << v[i].second.first << " decrease by " << v[i].second.second << "\n";
    // }
    ll times[m+7] = {0};
    for(ll i=1;i<=k;i++){
        ll x, y;
        cin >> x >> y;
        times[x]++;
        times[y+1]--;
    }
    for(ll i=1;i<=m;i++){
        times[i] += times[i-1];
        // cout << "operation " << i << " is done " << times[i] << " times\n";
    }
    for(ll i=1;i<=m;i++){
        // times[i] += times[i-1];
        b[v[i].first.first] = b[v[i].first.first] + (v[i].first.second)*times[i];
        b[v[i].second.first] = b[v[i].second.first] - (v[i].second.second)*times[i];
    }
    for(ll i=1;i<=n;i++){
        b[i] += b[i-1];
        // cout << b[i] << " ";
        cout << a[i]+b[i] << " ";
    }
    cout << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}