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
int parent[1007];
vector<int> adj[1007];
vector<int> ad[1007];
int vis[1007];
int n, m;
void initialize(){
    for(int i=0;i<=1005;i++){
        parent[i] = i;
    }
}
int root(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void union_set(int x, int y){
    int a = root(x);
    int b = root(y);
    parent[a] = parent[b];
}
void dfs(int x){
    vis[x] = true;
    for(int v : ad[x]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    initialize();
    for(int i=1;i<=n;i++){
        int s;
        cin >> s;
        for(int j=1;j<=s;j++){
            int l;
            cin >> l;
            adj[l].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        // if(adj[i].size() > 0){
        //     for(int j=1;j<adj[i].size();j++){
        //         if(root(adj[i][0] != root(adj[i][j]))){
        //             union_set(adj[i][0], adj[i][j]);
        //             ad[adj[i][0]].push_back(adj[i][j]);
        //             ad[adj[i][j]].push_back(adj[i][0]);
        //         }
        //     }
        // }
        for(int j=0;j<adj[i].size();j++){
            for(int k=j+1;k<adj[i].size();k++){
                if(root(adj[i][j] != root(adj[i][k]))){
                    union_set(adj[i][j], adj[i][k]);
                    ad[adj[i][j]].push_back(adj[i][k]);
                    ad[adj[i][k]].push_back(adj[i][j]);
                }
            }
        }
    }
    // for(int i=1;i<=m;i++){
    //     cout << "Language " << i << " - ";
    //     for(int v : adj[i]){
    //         cout << v << " ";
    //     }
    //     cout << "\n";
    // }
    ll ct = 0;
    ll no = 0;
    for(int i=1;i<=n;i++){
        // cout << i << " has parent " << parent[i] << "\n";
        // cout << i << " - ";
        // for(int v : ad[i]){
        //     cout << v << " ";
        // }
        // cout << "\n";
        if(!adj[i].size()){
            no++;
        }
        if(!vis[i]){
            ct++;
            dfs(i);
        }
    }
    // cout << "ct " << ct << ", no " << no << "\n"; 
    if(no != n)
        cout << ct-1 << "\n";
    else
        cout << n << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}