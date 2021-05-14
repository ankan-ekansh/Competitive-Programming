/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll>> a, b;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    a.resize(n+1, vector<ll>(m+1, 0));
    b.resize(n+1, vector<ll>(m+1, 0));
    for(ll i=0;i<n;i++){
        string s;
        cin >> s;
        for(ll j=0;j<m;j++){
            a[i][j] = s[j] - '0';
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(j == 0){
                b[i][j] = a[i][j];
                continue;
            }
            // b[i][j] = b[i][j+1] + a[i][j];
            if(a[i][j] == 1){
                b[i][j] = b[i][j-1] + a[i][j];
            }
        }
    }
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<m;j++){
    //         cout << b[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    ll ans = 0;
    for(ll j=0;j<m;j++){
        vector<ll> tmp(n);
        for(ll i=0;i<n;i++){
            tmp[i] = b[i][j];
        }
        sort(tmp.begin(), tmp.end(), greater<ll>());
        // sort(tmp.begin(), tmp.end());
        for(ll i=0;i<n;i++){
            ans = max(ans, (i+1)*(tmp[i]));
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}