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
    int t;
    cin>>t;
    while(t--){
        
        ll n, m;
        cin >> n >> m;
        string s[n];
        for(ll i=0;i<n;i++){
            cin >> s[i];
        }
        vector<vector<ll>> vis(n, vector<ll>(m, false));
        priority_queue<pair<char, pair<ll, ll>>> pq;
        pq.push({s[0][0], {0, 0}});
        string ans = "";
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            ans.push_back(u.first);
            vis[u.second.first][u.second.second] = true;
            ll i = u.second.first;
            ll j = u.second.second;
            if(i + 1 < n && s[i+1][j] != '#' && !vis[i+1][j]){
                pq.push({s[i+1][j], {i+1, j}});
                vis[i+1][j] = true;
            }
            if(j + 1 < m && s[i][j+1] != '#' && !vis[i][j+1]){
                pq.push({s[i][j+1], {i, j+1}});
                vis[i][j+1] = true;
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cout << vis[i][j] << " ";
            }
            cout << "\n";
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}