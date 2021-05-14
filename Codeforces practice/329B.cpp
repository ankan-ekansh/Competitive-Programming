/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 0x3f3f3f3f;
ll r, c;
char a[1007][1007];
ll t[1007][1007];
bool vis[1007][1007];
ll start_r, start_c, exit_r, exit_c;
ll dr[] = {0, -1, 0, 1};
ll dc[] = {1, 0, -1, 0};
void bfs(ll sr, ll sc){
    vis[sr][sc] = true;
    t[sr][sc] = 0;
    queue<pair<ll, ll>> q;
    q.push({sr, sc});
    while(!q.empty()){
        pair<ll, ll> u = q.front();
        ll ux = u.first, uy = u.second;
        // cout << ux << " " << uy << "\n";
        q.pop();
        for(ll i = 0; i < 4; i++){
            if(ux + dr[i] < 0 || ux + dr[i] >= r || uy + dc[i] < 0 || uy + dc[i] >= c){
                continue;
            }
            if(a[ux+dr[i]][uy+dc[i]] == 'T'){
                continue;
            }
            if(!vis[ux+dr[i]][uy+dc[i]]){
                vis[ux+dr[i]][uy+dc[i]] = true;
                t[ux+dr[i]][uy+dc[i]] = t[ux][uy] + 1;
                q.push({ux+dr[i], uy+dc[i]});
            }
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
    
    cin >> r >> c;
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cin >> a[i][j];
            if(a[i][j] == 'E'){
                exit_r = i;
                exit_c = j;
            }
            if(a[i][j] == 'S'){
                start_r = i;
                start_c = j;
            }
        }
    }
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            t[i][j] = INF;
        }
    }
    bfs(exit_r, exit_c);
    ll mytime = t[start_r][start_c];
    ll b = 0;
    // cout << mytime << "\n";
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            if(a[i][j] == 'E' || a[i][j] == 'S' || a[i][j] == 'T'){
                continue;
            }
            if(t[i][j] <= mytime){
                // cout << i << " " << j << " " << t[i][j] << " " << a[i][j] << "\n";
                b += (a[i][j] - '0');
            }
        }
    }
    cout << b << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}