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
    ll p[n+1] = {0}, q[n+1];
    for(ll i=1;i<n;i++){
        cin >> q[i];
    }
    ll idx = 1, mnm = 0x3f3f3f3f;
    for(ll i=1;i<=n;i++){
        if(i == 1){
            p[i] = 0;
        }
        else{
            p[i] = p[i-1] + q[i-1];
        }
        if(p[i] < mnm){
            idx = i;
            mnm = p[i];
        }
    }
    ll x = 1 - mnm;
    vector<ll> ans;
    set<ll> s;
    bool flag = true;
    for(ll i=1;i<=n;i++){
        // cout << p[i] + x << " ";
        if(p[i] + x >= 1 && p[i] + x <= n && !s.count(p[i] + x)){
            ans.push_back(p[i] + x);
            s.insert(p[i] + x);
        }
        else{
            flag = false;
            break;
        }
    }
    if(!flag){
        cout << "-1\n";
    }
    else{
        for(auto e : ans){
            cout << e << " ";
        }
        cout << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}