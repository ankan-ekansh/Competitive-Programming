#include<bits/stdc++.h>
using namespace std;
int bfs(int f, int s, int g, int u,int d){
    queue<int> q;
    int dist[f+1];
    memset(dist, -1, sizeof(dist));
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int c = q.front();
        // cout << c <<"\n";
        q.pop();
        if((c+u) <= f && (dist[c+u] == -1)){
            q.push(c+u);
            dist[c+u] = dist[c] + 1;
        }
        if((c-d) >= 1 && (dist[c-d] == -1)){
            q.push(c-d);
            dist[c-d] = dist[c] + 1;
        }
    }
    return dist[g];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    int ans = bfs(f, s, g, u, d);
    if(ans == -1){
        cout << "use the stairs\n";
    }
    else{
        cout << ans << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}