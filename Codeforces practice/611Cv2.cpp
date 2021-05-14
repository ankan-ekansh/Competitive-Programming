/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int h, w;
    cin >> h >> w;
    char grid[h+1][w+1];
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> grid[i][j];
        }
    }
    int dph[h+1][w+1], dpv[h+1][w+1];
    memset(dph, 0, sizeof(dph));
    memset(dpv, 0, sizeof(dpv));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            dph[i][j] = dph[i][j-1] + (grid[i][j] == '.' && grid[i][j-1] == '.');
            dpv[i][j] = dpv[i-1][j] + (grid[i][j] == '.' && grid[i-1][j] == '.');
        }
    }
    int q;
    cin >> q;
    while(q--){
        int r1, c1, r2, c2;
        int ans = 0;
        cin >> r1 >> c1 >> r2 >> c2;
        for(int i=r1;i<=r2;i++){
            ans += dph[i][c2] - dph[i][c1];
        }
        for(int j=c1;j<=c2;j++){
            ans += dpv[r2][j] - dpv[r1][j];
        }
        cout << ans << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}