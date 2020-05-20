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
bool comp(pair<string, ll> left, pair<string, ll> right){
    return left.first.length() < right.first.length();
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
 
        ll u;
        cin >> u;
        vector<pair<string, ll>> m;
        for(ll i=0;i<10000;i++){
            ll q;
            string r;
            cin >> q >> r;
            m.push_back({r, q});
        }
        sort(m.begin(), m.end(), comp);
        map<char, ll> mp;
        for(ll i=0;i<m.size();i++){
            // cout << m[i].first << " " << m[i].second << "\n";
            if(m[i].first.length() == 1){
                if(mp.find(m[i].first[0]) != mp.end())
                    mp[m[i].first[0]] = min(mp[m[i].first[0]], m[i].second);
                else
                    mp[m[i].first[0]] = m[i].second;
            }
            if(mp.size() == 10){
                break;
            }
            for(char c : m[i].first){
                if(mp.find(c) == mp.end()){
                    mp[c] = 
                }
            }
        }
        for(auto c : mp){
            cout << c.first << " " << c.second << "\n";
        }

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}