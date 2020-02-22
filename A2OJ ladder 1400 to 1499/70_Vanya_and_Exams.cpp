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
ll n, r, avg;
bool comp(pair<int, int> p1, pair<int, int> p2){
    // return (double)(r-p1.first)/(double)p1.second > (double)(r-p2.first)/(double)p2.second;
    return p1.second < p2.second;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> r >> avg;
    ll a[n], b[n];
    pair<int, int> p[n];
    ll sum = 0, rsum = avg*n;
    for(ll i=0;i<n;i++){
        cin >> a[i] >> b[i];
        sum+=a[i];
        p[i]={a[i], b[i]};
    }
    // ll c[n];
    // for(ll i=0;i<n;i++){
    //     c[i] = min((n*avg)-sum, r);
    // }
    sort(p, p+n, comp);
    ll ans = 0;
    // cout << sum << " " << rsum << "\n";
    for(ll i=0;i<n;i++){
        // cout << p[i].first << " " << p[i].second << "\n";
        if(sum < rsum){
            // ans+=(r-p[i].first)*p[i].second;
            ans+=min((rsum - sum)*p[i].second, (r-p[i].first)*p[i].second);
            sum+=(r-p[i].first);
        }
        if(sum >= rsum){
            break;
        }
    }
    // cout << sum << " " << rsum << "\n"; 
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}