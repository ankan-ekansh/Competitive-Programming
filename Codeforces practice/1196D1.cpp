/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string r, g, b;
string rgb = "RGB";
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x = 0;
    for(ll i=0;i<2000;i++) {
        r.push_back(rgb[x]);
        g.push_back(rgb[(x+1)%3]);
        b.push_back(rgb[(x+2)%3]);
        x = (x+1) % 3;
    }
    // cout << r << " " << g << " " << b << "\n";
    int t;
    cin>>t;
    while(t--){
        
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll c1 = 0, c2 = 0, c3 = 0;
        ll ans = INT_MAX;
        for(ll i=0;i<n && i+k-1<n;i++) {
            string sbs = s.substr(i, k);
            // cout << sbs << "\n";
            for(ll j=0;j<k;j++) {
                if(sbs[j] != r[j]) {
                    c1++;
                }
                if(sbs[j] != g[j]) {
                    c2++;
                }
                if(sbs[j] != b[j]) {
                    c3++;
                }
            }
            ans = min({ans, c1, c2, c3});
            c1 = c2 = c3 = 0;
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}