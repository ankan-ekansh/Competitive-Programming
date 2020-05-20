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
ll n, m;
vector<ll> adj[500007];
// vector<bool> vis(500007);
vector<ll> indegree(500007);
// vector<ll> ans;
priority_queue<ll, vector<ll>, greater<ll>> pq;
bool isDAC = true;
// void dfs(ll u){
//     vis[u] = true;
//     for(ll v : adj[u]){
//         if(!vis[v]){
//             dfs(v);
//         }
//     }
//     ans.push_back(u);
// }
// void topo_sort(){
//     vis.assign(n, false);
//     ans.clear();
//     for(ll i=1;i<=n;i++){
//         if(!vis[i]){
//             dfs(i);
//         }
//     }
//     reverse(ans.begin(), ans.end());
// }
// void dfs2(ll u, ll cs){
//     vis[u] = true;
//     for(ll v : adj[u]){
//         indegree[v]++;
//         if(!vis[v]){
//             dfs2(v, cs);
//         }
//         else{
//             if(v == cs){
//                 isDAC = false;
//                 // cout << v << "\n";
//             }
//         }
//     }
// }
void topo_sort(){
    ll ctr = 0;
    vector<ll> ans;
    while(!pq.empty()){
        ll f = pq.top();
        pq.pop();
        // cout << f << " ";
        ans.push_back(f);
        for(ll nei : adj[f]){
            // cout << nei << " ";
            indegree[nei]--;
            if(indegree[nei] == 0){
                pq.push(nei);
            }
        }
        ctr++;
        // cout << "\n";
    }
    if(ctr != n){
        cout << "Sandro fails.\n";
        return;
    }
    for(ll i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
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
    for(ll i=0;i<m;i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // radj[y].push_back(x);
    }
    // for(ll i=1;i<=n;i++){
    //     sort(adj[i].begin(), adj[i].end());
    // }
    for(ll i=1;i<=n;i++){
        // if(isDAC == false){
        //     cout << "Sandro fails.\n";
        //     return 0;
        // }
        // else{
        //     if(!vis[i]){
        //         dfs2(i, i);
        //     }
        // }
        for(ll nei : adj[i]){
            indegree[nei]++;
        }
    }
    for(ll i=1;i<=n;i++){
        // cout << i << " " << indegree[i] << "\n";
        if(indegree[i] == 0){
            pq.push(i);
        }
    }
    // vis.assign(100007, false);
    // for(ll i=1;i<=n;i++){
    //     if(!vis[i]){
    //         topo_sort();
    //     }
    // }
    // topo_sort();
    // for(ll i=0;i<ans.size();i++){
    //     cout << ans[i] << " ";
    // }
    topo_sort();

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}