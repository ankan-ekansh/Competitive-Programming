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
    
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> v;
    ll k = 0;
    ll f[n+1] = {0};
    for(ll i=0;i<n;i++){
        ll x, y;
        cin >> x >> y;
        // v.push_back(x);
        // f[x] = y;
        v.push_back({x, k});
        f[k++] = y;
    }
    sort(v.begin(), v.end());
    ll pf[n+7] = {0};
    pf[0] = f[v[0].second];
    vector<ll> w;
    w.push_back(v[0].first);
    for(ll i=1;i<v.size();i++){
        pf[i] = pf[i-1] + f[v[i].second];
        w.push_back(v[i].first);
    }
    // for(ll i=0;i<v.size();i++){
    //     cout << v[i].first << " " << v[i].second << " " << pf[i] << "\n";
    // }
    // for(ll i=0;i<w.size();i++){
    //     // cout << v[i].first << " " << v[i].second << " " << pf[i] << "\n";
    //     cout << w[i] << " " << pf[i] << "\n";
    // }
    ll ans = 0;
    ll i=0, j=0;
    ll temp = 0;
    for(;i<w.size() && j<w.size();){
        // ll temp = 0;
        // cout << i << " " << j << "\n";
        if(abs(w[j] - w[i]) < d){
            j++;
            continue;
        }
        else{
            j--;
            if(i != 0){
                // cout << pf[j] - pf[i-1] << "\n";
                temp=pf[j] - pf[i-1];
            }
            else{
                // cout << pf[j] << "\n";
                temp=pf[j];
            }
            // i++;
            // j = i;
            ans = max(ans, temp);
            // temp = 0;
            j++;
            while(w[i] + d <= w[j] && i < j){
                i++;
            }
            // temp-=pf[i-1];
        }
        // ans = max(ans, temp);
    }
    j--;
    if(i != 0){
        // cout << pf[j] - pf[i-1] << "\n";
        temp=pf[j] - pf[i-1];
    }
    else{
        // cout << pf[j] << "\n";
        temp=pf[j];
    }
    ans = max(ans, temp);
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}