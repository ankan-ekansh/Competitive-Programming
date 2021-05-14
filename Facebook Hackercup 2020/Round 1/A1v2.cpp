/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
ll mul(ll a, ll b, ll m){
    return ((a % m) * (b % m)) % m;
}
ll add(ll a, ll b, ll m){
    return ((a % m) + (b % m)) % m;
}
ll sub(ll a, ll b, ll m){
    return ((a % m) - (b % m) + m) % m;
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
    ll tc = 1;
    while(t--){
        
        cout << "Case #" << tc++ << ": ";
        ll n, k, w;
        ll al, ah, bl, bh, ch, cl, dl, dh;
        cin >> n >> k >> w;
        ll l[n] = {0}, h[n] = {0};
        for(ll i=0;i<k;i++){
            cin >> l[i];
        }
        cin >> al >> bl >> cl >> dl;
        for(ll i=0;i<k;i++){
            cin >> h[i];
        }
        cin >> ah >> bh >> ch >> dh;
        if(k < n){
            for(ll i=k;i<n;i++){
                // l[i] = (((((((al % dl)*(l[i-2] % dl)) % dl) + (((bl % dl)*(l[i-1] % dl)) % dl)) % dl + (cl % dl)) % dl) + 1) % dl;
                l[i] = add(add(mul(al, l[i-2], dl), mul(bl, l[i-1], dl), dl), cl, dl) + 1;
            }
            for(ll i=k;i<n;i++){
                // h[i] = (((((((ah % dh)*(h[i-2] % dh)) % dh) + (((bh % dh)*(h[i-1] % dh)) % dh)) % dh + (ch % dh)) % dh) + 1) % dh;
                h[i] = add(add(mul(ah, h[i-2], dh), mul(bh, h[i-1], dh), dh), ch, dh) + 1;
            }
        }
        for(ll i=0;i<n;i++){
            cout << l[i] << " ";
        }
        cout << "\n";
        for(ll i=0;i<n;i++){
            cout << h[i] << " ";
        }
        cout << "\n";
        ll ans = 1;
        ll prevl = l[0]+w, prevh = h[0];
        // ans = ((2 % mod)*(w % mod + prevh % mod)%mod) % mod;
        ll lb = l[0];
        ll pp[n+7] = {0};
        ll last = 0;
        pp[1] = ((2 % mod)*(w % mod + prevh % mod)%mod) % mod;
        for(ll i=1;i<n;i++){
            if(l[i] <= prevl){
                // prevl = l[i] + w;
                prevl = max(prevl, l[i] + w);
                prevh = max(prevh, h[i]);
                // ans = (ans % mod) * ((2 % mod) * ())
                // pp[i+1] = ((((2 % mod)*((prevl - lb) % mod + prevh % mod)%mod) % mod) + (last % mod)) % mod;
                pp[i+1] = add(last, mul(2, add(sub(prevl, lb, mod), prevh, mod), mod), mod);
            }
            else{
                last = pp[i];
                prevl = l[i] + w;
                lb = l[i];
                prevh = h[i];
                // pp[i+1] = ((last % mod) + ((2 % mod)*((prevl - lb) % mod + prevh % mod)%mod) % mod)%mod;
                pp[i+1] = add(last, mul(2, add(sub(prevl, lb, mod), prevh, mod), mod), mod);
            }
        }
        for(ll i=1;i<=n;i++){
            // ans = (ans % mod * pp[i] % mod) % mod;
            ans = mul(ans, pp[i], mod);
            cout << pp[i] << " ";
            // cout << ans << " ";
        }
        cout << " : ";
        cout << ans % mod << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}