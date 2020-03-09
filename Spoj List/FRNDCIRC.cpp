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
unordered_map<string, string> parent;
unordered_map<string, int> m;
string find_parent(string a){
    if(a == parent[a]){
        return a;
    }
    else{
        return parent[a] = find_parent(parent[a]);
    }
}
void union_set(string a, string b){
    a = find_parent(a);
    b = find_parent(b);
    if(a != b){
        parent[b] = a;
        m[a] = m[a] + m[b];
        // m[a] = m[b];
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
    int t;
    cin>>t;
    while(t--){

        parent.clear();
        m.clear(); 
        int n;
        cin >> n;
        while(n--){
            string a, b;
            cin >> a >> b;
            if(m[a] == 0){
                parent[a] = a;
                m[a] = 1;
            }
            if(m[b] == 0){
                parent[b] = b;
                m[b] = 1;
            }
            union_set(a, b);
            // cout << a << " " << b << "\n";
            // cout << find_parent(a) << " " << find_parent(b) << "\n";
            cout << m[find_parent(a)] << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}