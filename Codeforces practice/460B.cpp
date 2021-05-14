/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sod(ll x){
    ll s = 0;
    while(x){
        s += x%10;
        x/=10;
    }
    return s;
}
ll power(ll a, ll b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a;
    }
    else{
        ll x = power(a, b/2);
        if(b % 2 == 0){
            return x*x;
        }
        else{
            return x*a*x;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> ans;
    for(ll s=1;s<=81;s++){
        ll x = b*power(s, a) + c;
        if(sod(x) == s && x < 1000000000){
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << x << " ";
    }
    // cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}