/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll grid[307][307];
bool vis[307][307];
ll r, c;
ll ans;
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};
bool check(ll i, ll j) {
    if(i>=0 && i < r && j >=0 && j < c) {
        return true;
    }
    else {
        return false;
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
    int tc = 1;
    while(t--){
        
        cin >> r >> c;
        memset(vis, false, sizeof(vis));
        ans = 0;
        // priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
        map<ll, vector<pair<ll, ll>>, greater<ll>> mp;
        ll mxm = -1;
        for(ll i=0;i<r;i++) {
            for(ll j=0;j<c;j++) {
                cin >> grid[i][j];
                mxm = max(mxm, grid[i][j]);
                mp[grid[i][j]].push_back({i, j});
            }
        }
        for(auto i : mp) {
            for(ll j=0;j<mp[i.first].size();j++) {
                ll x = mp[i.first][j].first;
                ll y = mp[i.first][j].second;
            
                if(!vis[x][y]) {
                    vis[x][y] = true;
                    ll curval = grid[x][y];
                    for(ll k=0;k<4;k++) {
                        ll nx = x+dx[k];
                        ll ny = y+dy[k];
                    
                        if(check(nx, ny)) {
                            if(grid[nx][ny] < curval) {
                                ans += abs(curval - 1 - grid[nx][ny]);
                                grid[nx][ny] = curval - 1;
                                mp[curval - 1].push_back({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        // pq.push({mxm, {mxmi, mxmj}});
        // while(!pq.empty()) {
        //     pair<ll, pair<ll, ll>> p = pq.top();
        //     pq.pop();
        //     ll pi = p.second.first;
        //     ll pj = p.second.second;
        //     vis[pi][pj] = true;
        //     // cout << p.first << " " << pi << " " << pj << "\n";
        //     for(ll i=0;i<4;i++) {
        //         // cout << pi+dx[i] << " " << pj+dy[i] << "\n";
        //         if(check(pi+dx[i], pj+dy[i])){
        //             // cout << pi+dx[i] << " " << pj+dy[i] << " " << p.first-1 - grid[pi+dx[i]][pj+dy[i]] << "\n";
        //             ans += (p.first-1 - grid[pi+dx[i]][pj+dy[i]]);
        //             grid[pi+dx[i]][pj+dy[i]] = p.first - 1;
        //             vis[pi+dx[i]][pj+dy[i]] = true;
        //             pq.push({p.first-1, {pi+dx[i], pj+dy[i]}});
        //         }
        //     }
        // }
        // cout << pq.size() << "\n";
        cout << "Case #" << tc++ << ": " << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        // cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}