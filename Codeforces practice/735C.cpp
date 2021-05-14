/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
// ll ans[5000007];
vector<ll> v(101);
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    v[0] = 1;
    v[1] = 2;
    v[2] = 4;
    for(ll i=3;i<=89;i++){
        v[i] = v[i-1] + v[i-2] + 1;
        // if(v[i] < 0){
        //     cout << "Overflow at " << i << "\n";
        //     break;
        // }
    }
    // for(ll i=0;i<=10;i++){
        // cout << "i = " << i << " : " << v[i] << "\n";
    // }
    // cout << v[88] << "\n";
    ll n;
    cin >> n;
    auto it = lower_bound(v.begin(), v.end(), n);
    // cout << *it << " " << it - v.begin() << "\n";
    cout << it - v.begin() << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}