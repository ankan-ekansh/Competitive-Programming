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
vector<int> adj[100007];
vector<int> euler;
vector<int> depth(100007);
vector<int> first(100007);
vector<bool> vis(100007);
vector<int> segtree(800007);
void dfs(int currentNode = 1, int deep = 0){
    vis[currentNode] = 1;
    depth[currentNode] = deep;
    first[currentNode] = euler.size() + 1;
    euler.push_back(currentNode);
    for(int nextNode : adj[currentNode]){
        if(!vis[nextNode]){
            dfs(nextNode, deep+1);
            euler.push_back(currentNode);
        }
    }
}
void build(int node, int start, int end){
    if(start == end){
        segtree[node] = euler[start];
    }
    else{
        int middle = (start + end) / 2;
        build(2 * node, start, middle);
        build(2 * node + 1, middle + 1, end);
        int left = segtree[2 * node];
        int right = segtree[2 * node + 1];
        segtree[node] = depth[left] < depth[right] ? left : right;
    }
}
int query(int node, int start, int end, int L, int R){
    if(start > R || end < L){    // no overlap
        return -1;
    }
    if(start >= L && R >= end){
        return segtree[node];
    }
    int middle = (start + end) / 2;
    int left = query(node * 2, start, middle, L, R);
    int right = query(node * 2 + 1, middle + 1, end, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    return depth[left] < depth[right] ? left : right;
}
int lca(int u, int v){
    int left = first[u]-1, right = first[v]-1;
    if(left > right){
        swap(left, right);
    }
    return query(1, 0, euler.size() - 1, left, right);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int ctr = 1;
    while(t--){
        cin >> n;
        euler.clear();
        depth.assign(100007,0);
        vis.assign(100007, false);
        first.assign(100007, 0);
        segtree.assign(800007, 0);
        for(ll i=0;i<100007;i++){
            adj[i].clear();
        }
        for(int i=1;i<=n;i++){
            int s, x;
            cin >> s;
            for(int j=0;j<s;j++){
                cin >> x;
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        dfs();
        // segtree.resize(4 * euler.size());
        // segtree.resize(800007);
        build(1, 0, euler.size() - 1);
        int q;
        cin >> q;
        // for(int i=1;i<=n;i++){
        //     cout << first[i] << " ";
        // }
        // cout << "\n";
        // for(int i=0;i<euler.size();i++){
        //     cout << euler[i] << " ";
        // }
        // cout << "\n";
        cout << "Case " << ctr++ << ":\n"; 
        while(q--){
            int u, v;
            cin >> u >> v;
            // cout << u << " " << v << " ";
            cout << lca(u, v) << "\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}