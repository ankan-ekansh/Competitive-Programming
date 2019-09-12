#include<bits/stdc++.h>
using namespace std;
bool check(int x, int y){
    if(x < 0 || x > 7 || y < 0 || y > 7){
        return false;
    }
    return true;
}
int bfs(int sx, int sy, int ex, int ey){


    int dist[8][8] = {0}, vis[8][8] = {0};
    pair<int, int> p;
    queue<pair<int, int>> q;
    p.first = sx;
    p.second = sy;
    q.push(p);
    // memset(dist, 0, sizeof(dist));
    // memset(vis, 0, sizeof(vis));
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p.first == ex && p.second == ey){
            return dist[ex][ey];
        }
        int x = p.first;
        int y = p.second;
        if(check(x+2, y+1)){
            vis[x+2][y+1] = 1;
            dist[x+2][y+1] = dist[x][y] + 1;
            q.push(make_pair(x+2, y+1));
        }
        if(check(x+1, y+2)){
            vis[x+1][y+2] = 1;
            dist[x+1][y+2] = dist[x][y] + 1;
            q.push(make_pair(x+1, y+2));
        }
        if(check(x+2, y-1)){
            vis[x+2][y-1] = 1;
            dist[x+2][y-1] = dist[x][y] + 1;
            q.push(make_pair(x+2, y-1));
        }
        if(check(x+1, y-2)){
            vis[x+1][y-2] = 1;
            dist[x+1][y-2] = dist[x][y] + 1;
            q.push(make_pair(x+1, y-2));
        }
        if(check(x-2, y+1)){
            vis[x-2][y+1] = 1;
            dist[x-2][y+1] = dist[x][y] + 1;
            q.push(make_pair(x-2, y+1));
        }
        if(check(x-1, y-2)){
            vis[x-1][y-2] = 1;
            dist[x-1][y-2] = dist[x][y] + 1;
            q.push(make_pair(x-1, y-2));
        }
        if(check(x-2, y-1)){
            vis[x-2][y-1] = 1;
            dist[x-2][y-1] = dist[x][y] + 1;
            q.push(make_pair(x-2, y-1));
        }
        if(check(x-1, y+2)){
            vis[x-1][y+2] = 1;
            dist[x-1][y+2] = dist[x][y] + 1;
            q.push(make_pair(x-1, y+2));
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
    int t;
    cin>>t;
    while(t--){
 
        string s, e;
        cin>>s>>e;
        cout<<bfs(s[0] - 'a', s[1] - '0' - 1, e[0] - 'a', e[1] - '0' - 1)<<"\n";
        // cout<<bfs(2, 2, 7, 7);
        // cout<<turns<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}