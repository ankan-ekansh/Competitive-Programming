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
    ll tc = 1;
    while(t--){
        
        cout << "Case #" << tc++ << ": ";
        ll x, y;
        string s;
        cin >> x >> y;
        cin >> s;
        ll n = s.length();
        ll cost = 0;
        for(ll i=1;i<n;i++) {
            string tmps = s.substr(i-1, 2);
            if(tmps == "CJ") {
                cost += x;
            }
            else if(tmps == "JC") {
                cost += y;
            }
        }
        for(ll i=0;i<n;i++) {
            string tmps = "";
            if(i > 0 && s[i] == '?') {
                tmps = s[i-1];
            }
            while(s[i] == '?') {
                if(i+1 < n) {
                    i++;
                }
                else {
                    break;
                }
            }
            tmps.push_back(s[i]);
            if(tmps == "CJ") {
                cost += x;
            }
            else if(tmps == "JC") {
                cost += y;
            }
        }
        cout << cost << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}