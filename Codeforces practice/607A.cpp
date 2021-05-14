/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, bool> beacons;
map<ll, ll> strength;
ll prefix[1000007] = {0}, ctr[1000007] = {0};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >> n;
    ll a[n], b[n];
    ll mxm = 0, mnm = INT_MAX;
    for(ll i=0;i<n;i++){
        cin >> a[i] >> b[i];
        beacons[a[i]] = true;
        strength[a[i]] = b[i];
        ctr[a[i]] = 1;
        mxm = max(mxm, a[i]);
        mnm = min(mnm, a[i]);
    }
    ll ans = n;
    ll good = n, expl = 0;
    for(ll i=1;i<=mxm;i++){
        ctr[i] += ctr[i-1];
    }
    ll maxStr = 0, maxIdx = -1;
    for(ll i=0;i<=1000000;i++){
        if(beacons[i]){
            // if(i - strength[i] - 1 >= 0 && i - 1 >= 0){
                // prefix[i] = ctr[i-1] - ctr[i - 1 - strength[i]];
                // prefix[i] = prefix[max(0LL, i-1-strength[i])] + 1;
            // }
            if(i - 1 - strength[i] < 0){
                prefix[i] = 1;
            }
            else{
                prefix[i] = prefix[i-1-strength[i]] + 1;
            }
            if(maxStr < prefix[i]){
                maxStr = prefix[i];
                maxIdx = i;
            }
        }
        else{
            prefix[i] = prefix[i-1];
        }
    }
    // for(ll i=mnm; i<=mxm; i++){
    //     cout << prefix[i] << " ";
    // }
    // cout << "\n";
    // cout << maxStr << " " << maxIdx << "\n";
    // ll ans1 = 0;
    cout << n - maxStr << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}