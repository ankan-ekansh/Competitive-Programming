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
    
    ll n, W, H;
    cin >> n >> W >> H;
    vector<pair<pair<ll, ll>, ll>> v;
    ll dp[n+7], par[n+7];
    for(ll i=1;i<=n;i++){
        ll wi, hi;
        cin >> wi >> hi;
        v.push_back({{wi, hi}, i});
    }
    sort(v.begin(), v.end());
    for(ll i=0;i<n;i++){
        if(v[i].first.first <= W || v[i].first.second <= H){
            dp[i] = 0;
            par[i] = -1;
            continue;
        }
        ll mxm = 0, pr = -1;
        for(ll j=0;j<i;j++){
            if(v[j].first.first < v[i].first.first && v[j].first.second < v[i].first.second){
                if(dp[j] > mxm){
                    mxm = dp[j];
                    pr = j;
                }
            }
        }
        dp[i] = mxm + 1;
        par[i] = pr;
    }
    vector<ll> ans;
    ll mxm = 0, pr = -1;
    for(ll i=0;i<n;i++){
        if(mxm < dp[i]){
            mxm = dp[i];
            pr = i;
        }
    }
    cout << mxm << "\n";
    while(pr != -1){
        ans.push_back(v[pr].second);
        pr = par[pr];
    }
    reverse(ans.begin(), ans.end());
    for(ll x : ans){
        cout << x << " ";
    }
    cout << "\n";

    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}