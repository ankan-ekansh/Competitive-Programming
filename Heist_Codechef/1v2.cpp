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
ll parent[100];
ll money[100];
ll b[9];
void make_set(ll v) {
    parent[v] = v;
}

ll find_set(ll v) {
    
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
void fun(ll a){
    money[a] = max(money[parent[a]], b[a]);
    money[parent[a]] = money[a];
}
vector<ll> adj[1000];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // ll t;
    // cin>>t;
    // while(t--){
 
        for(ll i=1;i<=8;i++){
            cin >> b[i];
            make_set(i);
        }

        ll p;
        cin >> p;
        for(ll i=0;i<p;i++){
            ll a, b;
            cin >> a >> b;
            union_sets(a, b);
        }
        set<ll> s;
        for(ll i=1;i<=8;i++){
            s.insert(parent[i]);
            if(i != parent[i]){
                adj[parent[i]].push_back(i);
            }
        }
        ll ans = 0;
        for(auto i=s.begin();i!=s.end();i++){
            money[*i] = b[*i];
            // cout << *i << " : ";
            for(ll x : adj[*i]){
                // cout << x << " ";
                money[*i] = max(money[*i], b[x]);
            }
            // cout << "\n";
            // cout << "Money for " << *i << " is " << money[*i] << "\n";
            ans+=money[*i];
        }
        cout << ans;
 
    // }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}