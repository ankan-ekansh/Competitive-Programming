#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sx, sy;
    cin >> n >> sx >> sy;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};   // 0 - left, 1 - right, 2 - down, 3 - up
    int ax[n], ay[n];
    for(int i=0;i<n;i++){
        cin >> ax[i] >> ay[i];
    }
    pair<int, pair<int, int>> p = make_pair(-1, make_pair(0, 0));
    for(int i=0;i<4;i++){
        int c = 0;
        int x = sx + dx[i];
        int y = sy + dy[i];
        for(int j=0;j<n;j++){
            if((x <= sx && ax[j] <= x) || (x >= sx && ax[j] >= x)){
                if((y <= sy && ay[j] <= y) || (y >= sy && ay[j] >= y)){
                    c++;
                }
            }
        }
        p = max(p, make_pair(c, make_pair(x, y)));
    }
    cout << p.first << "\n";
    cout << p.second.first << " " << p.second.second << "\n";
    
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}