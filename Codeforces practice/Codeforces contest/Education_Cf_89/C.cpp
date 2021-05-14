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
        
        int n, m;
        cin >> n >> m;
        int a[n+1][m+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        int ans1 = 0, ans2 = 0;
        int ans = 0;
        vector<pair<int, int>> diags;
        for(int j=0;j<m;j++){
            int tj = j;
            int zeroes = 0, ones = 0;
            for(int i=0;i<n && tj >= 0; i++, tj--){
                if(a[i][tj] == 0){
                    zeroes++;
                }
                else{
                    ones++;
                }
            }
            diags.push_back({zeroes, ones});
        }
        for(int i=1;i<n;i++){
            int ti = i;
            int zeroes = 0, ones = 0;
            for(int j=m-1;j>=0 && ti < n; j--, ti++){
                if(a[ti][j] == 0){
                    zeroes++;
                }
                else{
                    ones++;
                }
            }
            diags.push_back({zeroes, ones});
        }
        for(int i=0;i<diags.size()/2;i++){
            // cout << diags[i].first << " " << diags[i].second << " ; " << diags[diags.size()-1-i].first << " " << diags[diags.size()-1-i].second << "\n";
            // int x = diags[i].first + diags[i].second;
            ans += min(diags[i].first + diags[diags.size()-1-i].first, diags[i].second + diags[diags.size()-1-i].second);
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}