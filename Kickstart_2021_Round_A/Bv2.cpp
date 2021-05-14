/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[47][47];
ll r, c;
ll ans;
ll grid[47][47];
bool check(ll i, ll j) {
    if(i>=0 && i < r && j >=0 && j < c && !vis[i][j] && grid[i][j] == 1) {
        return true;
    }
    else {
        return false;
    }
}
// d = 0 means horizontal
// d = 1 means vertical
void fun(ll x, ll y, ll l, ll pl, ll d) {
    cout << x << " " << y << " " << l << " " << pl << " " << d << "\n";
    ans++;
}
void dfs(ll x, ll y, ll l, ll pl, ll d) {
    vis[x][y] = true;
    if(d == 0) {
        if(check(x, y+1)) {
            dfs(x, y+1, l+1, pl, d);
        }
        else{
            if(2*l == pl || 2*pl == l) {
                fun(x,y,l,pl,d);
            }
            // vis[x][y] = false;
            dfs(x, y, 1, l, 1-d);
            if(2*l == pl || 2*pl == l) {
                fun(x,y,l,pl,d);
            }
            // if(check(x+1, y)) {
            //     dfs(x+1, y, 1, l, 1-d);
            // }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
            // if(check(x-1, y)) {
            //     dfs(x-1, y, 1, l, 1-d);
            // }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
        }
        if(check(x, y-1)) {
            dfs(x, y-1, l+1, pl, d);
        }
        else{
            if(2*l == pl || 2*pl == l) {
                fun(x,y,l,pl,d);
            }
            // vis[x][y] = false;
            dfs(x, y, 1, l, 1-d);
            if(2*l == pl || 2*pl == l) {
                fun(x,y,l,pl,d);
            }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
            // if(check(x+1, y)) {
            //     dfs(x+1, y, 1, l, 1-d);
            // }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
            // if(check(x-1, y)) {
            //     dfs(x-1, y, 1, l, 1-d);
            // }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
        }
    }
    else {
        if(check(x+1, y)) {
            dfs(x+1, y, l+1, pl, d);
        }
        else{
            if(2*l == pl || 2*pl == l) {
                fun(x,y,l,pl,d);
            }
            // vis[x][y] = false;
            dfs(x, y, 1, l, 1-d);
            if(2*l == pl || 2*pl == l) {
                fun(x,y,l,pl,d);
            }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
            // if(check(x, y+1)) {
            //     dfs(x, y+1, 1, l, 1-d);
            // }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
            // if(check(x, y-1)) {
            //     dfs(x, y-1, 1, l, 1-d);
            // }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
        }
        if(check(x-1, y)) {
            dfs(x-1, y, l+1, pl, d);
        }
        else{
            if(2*l == pl || 2*pl == l) {
                fun(x,y,l,pl,d);
            }
            // vis[x][y] = false;
            dfs(x, y, 1, l, 1-d);
            if(2*l == pl || 2*pl == l) {
                fun(x,y,l,pl,d);
            }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
            // if(check(x, y+1)) {
            //     dfs(x, y+1, 1, l, 1-d);
            // }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
            // if(check(x, y-1)) {
            //     dfs(x, y-1, 1, l, 1-d);
            // }
            // if(2*l == pl || 2*pl == l) {
            //     fun(x,y,l,pl,d);
            // }
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
    cin>>t;
    int tc = 1;
    while(t--){
        
        cin >> r >> c;
        memset(vis, 0, sizeof(vis));
        ans = 0;
        for(ll i=0;i<r;i++) {
            for(ll j=0;j<c;j++) {
                cin >> grid[i][j];
            }
        }
        for(ll i=0;i<r;i++) {
            for(ll j=0;j<c;j++) {
                if(grid[i][j] == 1) {
                    // memset(vis, 0, sizeof(vis));
                    dfs(i, j, 1, 0, 0);
                    // memset(vis, 0, sizeof(vis));
                    dfs(i, j, 1, 0, 1);
                }
            }
        }
        cout << "Case #" << tc++ << ": " << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}