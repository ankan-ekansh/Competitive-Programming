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
// set<int> vis1, vis2;
vector<bool> vis1(100007), vis2(100007);
vector<int> adj[100007];
// vector<int> radj[100007];
stack<int> dfsorder;
void dfs1(int s){
    // vis1.insert(s);
    vis1[s] = true;
    for(int v : adj[s]){
        // if(!vis1.count(v)){
        if(!vis1[v]){
            dfs1(v);
        }
    }
    dfsorder.push(s);
}
void dfs2(int s){
    // cout << s << " ";
    // vis2.insert(s);
    vis2[s] = true;
    for(int v : adj[s]){
        // if(!vis2.count(v)){
        if(!vis2[v]){
            dfs2(v);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
    //     freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        int n, m;
        cin >> n >> m;
        for(int i=0;i<=n;i++){
            adj[i].clear();
            vis1[i] = false;
            vis2[i] = false;
            // radj[i].clear();
        }
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            // radj[b].push_back(a);
            // adj[b].push_back(a);
        } 
        // for(int i=1;i<=n;i++){
        //     cout << i << " : ";
        //     for(int v : adj[i]){
        //         cout << v << " ";
        //     }
        //     cout << "\n";
        // }
        // for(int i=1;i<=n;i++){
        //     cout << i << " : ";
        //     for(int v : radj[i]){
        //         cout << v << " ";
        //     }
        //     cout << "\n";
        // }
        // int c = 0;
        for(int i=1;i<=n;i++){
            // if(!vis1.count(i)){
                // c++;
            if(!vis1[i]){
                dfs1(i);
            }
        }
        // cout << c << "\n";
        // cout << "vis1 size is " << vis1.size() << "\n";
        int c = 0;
        while(!dfsorder.empty()){
            int tp = dfsorder.top();
            // if(!vis2.count(tp)){
                // cout << tp << " ";
            if(!vis2[tp]){
                c++;
                dfs2(tp);
                // cout << "\n";
            }
            // cout << tp << " ";
            // cout << "\n";
            dfsorder.pop();
        }
        // cout << "\n";
        // cout << "vis2 size is " << vis2.size() << "\n";
        cout << c << "\n";
        // vis1.clear();
        // vis2.clear();
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}