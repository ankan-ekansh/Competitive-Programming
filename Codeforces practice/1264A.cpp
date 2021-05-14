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
    while(t--){
        
        ll n;
        cin >> n;
        ll a[n];
        map<ll, ll> f;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            f[a[i]]++;
        }
        vector<pair<ll, ll>> v;
        ll sum = 0;
        for(ll i=0;i<n/2;i++){
            if(f[a[i]] + sum <= n/2 && f[a[i]]){
                v.push_back({a[i], f[a[i]]});
                sum += f[a[i]];
                f[a[i]] = 0;
            }
        }
        ll g, s, b;
        g = s = b = 0;
        // for(ll i=0;i<v.size();i++){
        //     cout << v[i].first << " " << v[i].second << "\n";
        // }
        if(v.size() < 3){
            cout << "0 0 0\n";
        }
        else{
            g = v[0].second;
            ll idx = 1;
            while(!(g < s) && idx < v.size()){
                s += v[idx].second;
                idx++;
                if(g < s){
                    break;
                }
            }
            for(ll i=idx;i<v.size();i++){
                b += v[i].second;
            }
            if(!(g < s && g < b && g + s + b <= n/2 && g > 0 && s > 0 && b > 0)){
                cout << "0 0 0\n";
            }
            else{
                cout << g << " " << s << " " << b << "\n";
            }
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}