/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[800001], h[800001];
ll n;
ll dp[800001][2];
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
        
        cin >> n;
        for(ll i=0;i<n;i++){
            cin >> p[i] >> h[i];
        }

        cout << "Case #" << tc++ << ": \n";
        vector<pair<ll, ll>> left, right;
        map<pair<ll, ll>, vector<ll>> ml, mr;
        for(ll i=0;i<n;i++){
            left.push_back({p[i] - h[i], p[i]});
            ml[{p[i] - h[i]}].emplace_back(i);
            right.push_back({p[i], p[i] + h[i]});
            mr[{p[i] + h[i]}].emplace_back(i);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        ll ans = 0;
        for(ll i=0;i<left.size();i++){
            cout << "( " << left[i].first << ", " << left[i].second << " ) ";
        }
        cout << "\n";
        for(ll i=0;i<right.size();i++){
            cout << "( " << right[i].first << ", " << right[i].second << " ) ";
        }
        cout << "\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}