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
    
    ll n;
    cin >> n;
    ll a[n];
    map<ll, ll> freq;
    for(ll i=0;i<n;i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    vector<ll> ones;
    map<ll, pair<ll, ll>> twos;
    string ans(n, 'B');
    for(ll i=0;i<n;i++) {
        if(freq[a[i]] == 1) {
            ones.push_back(i);
        }
        if(freq[a[i]] == 2) {
            if(twos.find(a[i]) != twos.end()) {
                twos[a[i]].second = i;
            }
            else {
                twos[a[i]].first = i;
            }
        }
    }
    // cout << ones.size() << " " << twos.size() << "\n";
    if(ones.size() % 2 != 0) {
        // cout << "NO\n";
        if(n - ones.size() - 2*twos.size() == 0) {
            cout << "NO\n";
        }
        else {
            ll x = 1;
            for(ll i=0;i<=ones.size()/2;i++) {
                ans[ones[i]] = (char)('A' + x);
                // x = 1-x;
            }
            x = 0;
            // cout << ans << "\n";
            for(ll i=ones.size()/2 + 1;i<ones.size();i++) {
                ans[ones[i]] = (char)('A' + x);
            }
            // cout << ans << "\n";
            for(ll i=0;i<n;i++) {
                if(freq[a[i]] > 2) {
                    ans[i] = 'A';
                    break;
                }
            }
            cout << "YES\n";
            cout << ans << "\n";
        }
    }
    else {
        ll x = 0;
        for(ll i=0;i<ones.size();i++) {
            ans[ones[i]] = (char)('A' + x);
            x = 1-x;
        }
        // x = 0;
        // for(auto it = twos.begin(); it != twos.end(); it++) {
        //     pair<ll, pair<ll, ll>> p = *it;
        //     ll ta = p.second.first;
        //     ll tb = p.second.second;
        //     ans[ta] = 'A';
        //     ans[tb] = 'B';
        // }
        cout << "YES\n";
        cout << ans << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}