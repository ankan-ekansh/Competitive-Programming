/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(vector<int> adj[], bool vis[], int s, string &ans){
    vis[s] = true;
    // cout << (char)(s+'a') << "\n";
    ans.push_back((char)(s+'a'));
    for(int e : adj[s]){
        if(!vis[e]){
            // vis[e] = true;
            dfs(adj, vis, e, ans);
        }
    }
}
bool dfs2(vector<int> adj[], bool vis[], int s, int p){
    vis[s] = true;
    for(int e : adj[s]){
        if(!vis[e]){
            if(dfs2(adj, vis, e, s)){
                return true;
            }
        }
        else{
            if(e != p){
                return true;
            }
        }
    }
    return false;
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
    cin>>t;
    while(t--){
        
        string s;
        cin >> s;
        vector<int> adj[26];
        bool flag = true;
        int src = s[0] - 'a';
        for(int i=1;i<s.length();i++){
            int u = s[i-1] - 'a';
            int v = s[i] - 'a';
            bool found = false;
            for(int x : adj[u]){
                if(x == v){
                    found = true;
                    break;
                }
            }
            if(!found){
                adj[u].push_back(v);
            }
            found = false;
            for(int x : adj[v]){
                if(x == u){
                    found = true;
                    break;
                }
            }
            if(!found){
                adj[v].push_back(u);
            }
            // if(adj[u].size() > 2 || adj[v].size() > 2){
            //     cout << u << ", " << v << "\n";
            //     flag = false;
            // }
        }
        for(int i=0;i<26;i++){
            if(adj[i].size() == 1){
                src = i;
                break;
            }
        }
        bool vis[26];
        memset(vis, false, sizeof(vis));
        string ans = "";
        dfs(adj, vis, src, ans);
        for(int i=0;i<26;i++){
            // cout << (char)(i + 'a') << " " << adj[i].size() << "\n";
            // if(adj[i].size() > 2){
            //     flag = false;
            //     break;
            // }
            if(!vis[i]){
                dfs(adj, vis, i, ans);
            }
        }
        // cout << ans << "\n";
        memset(vis, false, sizeof(vis));
        if(dfs2(adj, vis, src, -1)){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << ans << "\n";
        }
        
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}