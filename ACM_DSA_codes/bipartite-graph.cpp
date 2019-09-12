#include<bits/stdc++.h>
using namespace std;
bool bfs(int u, vector<int> adj[], vector<int> &ca){
    ca[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        // cout<<c<<"\n";
        for(int v : adj[c]){
            // cout<<"Adj: "<<c<<" "<<v<<"\n";
            // q.push(v);
            if(ca[v] == -1){
                q.push(v);
                ca[v] = 1 - ca[c];
                // cout<<v<<" : "<<ca[v]<<"\n";
            }
            else{
                // cout<<"Already visited : "<<c<<" "<<v<<"\n";
                // cout<<ca[c]<<" "<<ca[v]<<"\n";
                if(ca[c] == ca[v]){
                    return false;
                }
            }
        }
    }
    return true;
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
    int s = 0;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> adj[n+1];
        vector<int> ca(n+1,-1);
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool state = true;
        for(int i=1;i<=n;i++){
            if(ca[i] == -1){
                state&= bfs(i, adj, ca);
                // if(!state){
                //     break;
                // }
            }
        }
        cout << "Scenario #"<<++s<<":\n";
        if(state){
            cout<<"No suspicious bugs found!\n";
        }
        else{
            cout<<"Suspicious bugs found!\n";
        }
    }




    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}