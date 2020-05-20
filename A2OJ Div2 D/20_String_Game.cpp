/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
#define fi(i, n) for(ll i=0;i<n;i++)
using namespace std;
string t, p;
ll a[200007];
bool f(ll x){
    string tmp;
    // bool b[t.length()] = {true};
    bool b[t.length()];
    memset(b, true, sizeof(b));
    fi(i, x){
        // cout << "---\n";
        b[a[i]-1] = false;
    }
    // fi(i, t.length()){
        // cout << b[i] << " ";
    // }
    // cout << "\n";
    fi(i, t.length()){
        // cout << t[i] << " ";
        if(b[i]){
            tmp += t[i];
        }
    }
    // cout << "\n";
    // cout << tmp << "\n";
    ll matches = 0;
    ll i=0, j=0;
    for(i=0, j=0; i<tmp.length() && j < p.length();){
        if(tmp[i] == p[j]){
            i++;
            j++;
            matches++;
        }
        else{
            i++;
        }
    }
    if(matches == p.length()){
        return true;
    }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cin >> t >> p;
    cin >> t;
    cin >> p;
    fi(i, t.length()){
        cin >> a[i];
    }
    // cout << f(0);
    ll l=0, r = t.length();
    ll mid;
    ll ans = 0;
    while(l <= r){
        mid = l + (r-l)/2;
        // cout << "mid is " << mid << "\n";
        bool tmp = f(mid);
        if(tmp){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}