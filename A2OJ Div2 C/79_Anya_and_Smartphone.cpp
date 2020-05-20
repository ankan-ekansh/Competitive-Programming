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
    ll a[n];
    // ll order[n+7] = {0}, pageno[n+7] = {0};
    // map<ll, ll> order, pageno;
    ll order[n+7] = {0}, pageno[n+7] = {0};
    for(ll i=0;i<n;i++){
        cin >> a[i];
        order[a[i]] = i;
        pageno[a[i]] = i/k + 1;
    }
    ll ans = 0;
    while(m--){
        ll x;
        cin >> x;
        ans += pageno[x];
        // cout << x << " needs " << pageno[x] << " operations\n";
        ll x_idx = order[x];
        ll prev_idx = x_idx - 1;
        ll prev = a[prev_idx];
        // cout << "Before " << x << " at index " << order[x] << " we have " << prev << " at index " << prev_idx << "\n";
        // if(order[x] % k == 0 && pageno[x] > 1){
        //     pageno[x]--;
        //     pageno[prev]++;
        //     cout << "Page shifted\n";
        // }
        // if(order[x] > 0){
        //     // order[x]--;
        //     // order[prev]++;
        //     cout << "Frequent used moved prev\n";
        //     cout << x << " is now at " << order[x] << " and " << prev << " is now at " << order[prev] << "\n";
        // }
        if(prev_idx >= 0 && x != prev){
            ll temp = order[x];
            order[x] = order[prev];
            order[prev] = temp;
            swap(a[x_idx], a[prev_idx]);
            if(pageno[x] != pageno[prev]){
                temp = pageno[x];
                pageno[x] = pageno[prev];
                pageno[prev] = temp;
            }
        }
    }
    // for(ll i=0;i<n;i++){
    //     cout << i << " " << a[i] << " " << order[a[i]] << " " << pageno[a[i]] << "\n";
    // }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}