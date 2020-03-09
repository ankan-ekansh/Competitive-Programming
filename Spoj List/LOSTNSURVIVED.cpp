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
int parent[100007];
int s[100007];
// int smax = 1, smin = 1;
multiset<int, greater<int>> sz;
void make_set(int a){
    parent[a] = a;
    s[a] = 1;
    sz.insert(1);
}
int find_set(int a){
    if(a == parent[a]){
        return a;
    }
    else{
        return parent[a] = find_set(parent[a]);
    }
}
void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(s[b] > s[a]){
            swap(a, b);
        }
        parent[b] = a;
        sz.erase(sz.find(s[a]));
        sz.erase(sz.find(s[b]));
        s[a]+=s[b];
        // smax = max(smax, s[a]);
        // smin = min(smin, s[a]);
        sz.insert(s[a]);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        make_set(i);
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        union_set(a, b);
        // cout << smax << " " << smin << "\n";
        // cout << smax - smin << "\n";
        cout << *sz.begin() - *sz.rbegin() << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}