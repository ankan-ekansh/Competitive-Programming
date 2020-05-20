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
    return p.first < q.first;
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
    ll ctr = 1;
    while(t--){
 
 
        ll n;
        cin >> n;
        vector<pair<pair<ll, ll>, ll>> v;
        vector<pair<ll, ll>> a;
        for(ll i=0;i<n;i++){
            ll x, y;
            cin >> x >> y;
            v.push_back({{x, y}, i});
        }
        bool ca = true, cj = true;
        bool ok = true;
        sort(v.begin(), v.end());
        vector<pair<ll, char>> ans;
        ll ct = 0, jt = 0;
        for(ll i=0;i<n;i++){
            // cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << "\n";
            if(v[i].first.first >= ct){
                // ans+="C";
                ans.push_back({v[i].second, 'C'});
                // cout << "\nC\n";
                ct = v[i].first.second;
            }
            else if(v[i].first.first >= jt){
                // ans+="J";
                // cout << "\nJ\n";
                ans.push_back({v[i].second, 'J'});
                jt = v[i].first.second;
            }
            else{
                // cout << "Case #" << ctr++ << ": " << "IMPOSSIBLE\n";
                ok = false;
                break;
            }
        }
        if(!ok){
            cout << "Case #" << ctr++ << ": " << "IMPOSSIBLE\n";
            continue;
        }
            sort(ans.begin(), ans.end());

            cout << "Case #" << ctr++ << ": ";
            for(auto p : ans){
                // cout << p.first << " " << p.second << "\n";
                cout << p.second;
            }
            cout << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}