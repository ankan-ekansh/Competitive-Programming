#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1000000];
bool vis[1000000];
bool vis_g[1000000];
queue<int> q;
int dist[1000000];
void create(int x){
    if(x!=m && x>0 && !vis_g[x]){
        vis_g[x] = true;
        adj[x].push_back(2*x);
        adj[x].push_back(x-1);
        if(x < m){
            create(2*x);
        }
        create(x-1);
    }
}
void bfs(int x){
    vis[x] = true;
    q.push(x);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i : adj[front]){
            if(!vis[i]){
                vis[i] = true;
                dist[i]=dist[front] + 1;
                q.push(i);
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

    cin >> n >> m;

    if(n == m){
        cout << "0\n";
    }
    else{
        create(n);
        bfs(n);
        cout << dist[m] << "\n";
    }

    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}