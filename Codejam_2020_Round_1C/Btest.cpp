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
struct comp{
    bool operator()(const std::string &left, const std::string &right) const{
        return (left.length() < right.length());
    }
};
// bool comp(pair<string, ll> p, pair<string, ll> q){
//     return p.first.length() < q.first.length();
// }
// struct comp{
//     bool operator()(const pair<string, ll> left, const pair<string, ll> right) const{
//         return left.first.length() < right.first.length();
//     }
// };
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
        // map<string, vector<ll>> m;
        multimap<string, ll> m;
        for(ll i=0;i<10000;i++){
            ll q;
            string r;
            cin >> q >> r;
            // for(ll j=1;j<=q;j++){
                // m[q] = r
                // m[r].push_back(q);;
                // m[r] = min(m[r], q);
                // m[r] = j;
                // if(m[r]){
                //     m[r] = min(m[r], q);
                // }
                // else{
                //     m[r] = q;
                // }
                if(m.find(r) != m.end()){
                    // m[r] = min(m[r], q);
                    auto it = m.find(r);
                    if((*it).second > q){
                        m.erase(r);
                        m.insert({r, q});
                    }
                }
                else{
                    m.insert({r, q});
                }
            // }
        }
        // for(ll i=1;i<=100;i++){
        //     cout << i << " " << m[i] << "\n";
        // }
        // sort(m.begin(), m.end());
        string d = "ABCDEFGHIJ";
        for(auto s : m){
            cout << s.first << " : " << s.second << "\n";
            if(s.first.length() == 1){
                d[s.second] = s.first[0];
            }
        }
        cout << d << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}