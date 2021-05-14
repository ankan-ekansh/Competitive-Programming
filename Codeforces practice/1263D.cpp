/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << " " << x << "\n";
template<typename... T>
void read(T&... args){
	((cin >> args), ...);
}
template<typename... T>
void write(T&&... args){
	((cout << args << " "), ...);
}
const int N = 2e5 + 69;
int n;
vector<int> adj[N];
vector<bool> vis(N);
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
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
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        
        read(n);
        for(int i=1;i<=n;i++){
            string s;
            read(s);
            for(char c : s){
                adj[i].push_back(n+c-'a'+1);
                adj[n+c-'a'+1].push_back(i);       
            }
        }
        int ans = 0;
        for(int i=n+1;i<=n+27;i++){
            if(!vis[i] && adj[i].size()){
                dfs(i);
                ans++;
            }
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
