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
bool comp(pair<ll, ll> p, pair<ll, ll> q){
    double d1, d2;
    d1 = (double)p.first/(double)p.second;
    d2 = (double)q.first/(double)q.second;
    return d1 > d2;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, z, x, y;
    cin >> n >> z >> x >> y;
    ll c[n], p[n];
    pair<ll, ll> a[n];
    for(ll i=0;i<n;i++){
        cin >> c[i];
        a[i].second = c[i];
    }
    for(ll i=0;i<n;i++){
        cin >> p[i];
        a[i].first = p[i];
    }
    ll ans = 0;
    ll cost = 0;
    sort(a, a+n, comp);
    if(n == 1){
        if(a[0].second <= z)
            cout << a[0].first * max(x, y) << "\n";
        else
            cout << "0\n";
    }
    else{
        if(a[0].second + a[1].second <= z){
            ans = max(x*a[0].first + y*a[1].first, x*a[1].first + y*a[0].first);
            cost+=a[0].second + a[1].second;
        }
        else{
            ans = max(x, y) * a[0].first;
            cost+=a[0].second;
        }
    }
    for(ll i=2;i<n;i++){
        // if(i == 0 && cost + a[i].second <= z){
        //     cost+=a[i].second;
        //     ans+=(max(x, y) * a[i].first);
        // }
        // else if(i == 1 && cost + a[i].second <= z){
        //     cost+=a[i].second;
        //     ans+=(min(x, y) * a[i].first);
        // }
        
            if(cost + a[i].second <= z){
                cost+=a[i].second;
                ans+=a[i].first;
            }
            else{
                break;
            }
    }
    
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}