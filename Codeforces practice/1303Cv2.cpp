/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(set<ll> adj[], bool vis[], ll u, string &ans){
    vis[u] = true;
    ans.push_back((char)(u + 'a'));
    for(ll v : adj[u]){
        if(!vis[v]){
            dfs(adj, vis, v, ans);
        }
    }
}

void solve(string s){
    set<ll> adj[26];
    ll n = s.length();
    if(n == 1){
        cout << "YES\n";
        cout << s[0];
        for(char c = 'a';c<='z';c++){
            if(c == s[0]){
                continue;
            }
            cout << c;
        }
        cout << "\n";
    }
    else{
        for(ll i=1;i<n;i++){
            ll u = s[i-1]-'a';
            ll v = s[i]-'a';
            adj[u].insert(v);
            adj[v].insert(u);
            if(adj[u].size() > 2 || adj[v].size() > 2){
                cout << "NO\n";
                return;
            }
        }
        bool vis[26];
        memset(vis, false, sizeof(vis));
        string ans = "";
        bool found = false;
        for(ll i=0;i<26;i++){
            if(adj[i].size() == 1){
                found = true;
                dfs(adj, vis, i, ans);
                break;
            }
        }
        if(!found){
            cout << "NO\n";
            return;
        }
        for(ll i=0;i<26;i++){
            if(!vis[i]){
                ans.push_back((char)(i+'a'));
            }
        }
        cout << "YES\n";
        cout << ans << "\n";
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
    cin>>t;
    while(t--){
        
        string s;
        cin >> s;
        solve(s);
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}