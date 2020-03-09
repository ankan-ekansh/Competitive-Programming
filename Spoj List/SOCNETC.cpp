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
int n, m;
map<int, int> s;
int parent[100007];
void make_set(int v) {
    parent[v] = v;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b && s[a] + s[b] <= m){
        parent[b] = a;
        s[b] = s[a] + s[b];
        s[a] = s[b];
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

    cin >> n >> m;
    int q;
    cin >> q;
    for(int i=1;i<=n;i++){
        make_set(i);
        s[i] = 1;
    }
    while(q--){
        char c;
        int a, b;
        cin >> c;
        if(c == 'S'){
            cin >> a;
            cout << s[find_set(a)] << "\n";
        }
        else{
            cin >> a >> b;
            if(c == 'A'){
                union_sets(a, b);
            }
            else if(c == 'E'){
                // cout << a << " " << b << "\n";
                // cout << find_set(a).first << " " << find_set(b).first << "\n"; 
                // if(find_set(a).first != find_set(b).first){
                //     cout << "No\n";
                // }
                // else{
                //     cout << "Yes\n";
                // }
                if(find_set(a) == find_set(b)){
                    cout << "Yes\n";
                }
                else{
                    cout << "No\n";
                }
            }
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}