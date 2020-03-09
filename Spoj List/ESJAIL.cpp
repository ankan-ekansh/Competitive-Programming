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
int n, k, m;
int keys[100007];
vector<int> adj[100007];
bool vis[100007];
bool has_key(int x){
    if(keys[x] == 0 || vis[keys[x]]){
        return true;
    }
    return false;
}
void bfs(int s){
    vis[s] = true;
    deque<int> dq;
    dq.push_back(s);
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        if(!has_key(u)){
            cout << u << "\n";
            return;
        }
        for(int v : adj[u]){
            if(has_key(v)){
                vis[v] = true;
                dq.push_back(v);
            }
            else{
                // cout << v << "\n";
                dq.push_front(v);
            }
        }
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
    
    cin >> n >> k >> m;
    while(n != -1 && k != -1 && m != -1){
        memset(vis, false, sizeof(vis));
        for(int i=0;i<n;i++){
            adj[i].clear();
        }
        for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            keys[b] = a;
        }
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // cout << has_key(1) << "\n";
        bfs(1);
        if(vis[n]){
            cout << "Y\n";
        }
        else{
            cout << "N\n";
        }

        cin >> n >> k >> m;
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}