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
        
        ll n, k;
        cin >> n >> k;
        vector<ll> a;
        set<ll> b;
        for(ll i=0;i<n;i++){
            ll x;
            cin >> x;
            a.push_back(x);
            b.insert(x);
        }
        // auto b = unique(a.begin(), a.end());
        // a.resize()
        if(b.size() > k){
            cout << "-1\n";
            continue;
        }
        vector<ll> ans;
        for(ll x : b){
            ans.push_back(x);
        }
        while(ans.size() < k){
            ans.push_back(1);
        }
        cout << n * ans.size() << "\n";
        for(ll i=0;i<n;i++){
            for(ll x : ans){
                cout << x << " ";
            }
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}