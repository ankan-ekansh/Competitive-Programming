#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(pair<ll, ll> p, pair<ll, ll> q){
    // return p.second > q.second;
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
        // for(ll i=30;i>=k;i--){
        //     for(ll j=i;j>=i-k;j--){

        //     }
        // }
        pair<ll, ll> p[32];
        ll b[32] = {0};
        for(ll i=0;i<n;i++){
            for(ll j=0;j<32;j++){
                if(a[i] & (1LL << j)){
                    // b[j] += 1;
                    ll x = p[j].second;
                    p[j] = {j, x+1};
                }
                else{
                    p[j] = {j, p[j].second};
                }
            }
        }
        pair<ll, ll> q[32];
        for(ll i=0;i<32;i++){
            q[i] = {i, (p[i].second) * (1LL << p[i].first)};
        }
        sort(q, q+32, comp);
        // ll ans = 0;
        // for(ll i=0;i<k;i++){
        //     ans += (1LL << q[i].first);
        // }
        // cout << ans << "\n";
        ll mxsum = 0, mnmans = 0;
        // for(ll i=0;i<32;i++){
        //     cout << q[i].first << " " << q[i].second << "\n";
        // }
        for(ll i=0;i<k;i++){
            mxsum += q[i].second;
            if(q[i].second)
                mnmans += (1LL << q[i].first);
        }
        // cout << mxsum << " " << mnmans << "\n";
        ll sum = 0, ans = INT_MAX;
        ll j = k, i = k;
        for(i=k;i<32-k;i++){
            ll tmpans = 0;
            while(j < i+k){
                sum += q[j].second;
                if(q[j].second)
                    tmpans += (1LL << q[j].first);
                j++;
            }
            if(sum == mxsum){
                mnmans = min(mnmans, tmpans);
            }
            sum -= q[i].second;
        }
        cout << mnmans << "\n";

        // ll ans = 0;
        // ll ctr = 0;
        // for(ll i=31;i>=0;i--){
        //     if(ctr == k){
        //         break;
        //     }
        //     if(b[i] == 1){
        //         ans = ans + (1LL << i);
        //         ctr++;
        //     }
        // }
        // cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}