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
bool comp(pair<ll, pair<ll, ll>> p, pair<ll, pair<ll, ll>> q){
    return (((double)p.second.second / (double)p.second.first) > ((double)q.second.second / (double)q.second.first));
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        ll n;
        cin >> n;
        pair<ll, ll> p[n];
        map<ll, ll> h;  //health of ith
        vector<pair<ll, pair<ll, ll>>> idx; //max damage / bullet values
        for(ll i=0;i<n;i++){
            cin >> p[i].first >> p[i].second;
            idx.push_back({i, {p[i].first, p[i].second}});
            // h[p[i].first]++;
            h[i] = p[i].first;
        }
        bool alive[n];
        memset(alive, true, sizeof(alive));
        sort(idx.begin(), idx.end(), comp);
        ll ans = 0;
        for(ll i=0;i<n;i++){
            // cout << idx[i].first << " " << idx[i].second.first << " " << idx[i].second.second << "\n";
            // if(h[idx[i].second.first])
            // cout << idx[i].first << " alive status " << alive[idx[i].first] << "\n";
            // cout << idx[i].first << " health " << h[idx[i].first] << "\n";
            if(alive[idx[i].first]){
                // ans += idx[i].second.first;
                ans += h[idx[i].first];
                // cout << ans << "\n";
                alive[idx[i].first] = false;
                h[idx[i].first] = 0;
                // if(alive[(idx[i].first + 1)%n]){
                //     h[(idx[i].first + 1)%n] -= idx[i].second.second;
                //     if(h[(idx[i].first + 1)%n] <= 0){
                //         alive[(idx[i].first + 1)%n] = false;
                //     }
                // }
                ll tmp = i;
                while(alive[(idx[tmp].first + 1)%n]){
                    // cout << "Tmp is now " << tmp << "\n";
                    // cout << "Explosions \n";
                    h[(idx[tmp].first + 1)%n] -= idx[tmp].second.second;
                    // cout << (idx[tmp].first + 1 )%n << " health " << h[(idx[tmp].first + 1)%n] << "\n";
                    if(h[(idx[tmp].first + 1)%n] <= 0){
                        alive[(idx[tmp].first + 1)%n] = false;
                        // cout << (idx[tmp].first + 1 )%n << " alive status " << alive[(idx[tmp].first + 1)%n] << "\n";
                        tmp = (idx[tmp].first + 1)%n;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        // cout << ans << "\n";
        for(ll i=0;i<n;i++){
            // cout << alive[i] << " ";
            if(alive[i]){
                ans += h[i];
            }
        }
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}