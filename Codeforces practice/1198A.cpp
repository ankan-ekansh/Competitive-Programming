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
    
    ll n, I;
    cin >> n >> I;
    ll a[n];
    map<ll, ll> mp;
    vector<ll> v;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(!mp[a[i]]){
            v.emplace_back(a[i]);
        }
        mp[a[i]]++;
    }
    sort(v.begin(), v.end());
    ll pref[v.size()+7] = {0}, suff[v.size()+7] = {0};
    ll disk = 8*I;
    ll k = disk / n;
    ll K = pow(2, k);
    for(ll i=0;i<v.size();i++){
        if(i == 0){
            pref[i+1] = mp[v[i]];
        }
        else{
            pref[i+1] = pref[i] + mp[v[i]];
        }
    }
    for(ll i=v.size()-1;i>=0;i--){
        if(i == v.size()-1){
            suff[i+1] = mp[v[i]];
        }
        else{
            suff[i+1] = suff[i+2] + mp[v[i]];
        }
    }
    ll mnm = INT_MAX;
    for(ll i=1;i+K<=v.size();i++){
        ll tmp = pref[i-1] + suff[i+K];
        mnm = min(mnm, tmp);
    }
    // cout << mnm << "\n";
    if(mnm == INT_MAX){
        cout << "0\n";
    }
    else{
        cout << mnm << "\n";
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}