/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(pair<ll, ll> p, pair<ll, ll> q){
    if(p.second == q.second){
        return p.first < q.first;
    }
    return p.second > q.second;
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
    while(t--){
        
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        ll b[32] = {0};
        for(ll i=0;i<n;i++){
            for(ll j=0;j<32;j++){
                if(a[i] & (1LL << j)){
                    b[j] += 1;
                }
            }
        }
        vector<pair<ll, ll>> v;
        for(ll i=0;i<32;i++){
            v.push_back({(1LL << i), b[i] * (1LL << i)});
        }
        sort(v.begin(), v.end(), comp);
        ll ans = 0;
        for(ll i=0;i<k;i++){
            ans += v[i].first;
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}