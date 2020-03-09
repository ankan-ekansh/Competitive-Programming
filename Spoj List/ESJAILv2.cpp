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
bool need_key[100007];
vector<int> adj[100007];
bool vis[100007];
bool bfs(int s){
    vis[s] = true;
    queue<int> q,p;
    q.push(s);
    while(!q.empty()){
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u == n){
                return true;
            }
            for(int v : adj[u]){
                if(!vis[v] && need_key[v] == false){
                    vis[v] = true;
                    q.push(v);
                    if(keys[v]){
                        p.push(keys[v]);
                    }
                }
            }
        }
        while(!p.empty()){
            int u = p.front();
            p.pop();
            if(!vis[u]){
                q.push(u);
                need_key[u] = false;
            }
        }
    }
    return false;
}
// void bfs2(int s){
//     vis[s] = true;
//     queue<int> q;
//     q.push(s);
//     while(!q.empty()){
//         int u = q.front();
//         q.pop();
//         // cout << u << " : ";
//         for(int v : adj[u]){
//             if(!vis[v] && !need_key[v]){
//                 q.push(v);
//                 vis[v] = true;
//                 // cout << v << " ";
//                 if(keys[v] != 0){
//                     // cout << v << " " << keys[v] << "\n";
//                     vis[keys[v]] = true;
//                     q.push(keys[v]);
//                 }
//             }
//         }
//         // cout << "\n";
//     }
// }
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
        memset(keys, 0, sizeof(keys));
        memset(need_key, false, sizeof(need_key));
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
        for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            keys[a] = b;
            need_key[b] = true;
        }
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // bfs1(1);
        // bool flag = true;
        // for(int i=1;i<=n;i++){
        //     if(!vis[i]){
        //         flag = false;
        //         break;
        //     }
        // }
        // if(!flag){
        //     cout << "N\n";
        // }
        // else{
        //     memset(vis, false, sizeof(vis));
        //     bfs2(1);
        //     for(int i=1;i<=n;i++){
        //         if(!vis[i]){
        //             // cout << "Not visited : " << i << "\n";
        //             flag = false;
        //             break;
        //         }
        //     }
        //     if(flag){
        //         cout << "Y\n";
        //     }
        //     else{
        //         cout << "N\n";
        //     }
        // }
        if(bfs(1)){
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